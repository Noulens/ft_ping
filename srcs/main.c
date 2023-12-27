
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
	t_data  target;
	int     nb_packets = 0;

	ft_bzero(&target, sizeof(target));
	signal_handling();
	check_args(ac, av, &target);
	if (is_valid_ip(target.buffer, &target) != 1)
		error("Name or service not known", -1, TRUE);
	while (target.count == -1 ? g_ping_data : target.count--)
	{
		printf("SIZE bytes from BUFFER: icmp_seq=TBD ttl=TBD time=TBD ms\n");
		nb_packets++;
		sleep(1);
	}
	ft_printf("--- %s ping statistics ---\n", target.buffer);
	ft_printf("%d packets transmitted, %d received, %d%% packet loss\n", nb_packets, nb_packets, 0);
	return (0);
}
