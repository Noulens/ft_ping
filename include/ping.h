
#ifndef PING_H
# define PING_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/socket.h>
# include <sys/types.h>
# include <arpa/inet.h>
# include <net/if.h>
# include <netinet/in.h>
# include <netdb.h>
# include <ifaddrs.h>
# include <linux/if_ether.h>
# include <signal.h>
# include <errno.h>
# include "colors.h"
# include "libft.h"
# include <netpacket/packet.h>
# include <net/ethernet.h>
# include <netinet/if_ether.h>
# include <sys/ioctl.h>

extern int  g_ping_data;

typedef enum e_options
{
	C = 0b00001
}   t_opt;

typedef struct s_data
{
	struct sockaddr_in  source;
	int                 opt;
	size_t              count;
	char                buffer[INET_ADDRSTRLEN];
}   t_data;

void    error(const char *msg, int error_code, int must_exit);
int     is_valid_ip(char *ip, t_data *data);
void    check_args(int ac, char **av, t_data *target);

# endif /* !PING_H */
