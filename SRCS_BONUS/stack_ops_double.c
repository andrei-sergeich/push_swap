#include "checker.h"

void	double_swap_stk(t_list **a_stk, t_list **b_stk)
{
	swap_stk(a_stk);
	swap_stk(b_stk);
}

void	double_rotate_stk(t_list **a_stk, t_list **b_stk)
{
	rotate_stk(a_stk);
	rotate_stk(b_stk);
}

void	double_rev_rotate_stk(t_list **a_stk, t_list **b_stk)
{
	rev_rotate_stk(a_stk);
	rev_rotate_stk(b_stk);
}
