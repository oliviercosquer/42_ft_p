/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/26 08:34:34 by olivier           #+#    #+#             */
/*   Updated: 2014/10/26 08:39:23 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_p_client.h>

void	ft_usage(char *str)
{
	ft_putstr("Usage: ");
	ft_putstr(str);
	ft_putstr(" <address>\n");
	ft_putstr(" <port>\n");
}

void	ft_put_prompt(t_client *client)
{
	ft_putstr(PROMPT_PREFIX);
	ft_pustr(client->address);
	ft_putstr(PROMPT_SUFFIX);
}

void	ft_put_msg(char *str, int msg_type)
{
	if (msg_type == MSG_ERROR)
		ft_putstr(ERROR_PREFIX);
	else if (msg_type == MSG_SUCCESS)
		ft_putstr(SUCCESS_PREFIX);
	else if (msg_type == MSG_STD)
		ft_putstr(STD_PREFIX);
	ft_putstr(": ");
	ft_putstr(str);
	ft_putstr("\n");
}