#include "push_swap.h"

int	max_value_finder(t_lst *stack)
{
	int	max_value;
	int	max_ind;
	int	it;

	max_ind = 0;
	max_value = stack->value;
	stack = stack->next;
	it = 1;
	while (stack)
	{
		if (stack->value > max_value)
		{
			max_ind = it;
			max_value = stack->value;
		}
		stack = stack->next;
		it++;
	}
	return (max_ind);
}

int	min_value_finder(t_lst *stack)
{
	int	min_value;
	int	min_ind;
	int	it;

	min_ind = 0;
	min_value = stack->value;
	stack = stack->next;
	it = 1;
	while (stack)
	{
		if (stack->value < min_value)
		{
			min_ind = it;
			min_value = stack->value;
		}
		stack = stack->next;
		it++;
	}
	return (min_ind);
}

int	is_stk_sorted(t_lst *stack)
{
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	small_stk_sort(t_lst **stack)
{
	int	max_index;
	int	min_index;

	if (lst_size(*stack) == 2 && (*stack)->value > (*stack)->next->value)
		swap_stk(stack, 'a');
	else if (lst_size(*stack) == 3)
	{
		max_index = max_value_finder(*stack);
		min_index = min_value_finder(*stack);
//		if (max_index == 0)
//			rotate_stk(stack, 'a');
//		else if (max_index == 1)
//			rev_rotate_stk(stack, 'a');
//		if ((*stack)->value > (*stack)->next->value)
//			swap_stk(stack, 'a');
		if (max_index == 2 && min_index == 1)
			swap_stk(stack, 'a');
		else if (max_index == 0 && min_index == 2)
		{
			swap_stk(stack, 'a');
			rev_rotate_stk(stack, 'a');
		}
		else if (max_index == 0 && min_index == 1)
			rotate_stk(stack, 'a');
		else if (max_index == 1 && min_index == 0)
		{
			swap_stk(stack, 'a');
			rotate_stk(stack, 'a');
		}
		else if (max_index == 1 && min_index == 2)
			rev_rotate_stk(stack, 'a');
	}
}

void	sorting_stacks(t_lst **a_stk, t_lst **b_stk)
{
	if (!is_stk_sorted(*a_stk))
	{
		if (lst_size(*a_stk) <= 3)
			small_stk_sort(a_stk);
//		swap_stk(a_stk, 'a');
//		rotate_stk(a_stk, 'a');
//		rev_rotate_stk(a_stk, 'a');
//		push_on_stk(b_stk, a_stk, 'b');
//		push_on_stk(b_stk, a_stk, 'b');
//		push_on_stk(a_stk, b_stk, 'a');
		(*b_stk) = lst_create_new(6);
	}
}
