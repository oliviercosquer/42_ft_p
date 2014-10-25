#ifndef FT_P_SERVER_H
# define FT_P_SERVER_H
# define MAX_CONNECTION 64
# define PROMPT_PREFIX "Server"
# include <ft_p.h>

//ft_prompt
void	ft_put_prompt(void);
void	ft_put_msg(char *str, int msg_type);
void	ft_usage(char *str);

//ft_check_arg
int		ft_port_is_valid(char *port);
#endif