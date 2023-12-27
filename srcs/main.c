
#include "ping.h"

int g_ping_data = TRUE;
int socket_fd = -1;

void	tmp_handler(int sig, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	if (sig == SIGINT)
	{
		ft_putchar_fd('\n', 1);
		g_ping_data = FALSE;
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
	struct sockaddr_in  target;
	t_ppckt             icmp_hdr;
	char                packet[PING_PKT_S];
	int                 nb_packets = 0;
	int                 count;
	int                 i;
	int                 ttl_val = 64;
	char                buffer[ADDR_LEN];
	struct timeval      timeout;

	signal_handling();
	ft_bzero(&target, sizeof(target));
	ft_bzero(buffer, ADDR_LEN);
	check_args(ac, av, &count, buffer);
	if (is_valid_ip(buffer, &target) != 1)
		error("Name or service not known", -1, TRUE);

	socket_fd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
	if (socket_fd == -1)
		error("socket() failed", errno, TRUE);

	timeout.tv_sec = RECV_TIMEOUT;
	timeout.tv_usec = 0;
	if (setsockopt(socket_fd, SOL_SOCKET, SO_RCVTIMEO, (const char *)&timeout, sizeof(timeout)) == -1)
		error("setsockopt() failed", errno, TRUE);
	if (setsockopt(socket_fd, SOL_IP, IP_TTL, &ttl_val, sizeof(ttl_val)) != 0)
		error("setsockopt() failed", errno, TRUE);

	ft_memset(&icmp_hdr, 0, sizeof(icmp_hdr));
	icmp_hdr.hdr.type = ICMP_ECHO;
	icmp_hdr.hdr.un.echo.id = htons(getpid());
	icmp_hdr.hdr.code = 0;
	for (i = 0; i < (int)sizeof(icmp_hdr.msg) - 1; i++)
		icmp_hdr.msg[i] = i + '0';
	icmp_hdr.msg[i] = '\0';
	icmp_hdr.hdr.checksum  = htons(calculate_checksum((unsigned short *)&icmp_hdr, sizeof(icmp_hdr)));

	while (count == -1 ? g_ping_data : count--)
	{
		if (sendto(socket_fd, &icmp_hdr, sizeof(icmp_hdr), 0, (struct sockaddr *)&target, sizeof(target)) <= 0)
		{
			perror("sendto");
			close(socket_fd);
			return (1);
		}
		if (recv(socket_fd, packet, sizeof(packet), 0) <= 0) {
			perror("recv");
			close(socket_fd);
			return (1);
		}
		nb_packets++;
		printf("SIZE bytes from BUFFER: icmp_seq=TBD ttl=TBD time=TBD ms\n");
		sleep(PING_SLEEP_RATE);
	}
	ft_printf("--- %s ping statistics ---\n", buffer);
	ft_printf("%d packets transmitted, %d received, %d%% packet loss\n", nb_packets, nb_packets, 0);
	return (0);
}
