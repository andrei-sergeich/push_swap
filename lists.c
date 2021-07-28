#include "push_swap.h"

t_lst	*lst_create_new(int data)
{
	t_lst	*element;

	element = (t_lst *)malloc(sizeof(t_lst));
	if (!element)
		return (NULL);
	element->value = data;
	// tmp->index = 0;
	// tmp->flag = 0;
	element->next = NULL;
	return (element);
}


// t_lst	*getLast(t_lst *head)
// {
// 	if (!head)
// 		ft_error("No list here\n");
// 	while (head->next)
// 		head = head->next;
// 	return (head);
// }


// void	ft_add_back(t_lst *head, int value)
// {
// 	t_lst *last;
// 	t_lst *tmp;
	
// 	if (!head)
// 		ft_error("No list\n");
// 	last = getLast(head);
// 	tmp = (t_lst *)malloc(sizeof(t_lst));
// 	if (!tmp)
// 		ft_error("No malloc\n");
// 	tmp->value = value;
// 	tmp->next = NULL;
// 	last->next = tmp;
// }

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


void lst_add_front(t_lst **head, int data)
{
	t_lst	*tmp;
	
	if (!head)
		ft_error("No list\n");
	tmp = (t_lst *)malloc(sizeof(t_lst));
	if (!tmp)
		ft_error("No malloc\n");
	tmp->value = data;
	// tmp->index = 0;
	// tmp->flag = 0;
	tmp->next = (*head);
	(*head) = tmp;
}