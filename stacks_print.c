#include "push_swap.h"

void 	stack_print(t_lst *stack, char name)
{
	while (stack)
	{
		printf("%d\n", stack->value);
		stack = stack->next;
	}
	printf("___\n");
	printf(" %c", name);
}

void 	stacks_print(t_lst *a, t_lst *b)
{
	while (a || b)
	{
		if (a != NULL)
		{
			printf("%d\t\t", a->value);
			a = a->next;
		}
		else if (a == NULL)
		{
			printf("*\t\t");
		}
		if (b != NULL)
		{
			printf("%d", b->value);
			b = b->next;
		}
		else if (b == NULL)
		{
			printf("*");
		}
		printf("\n");
	}
	printf("___\t\t___\n");
	printf(" A\t\t B\n");
}
