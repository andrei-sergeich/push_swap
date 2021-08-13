#include "checker.h"

int	is_stk_sorted(t_list *stack)
{
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	duplicate_checker(t_list *stack)
{
	t_list	*tmp;

	while (stack)
	{
		tmp = stack->next;
		while (tmp)
		{
			if (stack->value == tmp->value)
				ft_error("Error");
			tmp = tmp->next;
		}
		stack = stack->next;
	}
}

void	execute_command(t_list **A, t_list **B, char *line)
{
	if (ft_strncmp("sa", line, 3) == 0)
		swap_stk(A);
	else if (ft_strncmp("sb", line, 3) == 0)
		swap_stk(B);
	else if (ft_strncmp("ss", line, 3) == 0)
		double_swap_stk(A, B);
	else if (ft_strncmp("ra", line, 3) == 0)
		rotate_stk(A);
	else if (ft_strncmp("rb", line, 3) == 0)
		rotate_stk(B);
	else if (ft_strncmp("rr", line, 3) == 0)
		double_rotate_stk(A, B);
	else if (ft_strncmp("rra", line, 4) == 0)
		rev_rotate_stk(A);
	else if (ft_strncmp("rrb", line, 4) == 0)
		rev_rotate_stk(B);
	else if (ft_strncmp("rrr", line, 4) == 0)
		double_rev_rotate_stk(A, B);
	else if (ft_strncmp("pa", line, 3) == 0)
		push_on_stk(A, B);
	else if (ft_strncmp("pb", line, 3) == 0)
		push_on_stk(B, A);
	else
		ft_error("Error");
}

void	argv_processing(t_list **A, char **argv, int len)
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
			ft_lstadd_back(A, ft_lstnew(num));
			free(sump[it]);
			it++;
		}
		free(sump);
		val++;
	}
}

void	checker(int argc, char **argv)
{
	int		len;
	char	*line;
	t_list	*A;
	t_list	*B;

	A = NULL;
	B = NULL;
	if (argc == 1)
		exit(0);
	len = argc - 1;
	argv_processing(&A, argv, len);
	duplicate_checker(A);
	while (get_next_line(0, &line))
	{
		execute_command(&A, &B, line);
		free(line);
	}
	free(line);
	if (is_stk_sorted(A) == 0 && ft_lstsize(B) == 0)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
}
