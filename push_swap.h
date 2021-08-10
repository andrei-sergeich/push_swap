#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h> 					/* УБЕРИ!!! И НА ПРИНТФЫ ПРОВЕРЬ!!!!!!*/
# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include "limits.h"
# include "libft/libft.h"

typedef struct s_actions
{
	int	ra;
	int	rra;
	int	rb;
	int	rrb;
	int	total;
	int	mode;
}	t_act;

int		main(int argc, char **argv);
void	push_swap(int argc, char **argv);
void	argv_processing(t_list **a_stk, char **argv, int len);
void	duplicate_checker(t_list *stack);

void	sorting_stacks(t_list **a_stk, t_list **b_stk);
int		is_stk_sorted(t_list *stack);
void	small_stk_sort(t_list **stack);
void	lets_sort(t_list **a_stk, t_list **b_stk);
void	lets_sort_any_stk(t_list **stack, char stk_name);
int		find_best_place_in_a(t_list *a_stk, t_list *b_stk);
void	find_best_action(t_list **a_stk, t_list **b_stk, t_act *min_quant_act);
void	overwriting_values(t_act *min_quan_act, t_act *cur_act);
void	find_best_mode(t_act *cur_actions);

void	rr_mode(t_list **a_stk, t_list **b_stk, t_act min_quan_act);
void	rrr_mode(t_list **a_stk, t_list **b_stk, t_act min_quan_act);
void	ra_and_rrb_mode(t_list **a_stk, t_list **b_stk, t_act min_quan_act);
void	rb_and_rra_mode(t_list **a_stk, t_list **b_stk, t_act min_quan_act);

void	swap_stk(t_list **stack, char stk_name);
void	double_swap_stk(t_list **a_stk, t_list **b_stk);
void	rotate_stk(t_list **stack, char stk_name);
void	double_rotate_stk(t_list **a_stk, t_list **b_stk);
void	rev_rotate_stk(t_list **stack, char stk_name);
void	double_rev_rotate_stk(t_list **a_stk, t_list **b_stk);
void	push_on_stk(t_list **to, t_list **from, char stk_name);

void	stack_print(t_list *stack, char name);	/* УБЕРИ!!! ПОТОМ!!!!!!!!!!!! */
void	stacks_print(t_list *a, t_list *b);		/* УБЕРИ!!! ПОТОМ!!!!!!!!!!!! */

#endif