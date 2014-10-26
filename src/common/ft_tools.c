/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/26 12:00:02 by olivier           #+#    #+#             */
/*   Updated: 2014/10/26 12:15:22 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_p.h>

char	*ft_strjoin_free(char **s1, char *s2)
{
	char	*str;

	str = NULL;
	str = ft_strjoin(*s1, s2);
	ft_strdel(s1);
	return (str);
}

int		ft_wait(int pid, int options)
{
	int				status;
	struct rusage	usage;

	wait4(pid, &status, options, &usage);
	return (status);
}