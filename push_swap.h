#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h> /* УБЕРИ!!! И НА ПРИНТФЫ ПРОВЕРЬ, НА ИХ ОТСУТСТВИЕ!!!!!!!!!!!! */
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
void	lst_add_front(t_lst **head, int data);
void	lst_add_back(t_lst **head, t_lst *new);
void	sorting_stacks(t_lst *a_stk, t_lst *b_stk);
int		is_stak_sorted(t_lst *stack);
// void	ft_add_back(t_lst *head, int value);

#endif