#include "push_swap.h"

void	sump_checker(char *str)
{
	int	it;

	it = 0;
	if (((ft_strncmp(str, "2147483647", 10) > 0 && ft_strlen(str) >= 10)) \
		|| ((ft_strncmp(str, "-2147483648", 11) > 0 && ft_strlen(str) >= 11)))
		ft_error("Error: argument not in INT");
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
			ft_error("Error: not number in the sump");
		it++;
	}
}

void	duplicate_checker(t_lst *stack)
{
	t_lst	*tmp;

	while (stack)
	{
		tmp = stack->next;
		while (tmp)
		{
			if (stack->value == tmp->value)
				ft_error("Error: duplicate find");
			tmp = tmp->next;
		}
		stack = stack->next;
	}
}

void	argv_processing(t_lst **a_stk, char **argv, int len)
{
	int		val;
	int		it;
	int		num;
	char	**sump;

	val = 1;
	while (val <= len)
	{
		it = 0;
		sump = ft_split(argv[val], ' ');
		if (!sump)
			ft_error("Error: no malloc");
		while (sump[it])
		{
			sump_checker(sump[it]);
			num = ft_atoi(sump[it]);
			lst_add_back(a_stk, lst_create_new(num));
			free(sump[it]);
			it++;
		}
		free(sump);
		val++;
	}
}

void	push_swap(int argc, char **argv)
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
		duplicate_checker(a_stk);
	}
	else
		ft_prompt("Not enough arguments");
	sorting_stacks(&a_stk, &b_stk);
//	stacks_print(a_stk, b_stk);
//	stack_print(a_stk, 'A');
}
