/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/26 02:52:36 by ocosquer          #+#    #+#             */
/*   Updated: 2014/10/26 08:18:32 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_p.h>
#include <ft_p_client.h>

#include <fcntl.h>
int		main(int argc, char **argv)
{
	int		pid;
	int		fd;

	(void)argc;
	(void)argv;
	pid = fork();
	if (pid == 0)
	{
		fd = open(".ft_p.tmp", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
		
		dup2(fd, 1);
		dup2(fd, 2);
		close(fd);
		execl("/bin/ls", "", (char *)NULL);
	}
	return (0);
}
