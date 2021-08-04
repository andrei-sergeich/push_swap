#include "push_swap.h"

void	double_swap_stk(t_lst **a_stk, t_lst **b_stk)
{
	swap_stk(a_stk, 'd');
	swap_stk(b_stk, 'd');
	ft_putendl_fd("ss", 1);
}

void	double_rotate_stk(t_lst **a_stk, t_lst **b_stk)
{
	rotate_stk(a_stk, 'd');
	rotate_stk(b_stk, 'd');
	ft_putendl_fd("rr", 1);
}

void	double_rev_rotate_stk(t_lst **a_stk, t_lst **b_stk)
{
	rev_rotate_stk(a_stk, 'd');
	rev_rotate_stk(b_stk, 'd');
	ft_putendl_fd("rrr", 1);
}
