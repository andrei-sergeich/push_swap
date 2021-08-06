#include "push_swap.h"

int	find_best_place(t_lst *a_stk, t_lst *b_stk)
{
	int	tmp;
	int	best;
	int	best_ind;
	int	it;

	best_ind = 0;
	best = b_stk->value - a_stk->value;
	a_stk = a_stk->next;
	it = 1;
	while (a_stk)
	{
		tmp = b_stk->value - a_stk->value;
		if (tmp > 0)
		{
			if (tmp < best)
			{
				best_ind = it;
				best = tmp;
			}
		}
		else
		{
			if (tmp > best)
			{
				best_ind = it;
				best = tmp;
			}
		}
		a_stk = a_stk->next;
		it++;
	}
	return (best_ind);
}

void	lets_sort(t_lst **a_stk, t_lst **b_stk)
{
	int	best_place;

//	while (lst_size(*b_stk))
	{
		best_place = find_best_place(*a_stk, *b_stk);
		printf("%d\n\n", best_place);
//		if (best_place == lst_size(*a_stk) - 1)
//		{
//			push_on_stk(a_stk, b_stk, 'a');
//			rotate_stk(a_stk, 'a');
//		}
//		else
//		{
//			while (best_place > 0)
//			{
//				rotate_stk(a_stk, 'a');
//				best_place--;
//			}
//		}
	}
}
