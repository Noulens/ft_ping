#include "ping.h"

void    error(const char *msg, int error_code, int must_exit)
{
	if (error_code != -1)
	{
		fprintf(stderr, RED"ft_ping: %s: %s\n"RESET, msg, strerror(error_code));
	}
	else
		fprintf(stderr, RED"ft_ping: %s\n"RESET, msg);
	if (must_exit == TRUE)
	{
		if (g_socket_fd != -1 && close(g_socket_fd) != 0)
			fprintf(stderr, RED"close(): %s\n"RESET, strerror(errno));
		exit(EXIT_FAILURE);
	}
}
