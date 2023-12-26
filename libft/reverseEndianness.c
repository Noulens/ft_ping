/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverseEndianness.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 19:47:07 by tnoulens          #+#    #+#             */
/*   Updated: 2022/10/04 15:31:08 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * This function reverse the endianness of a data, it takes a pointer to the
 * data and the size of the data in bytes (eg: sizeof(uint16_t)...
 */

void    reverseEndianness(void *data, size_t size)
{
	uint8_t *bytes;
	uint8_t temp;
	size_t  nb;
	size_t  i;

	bytes = (uint8_t *)data;
	nb = size / 2;
	i = 0;
	while (i < nb)
	{
		temp = bytes[i];
		bytes[i] = bytes[size - 1 - i];
		bytes[size - 1 - i] = temp;
		i++;
	}
}

/*int main()
{
	uint64_t value64 = 0x123456789ABCDEF0ULL;

	printf("Original 64-bit value: 0x%016lX\n", value64);
	reverseEndianness(&value64, sizeof(value64));
	printf("Reversed 64-bit value: 0x%016lX\n", value64);
	return 0;
}*/
