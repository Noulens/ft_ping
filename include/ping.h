
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
# include <time.h>
# include <linux/icmp.h>

// RFC 792 for a description of the ICMP protocol.
// https://tools.ietf.org/html/rfc792
# define PING_PKT_S 64
# define PORT_NO 0
# define PING_SLEEP_RATE 1
# define RECV_TIMEOUT 2
# define BUFFER 1024

extern int  g_ping_data;

typedef enum e_options
{
	C = 0b00001
}   t_opt;

typedef struct s_ping_packet
{
	struct icmphdr  hdr;
	char            msg[PING_PKT_S - sizeof(struct icmphdr)];
}   t_ppckt;

typedef struct s_data
{
	struct sockaddr_in  source;
	int                 opt;
	int                 count;
	char                buffer[BUFFER];
}   t_data;

void            error(const char *msg, int error_code, int must_exit);
int             is_valid_ip(char *ip, t_data *data);
void            check_args(int ac, char **av, t_data *target);
unsigned short  calculate_checksum(unsigned short *buf, int len);

# endif /* !PING_H */
