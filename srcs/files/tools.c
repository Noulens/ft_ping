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

static unsigned long	multiply_bitewise(long a, long b)
{
	unsigned long	result;

	result = 0;
	while (b > 0)
	{
		if ((b & 1) == 1)
			result += a;
		b >>= 1;
		a <<= 1;
	}
	return (result);
}

time_t	gettimeinms(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == 1)
		return (write(2, "Error in getting start time\n", 27), 1);
	return (multiply_bitewise(tv.tv_sec, M) + (tv.tv_usec / M));
}
