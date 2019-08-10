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

NAME = checker

INCLUDE = includes/checker.h

SRCS = srcs/ans.c srcs/dots.c \
	   srcs/field.c srcs/fillit.c \
	   srcs/finfi.c srcs/fr_fi.c \
	   srcs/fr_tf.c srcs/fr_ttr.c \
	   srcs/frsh.c srcs/main.c srcs/nfi.c \
	   srcs/ntr.c srcs/nttr.c srcs/path.c \
	   srcs/prans.c srcs/pst.c \
	   srcs/strc.c srcs/valb.c srcs/valbuf.c \
	   srcs/valf.c srcs/valsh.c srcs/error.c srcs/pref.c

all: $(NAME)

$(NAME): lib
	@gcc -Wall -Wextra -Werror -I $(INCLUDE) -I libft/libft.h -o $(NAME) $(SRCS) -L libft -lft

lib:
	@make -C libft

clean:
	@make -C libft clean

fclean: clean
	@/bin/rm -rf $(NAME)
	@make -C libft fclean

re: fclean all
