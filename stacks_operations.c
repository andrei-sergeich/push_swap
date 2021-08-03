#include "push_swap.h"

void	swap_stk(t_lst **stack, char stk_name)
{
	int	save;

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

void	double_swap_stk(t_lst **a_stk, t_lst **b_stk)
{
	swap_stk(a_stk, 'd');
	swap_stk(b_stk, 'd');
	ft_putstr_fd("ss\n", 1);
}

void	rotate_stk(t_lst **stack, char stk_name)
{
	t_lst	*tmp;
	t_lst	*new_head;

	if ((*stack) != NULL && (*stack)->next != NULL)
	{
		tmp = *stack;
		new_head = (*stack)->next;
		while(tmp->next)
			tmp = tmp->next;
		tmp->next = *stack;
		(*stack)->next = NULL;
		*stack = new_head;
	}
	if (stk_name == 'a')
		ft_putstr_fd("ra\n", 1);
	else if (stk_name == 'b')
		ft_putstr_fd("rb\n", 1);
}

void	double_rotate_stk(t_lst **a_stk, t_lst **b_stk)
{
	rotate_stk(a_stk, 'd');
	rotate_stk(b_stk, 'd');
	ft_putstr_fd("rr\n", 1);
}

void	rev_rotate_stk(t_lst **stack, char stk_name)
{
	t_lst	*tmp;
	t_lst	*current;

	if ((*stack) != NULL && (*stack)->next != NULL)
	{
		tmp = *stack;
		current = *stack;
		while(current->next != NULL)
		{
			tmp = current;
			current = current->next;
		}
		tmp->next = NULL;
		current->next = *stack;
		*stack = current;
	}
	if (stk_name == 'a')
		ft_putstr_fd("rra\n", 1);
	else if (stk_name == 'b')
		ft_putstr_fd("rrb\n", 1);
}

void	double_rev_rotate_stk(t_lst **a_stk, t_lst **b_stk)
{
	rev_rotate_stk(a_stk, 'd');
	rev_rotate_stk(b_stk, 'd');
	ft_putstr_fd("rrr\n", 1);
}

void	push_on_stk(t_lst **to, t_lst **from, char stk_name)
{
	t_lst	*tmp;

	if ((*from) != NULL)
	{
		tmp = *from;
		*from = (*from)->next;
		lst_add_front(to, tmp);
	}
	if (stk_name == 'a')
		ft_putstr_fd("pa\n", 1);
	else if (stk_name == 'b')
		ft_putstr_fd("pb\n", 1);
}