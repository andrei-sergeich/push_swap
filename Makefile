NAME		=	push_swap


SRCS_MAN	=	./SRCS_MAN/main.c		./SRCS_MAN/push_swap.c\
				./SRCS_MAN/sorting.c	./SRCS_MAN/lets_sort.c\
				./SRCS_MAN/modes.c		./SRCS_MAN/find.c\
				./SRCS_MAN/stack_ops_single.c\
				./SRCS_MAN/stack_ops_double.c\
				\
				\
				./SRCS_MAN/stacks_print.c\

LIB_DIR 	= ./libft
HEADER 		= ./SRCS_MAN/push_swap.h

OBJS_MAN		=	$(patsubst %.c,%.o,$(SRCS_MAN))

OPTFLAGS	=	-O2
CFLAGS		=	-Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(OBJS_MAN)
			@make -C $(LIB_DIR)
			gcc $(LIB_DIR)/libft.a $(OBJS_MAN) -o $(NAME)
			@clear
			@echo all done, my Master!

%.o:		%.c $(HEADER)
			gcc $(CFLAGS) $(OPTFLAGS) -I $(HEADER) -c $< -o $@

norm:
			norminette .

test:
#			./push_swap 2147483647 -2147483648
#			./push_swap +2147483647 -2147483648
#			./push_swap 21474836471 -2147483648
#			./push_swap +21474836471 -2147483648
#			./push_swap 2147483647 -2147483648
#			./push_swap 2147483647 -2147483649
#			./push_swap 2147483647 -21474836481
#			./push_swap 214748364 -214748364

checker:
			ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_Mac $ARG ; ./push_swap $ARG | wc -l

clean:
			@make clean -C $(LIB_DIR)
			@rm -f $(OBJS_MAN)
			@clear
			@echo OBJS files destroyed, my Master!

fclean:		clean
			@make fclean -C $(LIB_DIR)
			@rm -f $(NAME)
			@clear
			@echo all terminated, my Master!

re:			fclean all

.PHONY:		all clean fclean re bonus
