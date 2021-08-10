#include "push_swap.h"

int	find_best_place_in_a(t_lst *a_stk, t_lst *b_stk)
{
	int	best_value;
	int	best_ind;
	int	it;

	best_value = a_stk->value;
	best_ind = 0;
	it = 1;
	a_stk = a_stk->next;
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
	int	half_size;

	max_index = max_value_finder(*stack);
	half_size = lst_size(*stack) / 2;
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

void	overwriting_values(t_act *min_quan_actions, t_act *cur_actions)
{
	min_quan_actions->ra = cur_actions->ra;
	min_quan_actions->rb = cur_actions->rb;
	min_quan_actions->rra = cur_actions->rra;
	min_quan_actions->rrb = cur_actions->rrb;
	min_quan_actions->total = cur_actions->total;
	min_quan_actions->mode = cur_actions->mode;
}

void	find_best_mode(t_act *cur_actions)
{
	cur_actions->total = INT_MAX;
	if (cur_actions->total > ft_find_max(cur_actions->ra, cur_actions->rb))
	{
		cur_actions->total = ft_find_max(cur_actions->ra, cur_actions->rb);
		cur_actions->mode = 1;
	}
	if (cur_actions->total > ft_find_max(cur_actions->rra, cur_actions->rrb))
	{
		cur_actions->total = ft_find_max(cur_actions->rra, cur_actions->rrb);
		cur_actions->mode = 2;
	}
	if (cur_actions->total > cur_actions->ra + cur_actions->rrb)
	{
		cur_actions->total = cur_actions->ra + cur_actions->rrb;
		cur_actions->mode = 3;
	}
	if (cur_actions->total > cur_actions->rra + cur_actions->rb)
	{
		cur_actions->total = cur_actions->rra + cur_actions->rb;
		cur_actions->mode = 4;
	}
}

void	find_best_actions(t_lst **a_stk, t_lst **b_stk, t_act *min_quan_actions)
{
	int		index;
	t_lst	*tmp;
	t_act	cur_actions;

	index = 0;
	tmp = *b_stk;
	min_quan_actions->total = INT_MAX;
	while (tmp)
	{
		cur_actions.ra = find_best_place_in_a(*a_stk, tmp);
		cur_actions.rb = index;
		cur_actions.rra = lst_size(*a_stk) - cur_actions.ra;
		cur_actions.rrb = lst_size(*b_stk) - cur_actions.rb;
		find_best_mode(&cur_actions);
		if (cur_actions.total < min_quan_actions->total)
			overwriting_values(min_quan_actions, &cur_actions);
		index++;
		tmp = tmp->next;
	}
}

void	rr_mode(t_lst **a_stk, t_lst **b_stk, t_act min_quan_actions)
{
	while (min_quan_actions.ra && min_quan_actions.rb)
	{
		double_rotate_stk(a_stk, b_stk);
		min_quan_actions.ra--;
		min_quan_actions.rb--;
	}
	while (min_quan_actions.ra)
	{
		rotate_stk(a_stk, 'a');
		min_quan_actions.ra--;
	}
	while (min_quan_actions.rb)
	{
		rotate_stk(b_stk, 'b');
		min_quan_actions.rb--;
	}
}

void	rrr_mode(t_lst **a_stk, t_lst **b_stk, t_act min_quan_actions)
{
	while (min_quan_actions.rra && min_quan_actions.rrb)
	{
		double_rev_rotate_stk(a_stk, b_stk);
		min_quan_actions.rra--;
		min_quan_actions.rrb--;
	}
	while (min_quan_actions.rra)
	{
		rev_rotate_stk(a_stk, 'a');
		min_quan_actions.rra--;
	}
	while (min_quan_actions.rrb)
	{
		rev_rotate_stk(b_stk, 'b');
		min_quan_actions.rrb--;
	}
}

void	ra_and_rrb_mode(t_lst **a_stk, t_lst **b_stk, t_act min_quan_actions)
{
	while (min_quan_actions.ra)
	{
		rotate_stk(a_stk, 'a');
		min_quan_actions.ra--;
	}
	while (min_quan_actions.rrb)
	{
		rev_rotate_stk(b_stk, 'b');
		min_quan_actions.rrb--;
	}
}

void	rb_and_rra_mode(t_lst **a_stk, t_lst **b_stk, t_act min_quan_actions)
{
	while (min_quan_actions.rb)
	{
		rotate_stk(b_stk, 'b');
		min_quan_actions.rb--;
	}
	while (min_quan_actions.rra)
	{
		rev_rotate_stk(a_stk, 'a');
		min_quan_actions.rra--;
	}
}

void	lets_sort(t_lst **a_stk, t_lst **b_stk)
{
	t_act	*min_quan_actions;

	min_quan_actions = (t_act *)malloc(sizeof(t_act) * 100);
	while (*b_stk)
	{
		find_best_actions(a_stk, b_stk, min_quan_actions);
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
