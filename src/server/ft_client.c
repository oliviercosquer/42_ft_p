/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocosquer <ocosquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/26 02:52:37 by ocosquer          #+#    #+#             */
/*   Updated: 2014/10/26 02:47:00 by ocosquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_p_server.h>

t_client	*ft_new_client(int sock)
{
	t_client	*client;

	client = (t_client *)malloc(sizeof(t_client));
	if (client && sock)
	{
		ft_putstr("ACCEPT START\n");
		client->sock = accept(sock,
						(struct sockaddr *)&client->sin,
						&client->len);
		client->path = NULL;
		ft_putstr("ACCEPT STOP\n");
	}
	return (client);
}

void		ft_handle_client(t_client *client)
{
	int		ret;
	char	buffer[BUFF_SIZE];
	int		has_quit;

	has_quit = 0;
	while ((ret = read(client->sock, buffer, BUFF_SIZE)) > 0 && has_quit == 0)
	{
		buffer[BUFF_SIZE] = '\0';
		ft_put_msg("Received data from client", MSG_STD);
		has_quit = ft_handle_command(buffer, client);
	}
	close(client->sock);
}
