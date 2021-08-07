#include "push_swap.h"

int	find_count_of_step_in_b(t_lst *stack, int value)
{
	int	it;

	it = 0;
	while (stack)
	{
		if (stack->value == value)
			return (it);
		it++;
		stack = stack->next;
	}
	return (it);
}

int	find_best_place_in_a(t_lst *a_stk, t_lst *b_stk)
{
	int	best_value;
	int	best_ind;
	int	it;

	best_value = a_stk->value;
	best_ind = 0;
	a_stk = a_stk->next;
	it = 1;
	while (a_stk)
	{
		if ((best_value > a_stk->value && best_value < b_stk->value) \
			|| (a_stk->value > b_stk->value && (best_value < b_stk->value \
			|| best_value > a_stk->value)))
		{
			best_ind = it;
			best_value = a_stk->value;
		}
		a_stk = a_stk->next;
		it++;
	}
	return (best_ind);
}

void	lets_sort_any_stk(t_lst **stack, char stk_name)
{
	int	max_index;
	int	size;

	max_index = max_value_finder(*stack);
	size = lst_size(*stack);
	if (max_index > size / 2)
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

int	find_best_index_in_b(t_lst *a_stk, t_lst *b_stk)
{
	int		cur_number_of_actions;
	int		min_number_of_actions;
	int		ind;
	t_lst	*tmp;

	tmp = b_stk;
	ind = 0;
	min_number_of_actions = find_count_of_step_in_b(b_stk, tmp->value) \
		+ find_best_place_in_a(a_stk, tmp);
	while (tmp)
	{
		cur_number_of_actions = find_count_of_step_in_b(b_stk, tmp->value) \
			+ find_best_place_in_a(a_stk, tmp);
		if (cur_number_of_actions < min_number_of_actions)
		{
			min_number_of_actions = cur_number_of_actions;
			ind++;
		}
		tmp = tmp->next;
	}
	return (ind);
}

void	lets_sort(t_lst **a_stk, t_lst **b_stk)
{
	while (lst_size(*b_stk))
	{
		while (find_best_index_in_b(*a_stk, *b_stk) != 0)
			rotate_stk(b_stk, 'b');
		while (find_best_place_in_a(*a_stk, *b_stk) != 0)
		{
			if (find_best_place_in_a(*a_stk, *b_stk) > lst_size(*a_stk) / 2)
				rev_rotate_stk(a_stk, 'a');
			else
				rotate_stk(a_stk, 'a');
		}
		push_on_stk(a_stk, b_stk, 'a');
	}
	lets_sort_any_stk(a_stk, 'a');
}
