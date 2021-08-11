NAME_MAN	=	push_swap
NAME_BONUS	=	checker

SRCS_MAN	=	$(MAN_DIR)/main.c		$(MAN_DIR)/push_swap.c\
				$(MAN_DIR)/sorting.c	$(MAN_DIR)/lets_sort.c\
				$(MAN_DIR)/modes.c		$(MAN_DIR)/find.c\
				$(MAN_DIR)/stack_ops_single.c\
				$(MAN_DIR)/stack_ops_double.c\
				\
				\
				$(MAN_DIR)/stacks_print.c\

SRCS_BONUS	=	$(BONUS_DIR)/main.c		$(BONUS_DIR)/checker.c\
				$(BONUS_DIR)/stack_ops_single.c\
				$(BONUS_DIR)/stack_ops_double.c\
				$(GNL_DIR)/get_next_line.c\
				$(GNL_DIR)/get_next_line_utils.c\
				\
				\
				$(BONUS_DIR)/stacks_print.c\

LIB_DIR 	=	./libft
GNL_DIR		=	./gnl
MAN_DIR		=	./SRCS_MAN
BONUS_DIR	=	./SRCS_BONUS

HEADER		=	$(MAN_DIR)/push_swap.h
HEADER_BON	=	$(BONUS_DIR)/checker.h

OBJS_MAN	=	$(patsubst %.c,%.o,$(SRCS_MAN))
OBJS_BONUS	=	$(patsubst %.c,%.o,$(SRCS_BONUS))

OPTFLAGS	=	-O2
CFLAGS		=	-Wall -Wextra -Werror

all:		$(NAME_MAN)

bonus:		$(NAME_BONUS)

$(NAME_MAN):	$(OBJS_MAN)
				@make -C $(LIB_DIR)
				gcc $(LIB_DIR)/libft.a $(OBJS_MAN) -o $(NAME_MAN)
				@clear
				@echo all done, my Master!

$(NAME_BONUS):	$(OBJS_BONUS)
				@make -C $(LIB_DIR)
				gcc $(LIB_DIR)/libft.a $(OBJS_BONUS) -o $(NAME_BONUS)
				@clear
				@echo all done, my Master!

%.o:			%.c $(HEADER)
				gcc $(CFLAGS) $(OPTFLAGS) -I $(HEADER) -c $< -o $@

norm:
				norminette .

test:
#				./push_swap 2147483647 -2147483648
#				./push_swap +2147483647 -2147483648
#				./push_swap 21474836471 -2147483648
#				./push_swap +21474836471 -2147483648
#				./push_swap 2147483647 -2147483648
#				./push_swap 2147483647 -2147483649
#				./push_swap 2147483647 -21474836481
#				./push_swap 214748364 -214748364

clean:
				@make clean -C $(LIB_DIR)
				@rm -f $(OBJS_MAN) $(OBJS_BONUS)
				@clear
				@echo OBJS files destroyed, my Master!

fclean:			clean
				@make fclean -C $(LIB_DIR)
				@rm -f $(NAME_MAN) $(NAME_BONUS)
				@clear
				@echo all terminated, my Master!

re:				fclean all bonus

.PHONY:			all clean fclean re bonus
