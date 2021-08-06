#include "push_swap.h"

int	find_best_place(t_lst *a_stk, t_lst *b_stk)
{
	int	best_value;
	int	best_ind;
	int	it;

	best_ind = 0;
	it = 0;
	best_value = a_stk->value;
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

void	lets_sort(t_lst **a_stk, t_lst **b_stk)
{
//	int	best_place;

	while (lst_size(*b_stk))
	{
//		best_place = find_best_place(*a_stk, *b_stk);
		while (find_best_place(*a_stk, *b_stk) != 0)
		{
//			printf("%d\n\n", find_best_place(*a_stk, *b_stk));
//			if (find_best_place(*a_stk, *b_stk) > lst_size(*a_stk) / 2)
				rotate_stk(a_stk, 'a');
//			else
//				rev_rotate_stk(a_stk, 'a');
		}
		push_on_stk(a_stk, b_stk, 'a');
	}
	lets_sort_any_stk(a_stk, 'a');
}
