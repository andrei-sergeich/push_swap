#include "push_swap.h"

t_lst	*lst_create_new(int data)
{
	t_lst	*element;

	element = (t_lst *)malloc(sizeof(t_lst));
	if (element == NULL)
		return (NULL);
	element->value = data;
	element->next = NULL;
	return (element);
}

int	lst_size(t_lst *lst)
{
	int	x;

	x = 0;
	while (lst)
	{
		lst = lst->next;
		x++;
	}
	return (x);
}

void	lst_add_back(t_lst **head, t_lst *new)
{
	t_lst	*last;

	if (!head || !new)
		return ;
	if (*head)
	{
		last = *head;
		while (last->next)
			last = last->next;
		last->next = new;
	}
	else
		*head = new;
}

void	lst_add_front(t_lst **head, t_lst *new)
{
	if (!head || !new)
		return ;
	new->next = *head;
	*head = new;
}

int	ft_lstfindmax_val(t_lst *lst)
{
	int	max_value;

	max_value = lst->value;
	while (lst)
	{
		if (max_value < lst->value)
			max_value = lst->value;
		lst = lst->next;
	}
	return (max_value);
}

int	ft_lstfindmin_val(t_lst *lst)
{
	int	min_value;

	min_value = lst->value;
	while (lst)
	{
		if (min_value > lst->value)
			min_value = lst->value;
		lst = lst->next;
	}
	return (min_value);
}
