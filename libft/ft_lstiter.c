#include "libft.h"

void	ft_lstiter(t_list *lst, int (*f)(int))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->value);
		lst = lst->next;
	}
}
