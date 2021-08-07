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

void	lst_add_front(t_lst **lst, t_lst *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

void	ft_del_lst(t_lst *lst)
{
	if (!lst)
		return ;
	lst->value = 0;
	lst = NULL;
	free(lst);
}

void	new_lst_add_front(t_lst **head, int data)
{
	t_lst	*tmp;

	if (!head)
		ft_error("No list");
	if (*head)
	{
		tmp = (t_lst *) malloc(sizeof(t_lst));
		if (tmp)
		{
			tmp->value = data;
			tmp->next = (*head);
			(*head) = tmp;
		}
		else
			ft_error("No malloc");
	}
	else
		ft_error("No head of lst");
}

t_lst	*lst_get_last(t_lst *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

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
