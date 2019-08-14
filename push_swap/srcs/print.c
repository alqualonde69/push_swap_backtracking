/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 21:12:23 by shunt             #+#    #+#             */
/*   Updated: 2019/08/14 21:12:24 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		print(t_ps *a, t_ps *b, int f)
{
	f ? write(1, "\033[31m+-----------------------------------+\n", 43) :
		write(1, "+-----------------------------------+\n", 38);
	f ? write(1, "|\033[46m        a        \033[40m|\033[46m        ", 42) :
		write(1, "|        a        |        ", 27);
	f ? write(1, "b        \033[40m|\n", 16) : write(1, "b        |\n", 11);
	write(1, "+-----------------------------------+\n", 38);
	while (a && b)
	{
		if (a->c)
		{
			f ? write(1, "|\033[46m", 6) : write(1, "|", 1);
			ft_printf("%16d ", a->n);
			f ? write(1, "\033[40m|", 6) : write(1, "|", 1);
		}
		else
			f ? write(1, "|\033[46m                 \033[40m|", 29) :
				write(1, "|                 |", 19);
		if (b->c)
		{
			f ? write(1, "\033[46m", 5) : 0;
			ft_printf("%16d ", b->n);
			f ? write(1, "\033[40m|\n", 7) : write(1, "|\n", 2);
		}
		else
			f ? write(1, "\033[46m                 \033[40m|\n", 29) :
				write(1, "                 |\n", 19);
		a = a->nxt;
		b = b->nxt;
	}
	f ? write(1, "\033[31m+-----------------------------------+\033[0m\n", 47) :
		write(1, "+-----------------------------------+\n", 38);
}
