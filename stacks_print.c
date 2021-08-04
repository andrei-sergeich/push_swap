#include "push_swap.h"

void 	stack_print(t_lst *stack)
{
	while (stack)
	{
		printf("%d\n", stack->value);
		stack = stack->next;
	}
}
