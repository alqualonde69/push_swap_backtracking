/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 17:25:02 by shunt             #+#    #+#             */
/*   Updated: 2019/08/14 17:25:03 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//void	print_rules2(char **rules, int *seq, int i)
//{
//	int 	j;
//
//	j = -1;
//	while (++j < i)
//	{
//		ft_putstr(rules[seq[j]]);
//		write(1, " ", 1);
//	}
//	write(1, "\n", 1);
//}

void	push_swap(t_ps *a, t_ps *b, char **rules)
{
	t_ps	*ta;
	t_ps	*tb;
	char 	***rs;
	int		i;
	int 	k;

	if (issort(a))
		return ;
	if (!(ta = listcpy(a)))
		return ;
	if (!(tb = listcpy(b)))
		return ;
	i = 1;
	if (!(rs = (char ***)malloc(sizeof(char **) * 2)))
		return ;
	if (!(rs[0] = (char **)malloc(sizeof(char *) * 1)))
		return ;
	if (!(rs[0][0] = (char *)malloc(sizeof(char) * 6000)))
		return ;
	rs[1] = rules;
	ft_bzero(rs[0][0], 6000);
	while (i)
	{
		listcpy2(a, &ta);
		listcpy2(b, &tb);
		if (!(k = sequence(i, &rs[0][0])))
			return ;
		if (k == 2)
			++i;
		else
			if (test(ta, tb, rs, i))
				return (print_rules(rules, rs[0][0], i));
	}
}
