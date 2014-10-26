/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/26 02:52:37 by ocosquer          #+#    #+#             */
/*   Updated: 2014/10/26 12:36:54 by olivier          ###   ########.fr       */
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
	int		has_cmd;
	char	*cmd;

	pos = 0;
	has_cmd  =0;
	while (str[pos] && str[pos] != ':')
	{
		pos++;
		if (str[pos] == ':')
			has_cmd = 1;
	}
	if (has_cmd)
		cmd = ft_strsub(str, 0, pos);
	else
		cmd = ft_strdup(str);
	return (cmd);
}

char		*ft_get_command_data(char *str)
{
	int		pos;
	int		len;
	char	*data;
	int		has_data;

	pos = 0;
	len = ft_strlen(str);
	data = NULL;
	has_data = 0;
	while (str[pos] && str[pos] != ':')
	{
		pos++;
		if (str[pos] == ':')
			has_data = 1;
	}
	if (has_data)
		data = ft_strsub(str, pos + 1, len - pos - 1);
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
	char		*response;

	has_quit = 0;
	cmd = ft_get_command(str);
	response = NULL;
	if (cmd)
	{
		//ft_log_command(cmd, client);
		ft_putstr("cmd:");
		ft_putstr(cmd->cmd);
		ft_putstr("\n");
		if (ft_strcmp(cmd->cmd, "ls") == 0)
		{
			response = ft_command_ls(client->path);
			ft_putstr(response);
			ft_putstr("\n");
		}
		if (ft_strcmp(cmd->cmd, "quit") == 0)
			has_quit = 1;
		/*if (response)
			ft_send_response(response);*/
		(void)response;
	}
	(void)client;
	return (has_quit);
}
