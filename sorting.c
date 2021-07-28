#include "push_swap.h"

int	is_stak_sorted(t_lst *stack)
{
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		printf ("%d\n", stack->value);
		stack = stack->next;		
	}
	return (1);

	// while (stack->next != NULL && stack->value <= stack->next->value)
	// {
	// 	printf ("%d\n", stack->value);
	// 	stack = stack->next;
	// }
	// return (stack->next == NULL);
}

void	sorting_stacks(t_lst *a_stk, t_lst *b_stk)
{
	if (!is_stak_sorted(a_stk))
	{
		printf ("%d\n", a_stk->value);
		printf ("%s\n", "сортируй давай");
		// printf ("%d\n", b_stk->value = 1);
		b_stk = lst_create_new(6);
	}
}
