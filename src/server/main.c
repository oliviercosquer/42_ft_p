#include <ft_p.h>
#include <ft_p_server.h>

int		main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	if (argc == 2)
	{
		if (ft_port_is_valid(argv[1]))
			ft_put_msg("Server started!", MSG_SUCCESS);
		else
			ft_put_msg("Invalid port specified!", MSG_ERROR);
	}
	else
		ft_usage(argv[0]);
	return (0);
}