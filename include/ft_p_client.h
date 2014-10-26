/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_client.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/26 02:52:25 by ocosquer          #+#    #+#             */
/*   Updated: 2014/10/26 08:39:02 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_P_CLIENT_H
# define FT_P_CLIENT_H
# define MAX_CONNECTION 64
# define PROMPT_PREFIX "Client@"
# define PROMPT_SUFFIX ">>"
# include <ft_p.h>

typedef struct	s_client
{
	int					sock;
	unsigned int		len;
	struct sockaddr_in	sin;
	char				*address;
}				t_client;
#endif
