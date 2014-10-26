/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocosquer <ocosquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/26 02:52:37 by ocosquer          #+#    #+#             */
/*   Updated: 2014/10/26 02:51:51 by ocosquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_p_server.h>

t_command	*ft_get_command(char *str)
{
	t_command	*command;

	command = (t_command *)malloc(sizeof(t_command));
	if (command)
	{
		command->cmd = ft_get_command_string(str);
		command->data = ft_get_command_data(str);
	}
	return (command);
}

char		*ft_get_command_string(char *str)
{
	int		pos;
	char	*cmd;

	pos = 0;
	while (str[pos] && str[pos] != ':')
		pos++;
	cmd = ft_strsub(str, 0, pos);
	return (cmd);
}

char		*ft_get_command_data(char *str)
{
	int		pos;
	int		len;
	char	*data;

	pos = 0;
	len = ft_strlen(str);
	while (str[pos] && str[pos] != ':')
		pos++;
	data = ft_strsub(str, pos + 1, len - pos);
	return (data);
}

void		ft_del_command(t_command **command)
{
	t_command	*tmp;

	tmp = *command;
	ft_strdel(&tmp->cmd);
	ft_strdel(&tmp->data);
	free(tmp);
	*command = NULL;
}

int			ft_handle_command(char *str, t_client *client)
{
	int			has_quit;
	t_command	*cmd;

	has_quit = 0;
	cmd = ft_get_command(str);
	if (cmd)
	{
		ft_putstr("COMMANDE:");
		ft_putstr(cmd->cmd);
		ft_putstr("\n");
		ft_putstr("DATA:");
		ft_putstr(cmd->data);
		ft_putstr("\n");
		ft_del_command(&cmd);
	}
	(void)client;
	return (has_quit);
}
