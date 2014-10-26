/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/26 02:52:37 by ocosquer          #+#    #+#             */
/*   Updated: 2014/10/26 12:36:27 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_p_server.h>

t_client	*ft_new_client(int sock)
{
	t_client	*client;

	client = (t_client *)malloc(sizeof(t_client));
	if (client && sock)
	{
		client->sock = accept(sock,
						(struct sockaddr *)&client->sin,
						&client->len);
		client->path = NULL;
	}
	return (client);
}

void		ft_handle_client(t_client *client)
{
	int		ret;
	char	buffer[BUFF_SIZE];
	int		has_quit;

	has_quit = 0;
	while (has_quit == 0 && (ret = read(client->sock, buffer, BUFF_SIZE - 1)) > 0)
	{
		buffer[ret - 1] = '\0';
		has_quit = ft_handle_command(buffer, client);
	}
	close(client->sock);
}
