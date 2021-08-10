#include "push_swap.h"

void	rr_mode(t_list **a_stk, t_list **b_stk, t_act min_quan_act)
{
	while (min_quan_act.ra && min_quan_act.rb)
	{
		double_rotate_stk(a_stk, b_stk);
		min_quan_act.ra--;
		min_quan_act.rb--;
	}
	while (min_quan_act.ra)
	{
		rotate_stk(a_stk, 'a');
		min_quan_act.ra--;
	}
	while (min_quan_act.rb)
	{
		rotate_stk(b_stk, 'b');
		min_quan_act.rb--;
	}
}

void	rrr_mode(t_list **a_stk, t_list **b_stk, t_act min_quan_act)
{
	while (min_quan_act.rra && min_quan_act.rrb)
	{
		double_rev_rotate_stk(a_stk, b_stk);
		min_quan_act.rra--;
		min_quan_act.rrb--;
	}
	while (min_quan_act.rra)
	{
		rev_rotate_stk(a_stk, 'a');
		min_quan_act.rra--;
	}
	while (min_quan_act.rrb)
	{
		rev_rotate_stk(b_stk, 'b');
		min_quan_act.rrb--;
	}
}

void	ra_and_rrb_mode(t_list **a_stk, t_list **b_stk, t_act min_quan_act)
{
	while (min_quan_act.ra)
	{
		rotate_stk(a_stk, 'a');
		min_quan_act.ra--;
	}
	while (min_quan_act.rrb)
	{
		rev_rotate_stk(b_stk, 'b');
		min_quan_act.rrb--;
	}
}

void	rb_and_rra_mode(t_list **a_stk, t_list **b_stk, t_act min_quan_act)
{
	while (min_quan_act.rb)
	{
		rotate_stk(b_stk, 'b');
		min_quan_act.rb--;
	}
	while (min_quan_act.rra)
	{
		rev_rotate_stk(a_stk, 'a');
		min_quan_act.rra--;
	}
}
