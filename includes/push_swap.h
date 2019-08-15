/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 01:07:43 by shunt             #+#    #+#             */
/*   Updated: 2019/08/14 01:07:44 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include "libft.h"
# include "ft_printf.h"
# include <stdio.h>

# define V	(1u << 0u)
# define C	(1u << 1u)

//# define DEF		\033[0m
//# define BOLD		\033[1m
//# define UNDERLINE	\033[4m
//# define REV		\033[7m
//# define BLACK		\033[30m
//# define RED		\033[31m
//# define GREEN		\033[32m
//# define YELLOW		\033[33m
//# define BLUE		\033[34m
//# define PINK		\033[35m
//# define CYAN		\033[36m
//# define GREY		\033[37m
//# define BLACK_B	\033[40m
//# define RED_B		\033[41m
//# define GREEN_B	\033[42m
//# define YELLOW_B	\033[43m
//# define BLUE_B		\033[44m
//# define PINK_B		\033[45m
//# define CYAN_B		\033[46m
//# define GREY_B		\033[47m

typedef struct	s_ps
{
	int 		n;
	char 		c;
	struct s_ps	*nxt;
	struct s_ps	*prv;
}				t_ps;

void			applyrule(t_ps **a, t_ps **b, char **rule);
char			*charjoin(char **rule, char buf);
int				error(void);
int				issort(t_ps *a);
t_ps			*atoi_stack(char **av, unsigned short i);
void			push(t_ps **dst, t_ps **src);
void			rotate(t_ps **stack, int dir);
void			swap(t_ps **stack);
char			**rules_m(void);
int				*intcpy(int *src, int sz);
void			push_swap(t_ps *a, t_ps *b, char **rules);
int				sequence(int i, char **seq);
void			print_rules(char **rules, char *seq, int i);
t_ps			*b_stack(int i);
void			free_t_ps(t_ps **a, t_ps **b);
void			print(t_ps *a, t_ps *b, int f);
t_ps			*listcpy(t_ps *src);
void			listcpy2(t_ps *src, t_ps **dst);
int 			test(t_ps *a, t_ps *b, char ***rs, int i);

#endif
