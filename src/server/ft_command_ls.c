/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command_ls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/26 08:20:59 by olivier           #+#    #+#             */
/*   Updated: 2014/10/26 12:29:21 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_p_server.h>

char	*ft_command_ls(t_path *path)
{
	int		pid;
	int		fd;

	fd = open(FILE_BUFFER, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	pid = fork();
	if (pid == 0)
	{
		dup2(fd, 1);
		execl("/bin/ls", "", (char *)NULL);
		close(fd);
		exit(0);
	}
	ft_wait(pid, 0);
	close(fd);
	(void)path;
	return (ft_command_ls_read());
}

char	*ft_command_ls_read(void)
{
	char	*str;
	int		ret;
	char	buffer[BUFF_SIZE];
	int		fd;

	fd = open(FILE_BUFFER, O_RDONLY);
	str = NULL;
	while((ret = read(fd, buffer, BUFF_SIZE - 1)) > 0)
	{
		buffer[ret - 1] = '\0';
		if (str)
			str = ft_strjoin_free(&str, buffer);
		else
			str = ft_strdup(buffer);
	}
	close(fd);
	return (str);
}