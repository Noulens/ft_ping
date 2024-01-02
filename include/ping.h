
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
# include <netinet/ip.h>
# include <sys/ioctl.h>
# include <sys/time.h>
# include <linux/icmp.h>

// RFC 792 for a description of the ICMP protocol.
// https://tools.ietf.org/html/rfc792
# define PING_PKT_S 64
# define PING_USLEEP_RATE 1000000
# define RECV_TIMEOUT 1
# define ADDR_LEN 1024
# define M 1000

extern int  g_ping_flag;

typedef enum e_opt
{
	GO = 0b00000001,
	VERBOSE = 0b00000010,
	QUIET = 0b00000100,
}   t_opt;

typedef struct s_ping_packet
{
	struct icmphdr  hdr;
	char            msg[PING_PKT_S - sizeof(struct icmphdr)];
}   t_ppckt;

void            error(const char *msg, int error_code, int must_exit);
int             is_valid_ip(char *ip, struct sockaddr_in *data);
void            check_args(int ac, char **av, int *count, char *tll, char *buffer);
void            prepare_packet(t_ppckt *icmp_hdr, int *nb_packets);
void            print_reply(const struct icmphdr *r_icmp_hdr, const char *r_buffer);
void            analyze_packet(const struct icmphdr *r_icmp_hdr, int *nb_r_packets, char *error_buffer);
unsigned short  calculate_checksum(unsigned short *buf, int len);
time_t          gettimeinms(void);

# endif /* !PING_H */
