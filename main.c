#include "push_swap.h"

void	ft_error(char *str)
{
	ft_putstr_fd(str, 1);
	exit(EXIT_FAILURE);
}

void	sump_checker(char *str)
{
	int	it;

	it = 0;
	if ((ft_strncmp(str, "2147483647", 10) > 0 && ft_strlen(str) == 10) ||
	(ft_strncmp(str, "-2147483648", 11) > 0 && ft_strlen(str) == 11))
		ft_error("Error\n");
	while (str[it])
	{
		if (it == 0 && (str[0] == '+' || str[0] == '-') && str[1])
		{
			if (ft_isdigit(str[1]) && str[2])
				it += 2;
			else
				it += 1;
		}
		if (!ft_isdigit(str[it]))
			ft_error("Error: not number in the sump\n");
		it++;
	}
}

void	argv_processing(t_lst **a_stk, char **argv, int len)
{
	int		val;
	int		it;
	int		num;
	char	**sump;
//	t_lst	*tmp;

//	tmp = NULL;
	val = 1;
	while (val <= len)
	{
		it = 0;
		sump = ft_split(argv[val], ' ');
		if (!sump)
			ft_error("Error of the sump\n");
		while (sump[it])
		{
			sump_checker(sump[it]);
			num = ft_atoi(sump[it]);
//			tmp = lst_create_new(num);
//			lst_add_back(a_stk, tmp);
//			ft_del_lst(tmp);
			lst_add_back(a_stk, lst_create_new(num));
//			printf("%p\n", lst_create_new(num));
//			tmp = NULL;
//			free(tmp);
//			printf("%p\n", a_stk);
			free(sump[it]);
			it++;
		}
		free(sump);
		val++;
	}
}

int	main(int argc, char **argv)
{
	int		len;
	t_lst	*a_stk;
	t_lst	*b_stk;

	a_stk = NULL;
	b_stk = NULL;
	if (argc > 1)
	{
		len = argc - 1;
		argv_processing(&a_stk, argv, len);
	}
	else
		// exit(0);
		ft_error("Error: not enought argc\n");
	sorting_stacks(&a_stk, &b_stk);
	stack_print(a_stk);
	return (0);
}
