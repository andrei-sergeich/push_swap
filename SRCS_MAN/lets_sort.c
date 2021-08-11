#include "push_swap.h"

void	lets_sort_any_stk(t_list **stack, char stk_name)
{
	int	max_index;
	int	half_size;

	max_index = ft_lstfind_ind_of_max_value(*stack);
	half_size = ft_lstsize(*stack) / 2;
	if (max_index > half_size)
	{
		while (is_stk_sorted(*stack) != 0)
			rev_rotate_stk(stack, stk_name);
	}
	else
	{
		while (is_stk_sorted(*stack) != 0)
			rotate_stk(stack, stk_name);
	}
}

void	lets_sort(t_list **a_stk, t_list **b_stk)
{
	t_act	*min_quan_actions;

	min_quan_actions = (t_act *)malloc(sizeof(t_act));
	while (*b_stk)
	{
		find_best_action(a_stk, b_stk, min_quan_actions);
		if (min_quan_actions->mode == 1)
			rr_mode(a_stk, b_stk, *min_quan_actions);
		if (min_quan_actions->mode == 2)
			rrr_mode(a_stk, b_stk, *min_quan_actions);
		if (min_quan_actions->mode == 3)
			ra_and_rrb_mode(a_stk, b_stk, *min_quan_actions);
		if (min_quan_actions->mode == 4)
			rb_and_rra_mode(a_stk, b_stk, *min_quan_actions);
		push_on_stk(a_stk, b_stk, 'a');
	}
	free(min_quan_actions);
	lets_sort_any_stk(a_stk, 'a');
}
