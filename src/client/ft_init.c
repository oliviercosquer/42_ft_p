/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/26 02:52:37 by ocosquer          #+#    #+#             */
/*   Updated: 2014/10/26 08:39:17 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_p_client.h>

int		ft_init_client(char *addr, int port)
{
	int					sock;
	struct protoent		*protocol;
	struct sockaddr_in	sin;
	int					bind_ret;

	protocol = getprotobyname("tcp");
	if (protocol)
	{
		sock = socket(AF_INET, SOCK_STREAM, protocol->p_proto);
		if (sock)
		{
			sin.sin_family = AF_INET;
			sin.sin_port = htons(port);
			sin.sin_addr.s_addr = inet_addr(addr);
			bind_ret = bind(sock, (const struct sockaddr *)&sin, sizeof(sin));
			if (bind_ret == 0)
			{
				listen(sock, MAX_CONNECTION);
				ft_put_msg("Starting started", MSG_STD);
			}
			else
			{
				ft_put_msg("Can't bind socket!", MSG_ERROR);
				return (-1);
			}
		}
	}
	else
	{
		ft_put_msg("Can't find protocol TCP!", MSG_ERROR);
		return (-1);
	}
	return (sock);
}
