
#include "ping.h"

int g_ping_flag = GO;

void	tmp_handler(int sig, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	if (sig == SIGINT)
	{
		g_ping_flag &= ~GO;
		ft_putchar_fd('\n', 1);
	}
}

void	signal_handling()
{
	struct sigaction    sa = {};

	sa.sa_flags = SA_RESTART;
	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = tmp_handler;
	sigaction(SIGINT, &sa, NULL);
}

int main(int ac, char **av)
{
	struct iphdr        *ipHdr = NULL;
	struct icmphdr      *r_icmp_hdr = NULL;
	struct sockaddr_in  target, r_addr;
	struct timeval      timeout;
	socklen_t           r_addr_len;
	size_t              r_size;
	time_t              avg = 0, min = LONG_MAX, max = 0;
	t_ppckt             icmp_hdr;
	int                 socket_fd = -1, nb_packets = 0, nb_r_packets = 0, count, i, ttl_val = 64, must_do;
	char                packet[128];
	char                buffer[ADDR_LEN];
	char                from[NI_MAXHOST];
	char                *r_buffer = NULL;

	signal_handling();
	ft_bzero(&target, sizeof(target));
	ft_bzero(buffer, ADDR_LEN);
	check_args(ac, av, &count, buffer);

	// Socket stuff
	socket_fd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
	if (socket_fd == -1)
		error("socket() failed", errno, TRUE);
	else if (g_ping_flag & VERBOSE)
		printf("ft_ping: sock4.fd: %d (socktype: SOCK_RAW), ", socket_fd);

	// DNS search
	if (is_valid_ip(buffer, &target) != 1)
	{
		if (close(socket_fd) == -1)
			error("close()", errno, TRUE);
		error("Name or service not known", -1, TRUE);
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
	time_t  start = gettimeinms();
	while (count == -1 ? (g_ping_flag & GO) : (g_ping_flag & GO) && count--)
	{
		// This must_do is to indicate whether we have to wait a reply or not
		must_do = 0;
		// Prepare ICMP packet
		ft_memset(&icmp_hdr, 0, sizeof(icmp_hdr));
		icmp_hdr.hdr.type = ICMP_ECHO;
		icmp_hdr.hdr.un.echo.id = htons(getpid());
		icmp_hdr.hdr.code = 0;
		for (i = 0; i < (int)sizeof(icmp_hdr.msg) - 1; i++)
			icmp_hdr.msg[i] = 'A';
		icmp_hdr.msg[i] = '\0';
		icmp_hdr.hdr.un.echo.sequence = htons(++nb_packets);
		icmp_hdr.hdr.checksum  = calculate_checksum((uint16_t *)&icmp_hdr, sizeof(icmp_hdr));

		// Send it and time it
		must_do = sendto(socket_fd, &icmp_hdr, sizeof(icmp_hdr), 0, (struct sockaddr *)&target, sizeof(target));
		if (must_do <= 0)
			fprintf(stderr, "sendto() failed: %s\n", strerror(errno));
		time_t  start_count = gettimeinms();

		// Receive it if necessary
		r_addr_len = sizeof(r_addr);
		if (must_do > 0)
		{
			must_do = recvfrom(socket_fd, packet, sizeof(packet), 0, (struct sockaddr *)&r_addr, &r_addr_len);
			if (must_do <= 0)
				fprintf(stderr, "packet lost: %s\n", strerror(errno));
			else
				nb_r_packets++;
		}
		time_t  end_count = gettimeinms() - start_count;

		// Do stats if necessary
		if (must_do > 0)
		{
			if (end_count < min)
				min = end_count;
			if (end_count > max)
				max = end_count;
			avg += end_count;
			// Get data from replies
			ipHdr = (struct iphdr *) packet;
			r_icmp_hdr = (struct icmphdr *) (packet + sizeof(struct iphdr));
			r_buffer = (char *) (packet + sizeof(struct iphdr) + sizeof(struct icmphdr));
			getnameinfo((struct sockaddr *) &r_addr, r_addr_len, from, NI_MAXHOST, NULL, 0, 0);
			r_size = sizeof(struct icmphdr) + ft_strlen(r_buffer) + 1;
			if (!(g_ping_flag & QUIET))
				printf("%zu bytes from %s (%s): icmp_seq=%d ttl=%d time=%ld ms\n", r_size, from,
				       inet_ntoa(r_addr.sin_addr), ntohs(r_icmp_hdr->un.echo.sequence), ipHdr->ttl, end_count);
			// print_reply(r_icmp_hdr, r_buffer);
		}
		sleep(PING_SLEEP_RATE);
	}
	// End timer and print conclusions
	time_t  end = gettimeinms() - start;
	printf("--- %s ping statistics ---\n", buffer);
	printf("%d packets transmitted, %d received, %0.1f%% packet loss, time %ldms\n", nb_packets, nb_r_packets, (((float)nb_packets - (float)nb_r_packets) * 100.0) / (float)nb_packets, end);
	printf("rtt min/avg/max = %ld/%ld/%ld ms\n", min, avg / nb_packets, max);
	if (close(socket_fd) == -1)
		return (fprintf(stderr, "close() failed: %s", strerror(errno)), EXIT_FAILURE);
	return (0);
}
