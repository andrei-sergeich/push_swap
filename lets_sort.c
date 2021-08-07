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

void	overwriting_values(t_actions *min_quant_actions, t_actions *cur_actions)
{
	min_quant_actions->ra = cur_actions->ra;
	min_quant_actions->rb = cur_actions->rb;
	min_quant_actions->rra = cur_actions->rra;
	min_quant_actions->rrb = cur_actions->rrb;
	min_quant_actions->total = cur_actions->total;
	min_quant_actions->mode = cur_actions->mode;
}

void	actions_count_init(t_actions *min_quant_actions)
{
	min_quant_actions->ra = 0;
	min_quant_actions->rb = 0;
	min_quant_actions->rra = 0;
	min_quant_actions->rrb = 0;
	min_quant_actions->total = INT_MAX;
	min_quant_actions->mode = 0;
}

void	find_best_way(t_actions *cur_actions)
{
	cur_actions->total = INT_MAX;
	if (ft_find_max(cur_actions->ra, cur_actions->rb) < cur_actions->total)
	{
		cur_actions->total = ft_find_max(cur_actions->ra, cur_actions->rb);
		cur_actions->mode = 1;
	}
	if (ft_find_max(cur_actions->rra, cur_actions->rrb) < cur_actions->total)
	{
		cur_actions->total = ft_find_max(cur_actions->rra, cur_actions->rrb);
		cur_actions->mode = 2;
	}
	if (cur_actions->ra + cur_actions->rrb < cur_actions->total)
	{
		cur_actions->total = cur_actions->ra + cur_actions->rrb;
		cur_actions->mode = 3;
	}
	if (cur_actions->rra + cur_actions->rb < cur_actions->total)
	{
		cur_actions->total = cur_actions->rra + cur_actions->rb;
		cur_actions->mode = 4;
	}
}

int	find_best_actions(t_lst *a_stk, t_lst *b_stk)
{
	int			ind;
	t_lst		*tmp;
	t_actions	curent_actions;
	t_actions	min_quantity_actions;

	tmp = b_stk;
	ind = 0;
	actions_count_init(&min_quantity_actions);
//	printf("%d\n", actions.ra);
//	printf("%d\n", actions.rb);
//	printf("%d\n", actions.rra);
//	printf("%d\n", actions.rrb);
//	printf("%d\n", actions.total);
//	printf("%d\n\n", actions.mode);
	while (tmp)
	{
		curent_actions.ra = find_best_place_in_a(a_stk, b_stk);
		curent_actions.rb = ind;
		curent_actions.rra = lst_size(a_stk) - curent_actions.ra;
		curent_actions.rrb = lst_size(b_stk) - curent_actions.rb;
		find_best_way(&curent_actions);
		if (curent_actions.total < min_quantity_actions.total)
			overwriting_values(&min_quantity_actions, &curent_actions);
		ind++;
		tmp = tmp->next;
	}
	return (min_quantity_actions.mode);
}

void	lets_sort(t_lst **a_stk, t_lst **b_stk)
{
	int	min_quantity_actions;

	while (lst_size(*b_stk))
	{
		min_quantity_actions = find_best_actions(*a_stk, *b_stk);
		printf("%d\n\n", min_quantity_actions);
		while (find_best_index_in_b(*a_stk, *b_stk) != 0)
//		{
//			if (find_best_index_in_b(*a_stk, *b_stk) > lst_size(*b_stk) / 2)
//				rev_rotate_stk(b_stk, 'b');
//			else
				rotate_stk(b_stk, 'b');
//		}
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
