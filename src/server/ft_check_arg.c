#include <ft_p_server.h>

int		ft_port_is_valid(char *str)
{
	int		port;

	port = ft_atoi(str);
	if (port > 0)
		return (1);
	return (0);
}