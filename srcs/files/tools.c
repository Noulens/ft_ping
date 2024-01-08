//
// Created by tnoulens on 12/27/23.
//

#include "ping.h"

unsigned short calculate_checksum(unsigned short *buf, int len)
{
	unsigned long   sum = 0;
	unsigned short  *w = buf;
	unsigned short  answer = 0;

	while (len > 1)
	{
		sum += *w++;
		len -= 2;
	}
	if (len == 1)
	{
		*((unsigned char *)&answer) = *((unsigned char *)w);
		sum += answer;
	}
	sum = (sum >> 16) + (sum & 0xFFFF);
	sum += (sum >> 16);
	answer = ~sum;
	return (answer);
}

void    print_reply(const struct icmphdr *r_icmp_hdr, const char *r_buffer)
{
	printf(" info from ECHO REPLY:\n");
	printf(" type: %d\n", r_icmp_hdr->type);
	printf(" code: %d\n", r_icmp_hdr->code);
	printf(" id: %d\n", ntohs(r_icmp_hdr->un.echo.id));
	printf(" sequence: %d\n", ntohs(r_icmp_hdr->un.echo.sequence));
	printf(" data: %s\n", r_buffer);
}

double gettimeinms(void)
{
	struct timeval tv;

	if (gettimeofday(&tv, NULL) == -1)
	{
		fprintf(stderr, "Error in getting start time\n");
		return (-1);
	}
	return ((double)tv.tv_sec * 1000.0 + (double)tv.tv_usec / 1000.0);
}

// Function to set all bits in the filter
// Function to set all bits in the filter (block all)
void    icmp_filter_set_block_all(struct icmp_filter *filter)
{
	filter->data = ~0U;
}

// Function to clear a specific bit (type) in the filter (allow pass)
void    icmp_filter_set_pass(int type, struct icmp_filter *filter)
{
	if (type < 32)
		filter->data &= ~(1U << type);
}

void    print_help(void)
{
	printf("Usage: ping [OPTION...] HOST ...\n");
	printf("Send ICMP ECHO_REQUEST packets to network hosts.\n");
	printf("Options:\n");
	printf("-c=NUMBER                   stop after sending NUMBER packets\n");
	printf("-i=NUMBER                   wait NUMBER seconds between sending each packet\n");
	printf("     --ttl=N                specify N as time-to-live\n");
	printf("-v                          verbose output\n");
	printf("-W=N                        number of seconds to wait for response\n");
	printf("-q                          quiet output\n");
	printf("-?                          display this help\n");
}
