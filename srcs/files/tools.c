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
