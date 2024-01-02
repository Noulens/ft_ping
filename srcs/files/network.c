#include "ping.h"

char    **hostnameResolution(const char *hostname)
{
	struct addrinfo hints;
	struct addrinfo *res;
	struct addrinfo *r;
	int status;
	char buffer[INET_ADDRSTRLEN];
	char from[NI_MAXHOST];
	char **ret = NULL;

	ft_memset(&hints, 0, sizeof(hints));
	ft_memset(buffer, 0, INET_ADDRSTRLEN);
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	status = getaddrinfo(hostname, 0, &hints, &res);
	if (status != 0)
	{
		// fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
		return (NULL);
	}
	r = res;
	while (r != NULL)
	{
		if (r->ai_family == AF_INET)
		{
			struct sockaddr_in *ipv4 = (struct sockaddr_in *)r->ai_addr;
			if (!inet_ntop(r->ai_family, &(ipv4->sin_addr), buffer, sizeof buffer))
				return (fprintf(stderr, "inet_ntop() failed: %s", strerror(errno)), NULL);
			// Find FQDN from result of inet_ntop()
			status = getnameinfo((struct sockaddr *)(ipv4), sizeof(struct sockaddr_in), from, NI_MAXHOST, NULL, 0, 0);
			if (status != 0)
			{
				// fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
				return (NULL);
			}
			break ;
		}
		r = r->ai_next;
	}
	if (!r)
		fprintf(stderr, "No AF_INET family found in ai LL\n");
	freeaddrinfo(res);
	ret = (char **)malloc(sizeof(char *) * 3);
	if (!ret)
		error("hostname resolution", errno, TRUE);
	ret[0] = ft_strdup(buffer);
	if (!ret[0])
		error("hostname resolution", errno, TRUE);
	ret[1] = ft_strdup(from);
	if (!ret[1])
		error("hostname resolution", errno, TRUE);
	ret[2] = NULL;
	return (ret);
}

int is_valid_ip(char *ip, struct sockaddr_in *data)
{
	char    **source = NULL;

	source = (char **)malloc(sizeof(char *) * 3);
	if (!source)
		error("is_valid_ip", errno, TRUE);
	ft_bzero(source, 3);
	for (int i = 0; ip[i]; i++)
	{
		if (ft_isalpha(ip[i]))
		{
			free(source);
			source = hostnameResolution(ip);
			if (!source)
				return (0);
			break ;
		}
		if (ip[i + 1] == '\0')
		{
			source[0] = ft_strdup(ip);
			if (!source[0])
				error("is_valid_ip", errno, TRUE);
		}
	}
	if (BONUS == TRUE && ft_strnstr(source[0], ".", ft_strlen(source[0])) == NULL)
	{
		char    *test = ft_itoa(ft_atoi(source[0]));
		if (!ft_strcmp(test, source[0]))
		{
			data->sin_family = AF_INET;
			data->sin_addr.s_addr = htonl((uint32_t)ft_atoi(source[0]));
			free(test);
		}
		else
			return (ft_free_split(source), free(test), 0);
	}
	else
	{
		if (inet_pton(AF_INET, source[0], &data->sin_addr) != 1)
			return (ft_free_split(source), 0);
	}
	// 56 bytes for msg + 8 bytes of icmp hdr + 20 bytes for iphdr = 84 bytes
	printf("PING %s (%s): 56 data bytes\n", ip, source[0]);
	ft_free_split(source);
	data->sin_family = AF_INET;
	return (1);
}

void    prepare_packet(t_ppckt *icmp_hdr, int *nb_packets)
{
	int i;
	ft_memset(icmp_hdr, 0, sizeof(*icmp_hdr));
	(*icmp_hdr).hdr.type = ICMP_ECHO;
	(*icmp_hdr).hdr.un.echo.id = htons(getpid());
	(*icmp_hdr).hdr.code = 0;
	for (i = 0; i < (int)sizeof((*icmp_hdr).msg) - 1; i++)
		(*icmp_hdr).msg[i] = 'A';
	(*icmp_hdr).msg[i] = '\0';
	(*icmp_hdr).hdr.un.echo.sequence = htons(++(*nb_packets));
	(*icmp_hdr).hdr.checksum  = calculate_checksum((uint16_t *) icmp_hdr, sizeof(*icmp_hdr));
}
