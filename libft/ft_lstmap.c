#include "libft.h"

t_list	*ft_lstmap(t_list *lst, int (*f)(int), int (*del)(int))
{
	t_list	*head;
	t_list	*new_list;

	if (!lst || !f)
		return (NULL);
	head = ft_lstnew(f(lst->value));
	lst = lst->next;
	while (lst)
	{
		new_list = ft_lstnew(f(lst->value));
		if (!new_list)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		ft_lstadd_back(&head, new_list);
		lst = lst->next;
	}
	return (head);
}
