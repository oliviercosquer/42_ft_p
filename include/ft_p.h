/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/26 02:52:25 by ocosquer          #+#    #+#             */
/*   Updated: 2014/10/26 12:16:07 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_P_H
# define FT_P_H
# define BUFF_SIZE 4096
# define ERROR_PREFIX "error"
# define SUCCESS_PREFIX "success"
# define STD_PREFIX "std"
# define MSG_ERROR 0
# define MSG_SUCCESS 1
# define MSG_STD 2
# include <unistd.h>
# include <libft.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <netdb.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <fcntl.h>
# include <sys/time.h>
# include <sys/resource.h>
# include <sys/wait.h>

char	*ft_strjoin_free(char **s1, char *s2);
int		ft_wait(int pid, int options);
#endif
