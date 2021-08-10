#include "libft.h"

int	ft_lstfind_ind_of_max_value(t_list *lst)
{
	int	max_value;
	int	max_ind;
	int	it;

	max_ind = 0;
	max_value = lst->value;
	lst = lst->next;
	it = 1;
	while (lst)
	{
		if (lst->value > max_value)
		{
			max_ind = it;
			max_value = lst->value;
		}
		lst = lst->next;
		it++;
	}
	return (max_ind);
}
