#include "push_swap.h"

int	max_value_finder(t_lst *stack)
{
	int	max_value;
	int	max_ind;
	int	it;

	max_ind = 0;
	max_value = stack->value;
	stack = stack->next;
	it = 1;
	while (stack)
	{
		if (stack->value > max_value)
		{
			max_ind = it;
			max_value = stack->value;
		}
		stack = stack->next;
		it++;
	}
	return (max_ind);
}

int	is_stk_sorted(t_lst *stack)
{
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	small_stk_sort(t_lst **stack)
{
	int	max_index;

	if (lst_size(*stack) == 2 && (*stack)->value > (*stack)->next->value)
		swap_stk(stack, 'a');
	else
	{
		max_index = max_value_finder(*stack);
		if (max_index == 0)
			rotate_stk(stack, 'a');
		else if (max_index == 1)
			rev_rotate_stk(stack, 'a');
		if ((*stack)->value > (*stack)->next->value)
			swap_stk(stack, 'a');
	}
}

void	sorting_stacks(t_lst **a_stk, t_lst **b_stk)
{
	int		lst_len;
	int		med_value;
	int		med_len;

	if (is_stk_sorted(*a_stk) == 0)
		exit (EXIT_SUCCESS);
	lst_len = lst_size(*a_stk);
	med_len = lst_len / 2;
	med_value = ((ft_lstfindmax_val(*a_stk) - ft_lstfindmin_val(*a_stk)) / 2) + 1;
	while (lst_len > 3)
	{
		if (med_value < (*a_stk)->value && lst_len > med_len && med_len > 100)
			rotate_stk(a_stk, 'a');
		else
		{
			push_on_stk(b_stk, a_stk, 'b');
			lst_len--;
		}
	}
	small_stk_sort(a_stk);
	lets_sort(a_stk, b_stk);
}
