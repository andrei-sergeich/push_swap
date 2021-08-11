#ifndef CHECKER_H
# define CHECKER_H

# include <stdio.h> 					/* NOT FOR INTRA!!!!!! */
# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include "limits.h"
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"

int		main(int argc, char **argv);
void	checker(int argc, char **argv);
void	argv_processing(t_list **a_stk, char **argv, int len);
void	execute_command(t_list **A, t_list **B, char *line);
int		is_stk_sorted(t_list *stack);
void	duplicate_checker(t_list *stack);

void	swap_stk(t_list **stack);
void	double_swap_stk(t_list **a_stk, t_list **b_stk);
void	rotate_stk(t_list **stack);
void	double_rotate_stk(t_list **a_stk, t_list **b_stk);
void	rev_rotate_stk(t_list **stack);
void	double_rev_rotate_stk(t_list **a_stk, t_list **b_stk);
void	push_on_stk(t_list **to, t_list **from);

void	stacks_print(t_list *a, t_list *b);			/* NOT FOR INTRA!!!!!! */

#endif