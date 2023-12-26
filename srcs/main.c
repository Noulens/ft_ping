
#include "ping.h"

int g_ping_data = -1;

void	tmp_handler(int sig, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	if (sig == SIGINT)
	{
		if (g_ping_data > -1 && close(g_ping_data) == -1)
			error("error: close() failed: ", errno, TRUE);
		fprintf(stdout, YELLOW"\nSIGINT received\n"RESET);
		exit(128 + SIGINT);
	}
}

void	signal_handling()
{
	struct sigaction	sa = {};

	sa.sa_flags = SA_RESTART;
	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = tmp_handler;
	sigaction(SIGINT, &sa, NULL);
}

int main(int ac, char **av)
{
	t_data  target = {0};

	if (ac == 1)
		error("usage error: Destination address required", -1, TRUE);
	signal_handling();
	if (is_valid_ip(av[1], &target) != 1)
		error("Name or service not known", -1, TRUE);
	return (0);
}