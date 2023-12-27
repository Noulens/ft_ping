
#include "ping.h"

int g_ping_data = TRUE;

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
	int                 nb_packets = 0;
	struct sockaddr_in  source;
	int                 count;
	char                buffer[ADDR_LEN];

	signal_handling();
	ft_bzero(&source, sizeof(source));
	ft_bzero(buffer, ADDR_LEN);
	check_args(ac, av, &count, buffer);
	if (is_valid_ip(buffer, &source) != 1)
		error("Name or service not known", -1, TRUE);
	// Socket stuff
	while (count == -1 ? g_ping_data : count--)
	{
		// Get packet ready
		// Send packet
		// Receive packet
		nb_packets++;
		printf("SIZE bytes from BUFFER: icmp_seq=TBD ttl=TBD time=TBD ms\n");
		sleep(1);
	}
	ft_printf("--- %s ping statistics ---\n", buffer);
	ft_printf("%d packets transmitted, %d received, %d%% packet loss\n", nb_packets, nb_packets, 0);
	return (0);
}
