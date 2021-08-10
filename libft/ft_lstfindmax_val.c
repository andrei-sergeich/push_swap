#include "libft.h"

int	ft_lstfindmax_val(t_list *lst)
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
