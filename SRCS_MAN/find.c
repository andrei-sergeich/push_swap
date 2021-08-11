#include "push_swap.h"

void	overwriting_values(t_act *min_quan_act, t_act *cur_act)
{
	min_quan_act->ra = cur_act->ra;
	min_quan_act->rb = cur_act->rb;
	min_quan_act->rra = cur_act->rra;
	min_quan_act->rrb = cur_act->rrb;
	min_quan_act->total = cur_act->total;
	min_quan_act->mode = cur_act->mode;
}

int	find_best_place_in_a(t_list *a_stk, t_list *b_stk)
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

void	find_best_mode(t_act *cur_act)
{
	cur_act->total = INT_MAX;
	if (cur_act->total > ft_find_max(cur_act->ra, cur_act->rb))
	{
		cur_act->total = ft_find_max(cur_act->ra, cur_act->rb);
		cur_act->mode = 1;
	}
	if (cur_act->total > ft_find_max(cur_act->rra, cur_act->rrb))
	{
		cur_act->total = ft_find_max(cur_act->rra, cur_act->rrb);
		cur_act->mode = 2;
	}
	if (cur_act->total > cur_act->ra + cur_act->rrb)
	{
		cur_act->total = cur_act->ra + cur_act->rrb;
		cur_act->mode = 3;
	}
	if (cur_act->total > cur_act->rra + cur_act->rb)
	{
		cur_act->total = cur_act->rra + cur_act->rb;
		cur_act->mode = 4;
	}
}

void	find_best_action(t_list **a_stk, t_list **b_stk, t_act *min_quant_act)
{
	int		index;
	t_list	*tmp;
	t_act	cur_act;

	index = 0;
	tmp = *b_stk;
	min_quant_act->total = INT_MAX;
	while (tmp)
	{
		cur_act.ra = find_best_place_in_a(*a_stk, tmp);
		cur_act.rb = index;
		cur_act.rra = ft_lstsize(*a_stk) - cur_act.ra;
		cur_act.rrb = ft_lstsize(*b_stk) - cur_act.rb;
		find_best_mode(&cur_act);
		if (cur_act.total < min_quant_act->total)
			overwriting_values(min_quant_act, &cur_act);
		index++;
		tmp = tmp->next;
	}
}
