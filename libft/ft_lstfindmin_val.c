#include "libft.h"

int	ft_lstfindmin_val(t_list *lst)
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
