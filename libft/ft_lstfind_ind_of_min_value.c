#include "libft.h"

int	ft_lstfind_ind_of_min_value(t_list *lst)
{
	int	min_value;
	int	min_ind;
	int	it;

	min_ind = 0;
	min_value = lst->value;
	lst = lst->next;
	it = 1;
	while (lst)
	{
		if (lst->value < min_value)
		{
			min_ind = it;
			min_value = lst->value;
		}
		lst = lst->next;
		it++;
	}
	return (min_ind);
}
