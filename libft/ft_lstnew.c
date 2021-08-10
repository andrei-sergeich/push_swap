#include "libft.h"

t_list	*ft_lstnew(int content)
{
	t_list	*element;

	element = (t_list *)malloc(sizeof(t_list));
	if (!element)
		return (NULL);
	element->value = content;
	element->next = NULL;
	return (element);
}
