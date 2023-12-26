#include "ping.h"

char    *hostnameResolution(const char *hostname)
{
	struct addrinfo hints;
	struct addrinfo *res;
	struct addrinfo *r;
	int status;
	char buffer[INET_ADDRSTRLEN];
	char *ret;

	ft_memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM; // TCP
	status = getaddrinfo(hostname, 0, &hints, &res);
	if (status != 0)
	{
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
		return (NULL);
	}
	r = res;
	while (r != NULL)
	{
		if (r->ai_family == AF_INET)
		{
			struct sockaddr_in *ipv4 = (struct sockaddr_in *)r->ai_addr;
			if (!inet_ntop(r->ai_family, &(ipv4->sin_addr), buffer, sizeof buffer))
				error("inet_ntop", errno, FALSE);
		}
		r = r->ai_next;
	}
	freeaddrinfo(res);
	ret = ft_strdup(buffer);
	return (ret);
}

int is_valid_ip(char *ip, t_data *data)
{
	char    *source = ip;

	for (int i = 0; ip[i]; i++)
	{
		if (ft_isalpha(ip[i]))
		{
			source = hostnameResolution(ip);
			if (!source)
				return (0);
			break ;
		}
		if (ip[i + 1] == '\0')
			source = ft_strdup(ip);
	}
	if (ft_strnstr(source, ".", ft_strlen(source)) == NULL)
	{
		char    *test = ft_itoa(ft_atoi(source));
		if (!ft_strcmp(test, source))
		{
			data->source.sin_family = AF_INET;
			data->source.sin_addr.s_addr = htonl((uint32_t)ft_atoi(source));
			free(test);
		}
		else
			return (free(test), 0);
	}
	else
	{
		if (inet_pton(AF_INET, source, &data->source.sin_addr) != 1)
			return (free(source), 0);
	}
	free(source);
	data->source.sin_family = AF_INET;
	return (1);
}