/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocosquer <ocosquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/26 02:52:37 by ocosquer          #+#    #+#             */
/*   Updated: 2014/10/26 02:57:14 by ocosquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_p.h>
#include <ft_p_server.h>

int		main(int argc, char **argv)
{
	int			sock;
	t_client	*client;
	int			pid;

	if (argc == 2)
	{
		ft_put_msg("Starting server", MSG_STD);
		if (ft_port_is_valid(argv[1]))
			sock = ft_init_server(ft_atoi(argv[1]));
		if (sock)
		{
			while ((client = ft_new_client(sock)))
			{
				pid = fork();
				if (pid == 0)
					ft_handle_client(client);
			}
		}
		close(sock);
		ft_put_msg("Server stopped", MSG_STD);
	}
	else
		ft_usage(argv[0]);
	return (0);
}
