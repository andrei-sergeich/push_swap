#include "push_swap.h"

void	ft_prompt(char *str)
{
	ft_putendl_fd(str, 1);
	exit(EXIT_SUCCESS);
}

void	ft_error(char *str)
{
	ft_putendl_fd(str, 1);
	exit(EXIT_FAILURE);
}
