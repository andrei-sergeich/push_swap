#include "push_swap.h"

void	duplicate_checker(t_list *stack)
{
	t_list	*tmp;

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

void	argv_processing(t_list **a_stk, char **argv, int len)
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
			num = ft_atoi_only_for_num(sump[it]);
			ft_lstadd_back(a_stk, ft_lstnew(num));
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
	t_list	*a_stk;
	t_list	*b_stk;

	a_stk = NULL;
	b_stk = NULL;
	if (argc == 1)
		ft_prompt("No arguments");
	len = argc - 1;
	argv_processing(&a_stk, argv, len);
	duplicate_checker(a_stk);
	sorting_stacks(&a_stk, &b_stk);
//	stacks_print(a_stk, b_stk);
//	stack_print(a_stk, 'A');
}
