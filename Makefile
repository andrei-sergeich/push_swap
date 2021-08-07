NAME		=	push_swap

SRCS		=	main.c	push_swap.c	lists.c\
				sorting.c	lets_sort.c\
				stack_ops_single.c	stack_ops_double.c\
				exit_functions.c\
				\
				\
				stacks_print.c\

LIB_DIR 	= ./libft
HEADER 		= ./push_swap.h

OBJS		=	$(patsubst %.c,%.o,$(SRCS))

OPTFLAGS	=	-O2
CFLAGS		=	-Wall -Wextra -Werror -g

all:		$(NAME)

$(NAME):	$(OBJS)
			@make -C $(LIB_DIR)
			gcc $(LIB_DIR)/libft.a $(OBJS) -o $(NAME)
			@echo all done, my Master!
# @cp $(LIB_DIR)/libft.a ./
# @make re -C $(LIB_DIR)
# @make fclean -C $(LIB_DIR)
# @make bonus -C $(LIB_DIR)

%.o:		%.c $(HEADER)
			gcc $(CFLAGS) $(OPTFLAGS) -I $(HEADER) -c $< -o $@

norm:
			norminette .

test:
			./push_swap 2147483647 -2147483648

checker:
			ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_Mac $ARG ; ./push_swap $ARG | wc -l

clean:
			@rm -f $(OBJS)
			@make clean -C $(LIB_DIR)
			@echo .o files destroyed, my Master!

fclean:		clean
			@rm -f $(NAME)
			@rm -f libft.a
			@make fclean -C $(LIB_DIR)
			@echo all terminated, my Master!

re:			fclean all

.PHONY:		all clean fclean re bonus
