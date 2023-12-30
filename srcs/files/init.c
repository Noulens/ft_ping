//
// Created by tnoulens on 12/26/23.
//

#include "ping.h"

void    check_args(int ac, char **av, int *count, char *ttl, char *buffer)
{
	size_t  len = 0;

	*count = -1;
	++av;
	if (ac == 1)
	{
		error("usage error: Destination address required", -1, TRUE);
		return ;
	}
	len = ft_ptrlen((const char **)av);
	while (len--)
	{
		if (**av == '-')
		{
			++*av;
			while (**av)
			{
				switch (**av)
				{
					case 'c':
						++*av;
						if (**av == '\0')
						{
							++av;
							--len;
						}
						*count = ft_atoi(*av);
						if (*count < 1)
							error("bad number of packets to transmit.", -1, TRUE);
						while (*(*av + 1))
							++*av;
						break;
					case 'v':
						g_ping_flag |= VERBOSE;
						break ;
					case 'q':
						g_ping_flag |= QUIET;
						break ;
					case '-':
						++*av;
						if (!ft_strncmp("ttl", *av, 3))
						{
							*av += 3;
							if (**av == '\0')
							{
								++av;
								--len;
							}
							int res = ft_atoi(*av);
							if (res > 255)
							{
								fprintf(stderr, RED"option value too big: %d\n"RESET, res);
								exit(1);
							}
							if (res <= 0)
							{
								fprintf(stderr, RED"option value too small: %d\n"RESET, res);
								exit(1);
							}
							*ttl = (char)res;
							while (*(*av + 1))
								++*av;
							break;
						}
						else
						{
							fprintf(stderr, RED"invalid option\n"RESET);
							exit(1);
						}
					default:
						fprintf(stderr, RED"invalid option -- \'%c\'\n"RESET, **av);
						exit(1);
				}
				++*av;
			}
		}
		else
		{
			size_t addr_len = ft_strlen(*av);
			ft_memcpy(buffer, *av, addr_len > ADDR_LEN ? ADDR_LEN : addr_len);
		}
		++av;
	}
}
