#include "checker.h"

void	swap_stk(t_list **stack)
{
	t_list	*tmp;

	if ((*stack) != NULL && (*stack)->next != NULL)
	{
		tmp = (*stack)->next;
		(*stack)->next = (*stack)->next->next;
		tmp->next = (*stack);
		(*stack) = tmp;
	}
}

void	rotate_stk(t_list **stack)
{
	t_list	*tmp;
	t_list	*new_head;

	if ((*stack) != NULL && (*stack)->next != NULL)
	{
		tmp = *stack;
		new_head = (*stack)->next;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = *stack;
		(*stack)->next = NULL;
		*stack = new_head;
	}
}

void	rev_rotate_stk(t_list **stack)
{
	t_list	*tmp;
	t_list	*current;

	if ((*stack) != NULL && (*stack)->next != NULL)
	{
		tmp = *stack;
		current = *stack;
		while (current->next != NULL)
		{
			tmp = current;
			current = current->next;
		}
		tmp->next = NULL;
		current->next = *stack;
		*stack = current;
	}
}

void	push_on_stk(t_list **to, t_list **from)
{
	t_list	*tmp;

	if ((*from) != NULL)
	{
		tmp = *from;
		*from = (*from)->next;
		ft_lstadd_front(to, tmp);
	}
}
