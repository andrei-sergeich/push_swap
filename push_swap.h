#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h> 									/* УБЕРИ!!! И НА ПРИНТФЫ ПРОВЕРЬ, НА ИХ ОТСУТСТВИЕ!!!!!!!!!!!! */
# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_lst
{
	int				value;
	// int				index;
	// int				flag;
	struct s_lst	*next;
}	t_lst;

int		main(int argc, char **argv);
void	argv_processing(t_lst **a_stk, char **argv, int len);
void	sump_checker(char *str);
void	ft_error(char *str);
t_lst	*lst_create_new(int data);
void	lst_add_back(t_lst **head, t_lst *new);
void	lst_add_front(t_lst **lst, t_lst *new);
int		lst_size(t_lst *lst);
//t_lst	*lst_get_last(t_lst *lst);
void	sorting_stacks(t_lst **a_stk, t_lst **b_stk);
int		is_stk_sorted(t_lst *stack);

void	small_stk_sort(t_lst **stack);
int		max_value_finder(t_lst *stack);


void 	swap_stk(t_lst **stack, char stk_name);
void 	double_swap_stk(t_lst **a_stk, t_lst **b_stk);
void 	rotate_stk(t_lst **stack, char stk_name);
void 	double_rotate_stk(t_lst **a_stk, t_lst **b_stk);
void 	rev_rotate_stk(t_lst **stack, char stk_name);
void	double_rev_rotate_stk(t_lst **a_stk, t_lst **b_stk);
void	push_on_stk(t_lst **to, t_lst **from, char stk_name);


// void	ft_add_back(t_lst *head, int value);
//void	new_lst_add_front(t_lst **head, int data);
//void	ft_del_lst(t_lst *lst);



void 	stack_print(t_lst *stack); 						/* УБЕРИ!!! ПОТОМ!!!!!!!!!!!! */

#endif