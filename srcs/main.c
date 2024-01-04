
#include "ping.h"

int g_ping_flag = GO;

void	tmp_handler(int useless)
{
	(void)useless;
	g_ping_flag &= ~GO;
}

int main(int ac, char **av)
{
	struct icmphdr      *r_icmp_hdr = NULL;
	struct iphdr        *ipHdr = NULL;
	struct sockaddr_in  target, r_addr;
	struct timeval      timeout;
	socklen_t           r_addr_len;
	ssize_t             must_do;
	double              avg = 0, min = THE_MAX, max = 0;
	t_ppckt             icmp_hdr;
	int                 socket_fd = -1, nb_packets = 0, nb_r_packets = 0, count;
	char                ttl_val = 64;
	char                packet[1024];
	char                buffer[ADDR_LEN];
	char                error_buffer[255];
	char                from[NI_MAXHOST];

	signal(SIGINT, tmp_handler);
	ft_bzero(&target, sizeof(target));
	ft_bzero(buffer, ADDR_LEN);
	check_args(ac, av, &count, &ttl_val, buffer);
	// Socket stuff
	socket_fd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
	if (socket_fd == -1)
		error("socket() failed", errno, TRUE);
	// DNS search
	if (is_valid_ip(buffer, &target) != 1)
	{
		if (close(socket_fd) == -1)
			error("close()", errno, TRUE);
		error("unknown host", -1, TRUE);
	}
	// Set timeout on socket
	timeout.tv_sec = RECV_TIMEOUT;
	timeout.tv_usec = 0;
	if (setsockopt(socket_fd, SOL_SOCKET, SO_RCVTIMEO, (const char *)&timeout, sizeof(timeout)) == -1)
		return (close(socket_fd), ft_fprintf(2, "setsockopt() failed: %s", strerror(errno)), EXIT_FAILURE);
	// Set ttl value
	if (setsockopt(socket_fd, SOL_IP, IP_TTL, &ttl_val, sizeof(ttl_val)) != 0)
		return (close(socket_fd), ft_fprintf(2, "setsockopt() failed: %s", strerror(errno)), EXIT_FAILURE);
	// Start loop
//	time_t  start = gettimeinms();
	while (count == -1 ? (g_ping_flag & GO) : (g_ping_flag & GO) && count--)
	{
		// This must_do is to indicate whether we have to wait a reply or not
		must_do = 0;
		// Prepare ICMP packet
		prepare_packet(&icmp_hdr, &nb_packets);

		// Send it and time it
		must_do = sendto(socket_fd, &icmp_hdr, sizeof(icmp_hdr), 0, (struct sockaddr *)&target, sizeof(target));
//		if (must_do <= 0)
//			fprintf(stderr, "sendto() failed: %s\n", strerror(errno));
		double  start_count = gettimeinms();

		// Receive it if necessary
		r_addr_len = sizeof(r_addr);
		// Declare recvmsg variables
		struct iovec iov;
		struct msghdr msg;
		while (must_do > 0)
		{
			ft_bzero(packet, sizeof(packet));
			iov.iov_base = packet;
			iov.iov_len = sizeof(packet);
			msg.msg_name = (void *)&r_addr;
			msg.msg_namelen = r_addr_len;
			msg.msg_iov = &iov;
			msg.msg_iovlen = 1;
			msg.msg_flags = 0;
			msg.msg_control = NULL;
			msg.msg_controllen = 0;
			must_do = recvmsg(socket_fd, &msg, 0);
			if (must_do > 0)
			{
				// Get data from replies
				ipHdr = (struct iphdr *)packet;
				if (ipHdr->protocol == IPPROTO_ICMP)
				{
					r_icmp_hdr = (struct icmphdr *) (packet + sizeof(struct iphdr));
//					char                *r_buffer = NULL;
//					r_buffer = (char *) (packet + sizeof(struct iphdr) + sizeof(struct icmphdr));
//					print_reply(r_icmp_hdr, r_buffer);
					analyze_packet(r_icmp_hdr, &nb_r_packets, error_buffer);
					break ;
				}
				else
					continue;
			}
		}
		double  end_count = (gettimeinms() - start_count);
		// Do stats and print only if necessary
		if (must_do > 0)
		{
			if (end_count < min)
				min = end_count;
			if (end_count > max)
				max = end_count;
			avg += end_count;
			if (!(r_icmp_hdr->type == ICMP_ECHOREPLY && r_icmp_hdr->code == 0) && !(g_ping_flag & QUIET))
			{
				getnameinfo((struct sockaddr *) &r_addr, r_addr_len, from, NI_MAXHOST, NULL, 0, 0);
				printf("%zu bytes from %s (%s): %s\n", must_do - sizeof(struct iphdr), from, inet_ntoa(r_addr.sin_addr), error_buffer);
			}
			else if (!(g_ping_flag & QUIET))
				printf("%zu bytes from %s: icmp_seq=%d ttl=%d time=%.3f ms\n", must_do - sizeof(struct iphdr), \
				inet_ntoa(r_addr.sin_addr), ntohs(r_icmp_hdr->un.echo.sequence), ipHdr->ttl, (double)end_count);
		}
		usleep(PING_USLEEP_RATE);
	}
	// End global timer and print conclusions
//	time_t  end = gettimeinms() - start;
	printf("--- %s ping statistics ---\n", buffer);
	printf("%d packets transmitted, %d packets received, %0.1f%% packet loss\n", nb_packets, nb_r_packets, \
		(((float)nb_packets - (float)nb_r_packets) * 100.0) / (float)nb_packets);
	if (nb_r_packets)
		printf("round-trip min/avg/max = %.3f/%.3f/%.3f ms\n", min == THE_MAX ? 0 : (double)min, (double)avg / nb_packets, (double)max);
	else
		ft_putchar_fd('\n', 1);
	if (close(socket_fd) == -1)
		return (fprintf(stderr, "close() failed: %s", strerror(errno)), EXIT_FAILURE);
	return (0);
}
