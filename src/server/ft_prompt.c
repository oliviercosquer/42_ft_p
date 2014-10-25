#include <ft_p_server.h>

void	ft_usage(char *str)
{
	ft_putstr("Usage: ");
	ft_putstr(str);
	ft_putstr(" <port>\n");
}

void	ft_put_prompt(void)
{
	write(1, PROMPT_PREFIX, ft_strlen(PROMPT_PREFIX));
	write(1, ":", 1);
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