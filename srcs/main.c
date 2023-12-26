
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

	signal_handling();
	check_args(ac, av, &target);
	while (target.count--)
	{
		sleep(1);
	}
	return (0);
}
