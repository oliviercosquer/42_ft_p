/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocosquer <ocosquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/26 02:52:25 by ocosquer          #+#    #+#             */
/*   Updated: 2014/10/26 02:59:44 by ocosquer         ###   ########.fr       */
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

#endif
