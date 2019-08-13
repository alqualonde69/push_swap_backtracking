# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shunt <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/10 13:25:42 by shunt             #+#    #+#              #
#    Updated: 2019/08/10 13:25:49 by shunt            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DEF			=	\033[0m
BOLD		=	\033[1m
UNDERLINE	=	\033[4m
REV			=	\033[7m
BLACK		=	\033[30m
RED			=	\033[31m
GREEN		=	\033[32m
YELLOW		=	\033[33m
BLUE		=	\033[34m
PINK		=	\033[35m
CYAN		=	\033[36m
GREY		=	\033[37m
BLACK_B		=	\033[40m
RED_B		=	\033[41m
GREEN_B		=	\033[42m
YELLOW_B	=	\033[43m
BLUE_B		=	\033[44m
PINK_B		=	\033[45m
CYAN_B		=	\033[46m
GREY_B		=	\033[47m

NAME			=	checker

LIB_PATH		=	libft/
LIB_INC_PATH	=	libft/includes/

LIB_NAME		=	libft.a

LIB				=	$(addprefix $(LIB_PATH), $(LIB_NAME))
LIB_INC			=	$(addprefix -I, $(LIB_INC_PATH))

SRC_PATH		=	srcs/
INC_PATH		=	includes/

SRC_NAME		=	applyrule.c charjoin.c c_main.c error.c issort.c\
					atoi_stack.c push.c rotate.c swap.c

SRC				=	$(addprefix $(SRC_PATH), $(SRC_NAME))
INC				=	$(addprefix -I, $(INC_PATH))

all:				$(NAME)

$(NAME):			$(LIB)
	@gcc -Wall -Wextra -Werror $(INC) $(LIB_INC) -o $(NAME) $(SRC) -L libft -lft
	@echo "  🌸 🌸 🌸     🌸 🌸 🌸"
	@echo "🌸       🌸 🌸       🌸"
	@echo "🌸        🌸        🌸"
	@echo " 🌸  $(PINK)CHECKER READY🌸"
	@echo "   🌸           🌸"
	@echo "     🌸       🌸"
	@echo "       🌸   🌸"
	@echo "         🌸"

$(LIB):
	@make -C libft

clean:
	@make -C libft clean

fclean:				clean
	@rm -rf $(NAME)
	@make -C libft fclean

re: fclean all
