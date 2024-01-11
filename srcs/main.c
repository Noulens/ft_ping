
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
	struct icmp_filter  filter;
	struct iphdr        *ipHdr = NULL;
	struct sockaddr_in  target, r_addr;
	struct timeval      timeout;
	socklen_t           r_addr_len;
	ssize_t             must_do;
	double              avg = 0, min = THE_MAX, max = 0;
	t_ppckt             icmp_hdr;
	int                 socket_fd = -1, nb_packets = 0, nb_r_packets = 0;
	int                 count, interval = PING_USLEEP_RATE, linger = RECV_TIMEOUT;
	char                ttl_val = 64;
	char                packet[1024];
	char                buffer[ADDR_LEN];
	char                error_buffer[255];
	char                from[NI_MAXHOST];

	signal(SIGINT, tmp_handler);
	ft_bzero(&target, sizeof(target));
	ft_bzero(buffer, ADDR_LEN);
	check_args(ac, av, &count, &ttl_val, &linger, &interval, buffer);
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
	timeout.tv_sec = linger;
	timeout.tv_usec = 0;
	if (setsockopt(socket_fd, SOL_SOCKET, SO_RCVTIMEO, (const char *)&timeout, sizeof(timeout)) == -1)
		return (close(socket_fd), ft_fprintf(2, "setsockopt() failed: %s", strerror(errno)), EXIT_FAILURE);
	// Set up ICMP filter to allow relevant ICMP messages
	icmp_filter_set_block_all(&filter);
	icmp_filter_set_pass(ICMP_ECHOREPLY, &filter);
	icmp_filter_set_pass(ICMP_TIME_EXCEEDED, &filter);
	icmp_filter_set_pass(ICMP_DEST_UNREACH, &filter);
	icmp_filter_set_pass(ICMP_REDIRECT, &filter);
	// Apply the ICMP filter
	if (setsockopt(socket_fd, SOL_RAW, ICMP_FILTER, &filter, sizeof(filter)) == -1)
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
		if (must_do <= 0)
			error("sending packet", errno, TRUE);
		double  start_count = gettimeinms();
		// Receive it if necessary
		r_addr_len = sizeof(r_addr);
		// Declare recvmsg variables
		struct iovec iov;
		struct msghdr msg;
		if (must_do > 0)
		{
			// Prepare msg
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
				ipHdr = (struct iphdr *)packet;
				r_icmp_hdr = (struct icmphdr *) (packet + sizeof(struct iphdr));
//				char *r_buffer;
//				r_buffer = (char *)(packet + sizeof(struct iphdr) + sizeof(struct icmphdr));
//				print_reply(r_icmp_hdr, r_buffer);
				analyze_packet(r_icmp_hdr, &nb_r_packets, error_buffer);
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
			if (!(r_icmp_hdr->type == ICMP_ECHOREPLY && r_icmp_hdr->code == 0
				&& !(r_icmp_hdr->checksum - calculate_checksum((uint16_t *) r_icmp_hdr, sizeof(*r_icmp_hdr)))))
			{
				getnameinfo((struct sockaddr *) &r_addr, r_addr_len, from, NI_MAXHOST, NULL, 0, 0);
				if (!(g_ping_flag & VERBOSE))
					printf("%zu bytes from %s (%s): %s\n", must_do - sizeof(struct iphdr), from,
							inet_ntoa(r_addr.sin_addr), error_buffer);
				else
					printf("%zu bytes from %s (%s): type: %d, code: %d: %s\n", must_do - sizeof(struct iphdr),
							from, inet_ntoa(r_addr.sin_addr), r_icmp_hdr->type, r_icmp_hdr->code, error_buffer);
			}
			else if (!(g_ping_flag & QUIET))
				printf("%zu bytes from %s: icmp_seq=%d ttl=%d time=%.3f ms\n", must_do - sizeof(struct iphdr),
						inet_ntoa(r_addr.sin_addr), ntohs(r_icmp_hdr->un.echo.sequence), ipHdr->ttl, (double)end_count);
		}
		usleep(interval * M);
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
