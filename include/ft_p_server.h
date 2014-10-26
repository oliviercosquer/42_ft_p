/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_server.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocosquer <ocosquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/26 02:52:25 by ocosquer          #+#    #+#             */
/*   Updated: 2014/10/26 03:00:18 by ocosquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_P_SERVER_H
# define FT_P_SERVER_H
# define MAX_CONNECTION 64
# define PROMPT_PREFIX "Server"
# include <ft_p.h>

typedef struct	s_client
{
	int					sock;
	unsigned int		len;
	struct sockaddr_in	sin;
	char				*path;
}				t_client;
typedef struct	s_command
{
	char	*cmd;
	char	*data;
}				t_command;
//ft_prompt
void			ft_put_prompt(void);
void			ft_put_msg(char *str, int msg_type);
void			ft_usage(char *str);

//ft_check_arg
int				ft_port_is_valid(char *port);

//ft_init
int				ft_init_server(int port);

//ft_client
t_client		*ft_new_client(int sock);
void			ft_handle_client(t_client *client);

//ft_commands
t_command		*ft_get_command(char *str);
char			*ft_get_command_string(char *str);
char			*ft_get_command_data(char *str);
void			ft_del_command(t_command **command);
int				ft_handle_command(char *str, t_client *client);
#endif
