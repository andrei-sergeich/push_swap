#include "libft.h"

void	ft_lstdelone(t_list *lst, int (*del)(int))
{
	if (!lst)
		return ;
	del(lst->value);
	free(lst);
	lst = NULL;
}
