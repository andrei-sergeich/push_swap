#include "push_swap.h"

int	is_stak_sorted(t_lst *stack)
{
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

//void	small_stack_sort(t_lst *a_stk, t_lst *b_stk)
//{
//
//}

void	sorting_stacks(t_lst **a_stk, t_lst **b_stk)
{
	if (!is_stak_sorted(*a_stk))
	{
//		if (lst_size(*a_stk) <= 3)
//		{
//			small_stack_sort(a_stk, b_stk);
//			swap_stk(&a_stk, 'a');
//			rotate_stk(a_stk, 'a');
//		}
//		swap_stk(&a_stk, 'a');
		rotate_stk(a_stk, 'a');
		(*b_stk) = lst_create_new(6);
	}
}
