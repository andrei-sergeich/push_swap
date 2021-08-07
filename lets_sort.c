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

int	find_best_place_in_stk(t_lst *a_stk, t_lst *b_stk)
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
	int best_place_for_a;
	int count_of_step_in_b;
	int step_count;
	int step_count_best;
	int ind;
	t_lst *tmp;

	tmp = b_stk;
	ind = 0;
	step_count_best = find_count_of_step_in_b((b_stk), tmp->value) \
		+ find_best_place_in_stk(a_stk, tmp);
	while (tmp)
	{
		count_of_step_in_b = find_count_of_step_in_b(b_stk, tmp->value);
//		printf("best_place_in_b - %d\n", count_of_step_in_b);
		best_place_for_a = find_best_place_in_stk(a_stk, tmp);
//		printf("best_place_for_a - %d\n", best_place_for_a);
		step_count = count_of_step_in_b + best_place_for_a;
//		printf("step_count = %d\n\n", step_count);
		if (step_count < step_count_best)
		{
			step_count_best = step_count;
			ind++;
		}
		tmp = tmp->next;
	}
//	printf("step_count_best = %d, index of element - %d\n", step_count_best, ind);
	return (ind);
}

void	lets_sort(t_lst **a_stk, t_lst **b_stk)
{
//	int ind;

	while (lst_size(*b_stk))
	{
		while (find_best_index_in_b(*a_stk, *b_stk) != 0)
			rotate_stk(b_stk, 'b');
		while (find_best_place_in_stk(*a_stk, *b_stk) != 0)
		{
//			printf("%d\n\n", find_best_place(*a_stk, *b_stk));
			if (find_best_place_in_stk(*a_stk, *b_stk) > lst_size(*a_stk) / 2)
				rev_rotate_stk(a_stk, 'a');
			else
				rotate_stk(a_stk, 'a');
		}
		push_on_stk(a_stk, b_stk, 'a');
	}
	lets_sort_any_stk(a_stk, 'a');

//	ind = find_best_index_in_b(*a_stk, *b_stk);
//	printf("index of element - %d\n", ind);
}

