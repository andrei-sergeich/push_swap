#include "push_swap.h"

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

void	small_stk_sort(t_list **stack)
{
	int	max_index;

	if (ft_lstsize(*stack) == 2 && (*stack)->value > (*stack)->next->value)
		swap_stk(stack, 'a');
	else
	{
		max_index = ft_lstfind_ind_of_max_value(*stack);
		if (max_index == 0)
			rotate_stk(stack, 'a');
		else if (max_index == 1)
			rev_rotate_stk(stack, 'a');
		if ((*stack)->value > (*stack)->next->value)
			swap_stk(stack, 'a');
	}
}

void	sorting_stacks(t_list **a_stk, t_list **b_stk)
{
	int		lst_len;
	int		med_value;
	int		med_len;

	if (is_stk_sorted(*a_stk) == 0)
		exit (EXIT_SUCCESS);
	lst_len = ft_lstsize(*a_stk);
	med_len = lst_len / 2;
	med_value = ((ft_lstfindmax_val(*a_stk) + \
					ft_lstfindmin_val(*a_stk))) / 2;
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
