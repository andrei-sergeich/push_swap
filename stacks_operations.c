#include "push_swap.h"

void 	swap_stk(t_lst **stack, char stk_name)
{
	int save;

	if ((*stack) != NULL && (*stack)->next != NULL)
	{
		save = (*stack)->value;
		(*stack)->value = (*stack)->next->value;
		(*stack)->next->value = save;
	}
	if (stk_name == 'a')
		ft_putstr_fd("sa\n", 1);
	else if (stk_name == 'b')
		ft_putstr_fd("sb\n", 1);
}

void 	double_swap_stk(t_lst **a_stk, t_lst **b_stk)
{
	swap_stk(a_stk, 'd');
	swap_stk(b_stk, 'd');
	ft_putstr_fd("ss\n", 1);
}

void 	rotate_stk(t_lst **stack, char stk_name)
{
	int first;
	int last;
	t_lst *tmp;

	tmp = *stack;
	if ((*stack) != NULL && (*stack)->next != NULL)
	{
		first = tmp->value;
		last = lst_get_last(tmp)->value;
		(*stack)->value = last;
		tmp->value = first;
	}
	if (stk_name == 'a')
		ft_putstr_fd("ra\n", 1);
	else if (stk_name == 'b')
		ft_putstr_fd("rb\n", 1);
}

void 	double_rotate_stk(t_lst **a_stk, t_lst **b_stk)
{
	rotate_stk(a_stk, 'd');
	rotate_stk(b_stk, 'd');
	ft_putstr_fd("rr\n", 1);
}
