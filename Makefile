NAME		=	push_swap

SRCS		=	main.c	push_swap.с	lists.c	sorting.c	\
				stacks_operations.c\
				stacks_print.c\

LIB_DIR 	= .\libft
HEADER 		= .\push_swap.h

OBJS		=	$(patsubst %.c,%.o,$(SRCS))

OPTFLAGS	=	-O2
CFLAGS		=	-Wall -Wextra -Werror -g

all:		$(NAME)

$(NAME):	$(OBJS)
			@make -C $(LIB_DIR)
#			@cp $(LIB_DIR)\libft.a .\libft.a
			gcc libft.a $(OBJS) -o $(NAME)
			@echo all done, my Master!
# @make re -C $(LIB_DIR)
# @make fclean -C $(LIB_DIR)
# @make bonus -C $(LIB_DIR)

%.o:		%.c $(HEADER)
			gcc $(CFLAGS) $(OPTFLAGS) -c $< -o $@

norm:
			norminette .

test:
			./push_swap -123 +254 "663    734"

clean:
			@rm -f $(OBJS)
			@make clean -C $(LIB_DIR)
			@echo .o files destroyed, my Master!

fclean:		clean
			@rm -f $(NAME)
			@rm -f .\libft.a
			@make fclean -C $(LIB_DIR)
			@echo all terminated, my Master!

re:			fclean all

.PHONY:		all clean fclean re bonus
