//
// Created by tnoulens on 12/26/23.
//

#include "ping.h"

void    check_args(int ac, char **av, t_data *target)
{
	size_t  len = 0;

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
						target->count = ft_atoi(*av);
						if (target->count < 1)
							error("bad number of packets to transmit.", -1, TRUE);
						break;
					default:
						ft_fprintf(2, RED"invalid option -- \'%c\'\n"RESET, **av);
						exit(1);
				}
				++*av;
			}
		}
		else if (is_valid_ip(*av, target) != 1)
			error("Name or service not known", -1, TRUE);
		++av;
	}
}
