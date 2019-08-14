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

void	print_rules2(char **rules, int *seq, int i)
{
	int 	j;

	j = -1;
	while (++j < i)
	{
		ft_putstr(rules[seq[j]]);
		write(1, " ", 1);
	}
	write(1, "\n", 1);
}

int 	test(t_ps *a, t_ps *b, char ***rs, int i)
{
	int 	j;

	j = -1;
//	printf("i = %d ", i);
	while (++j < i)
	{
//		printf("rule%d = %s ", j + 1, rs[1][rs[0][0][j] - 48]);
		applyrule(&a, &b, &rs[1][rs[0][0][j] - 48]);
	}
//	printf("\n");
	if (!(b->c) && issort(a))
		return (1);
	return (0);
}

t_ps	*listcpy(t_ps *src)
{
	t_ps	*res;

	if (!(res = (t_ps *)malloc(sizeof(t_ps))))
		return (NULL);
	res->nxt = NULL;
	res->n = src->n;
	res->prv = NULL;
	res->c = src->c;
	while (src->nxt)
	{
		if (!(res->nxt = (t_ps *)malloc(sizeof(t_ps))))
			return (NULL);
		res->nxt->prv = res;
		res = res->nxt;
		src = src->nxt;
		res->nxt = NULL;
		res->n = src->n;
		res->c = src->c;
	}
	while (res->prv)
		res = res->prv;
	return (res);
}

void	listcpy2(t_ps *src, t_ps **dst)
{
	t_ps	*tmp;

	tmp = *dst;
	while (src && (*dst))
	{
		(*dst)->c = src->c;
		(*dst)->n = src->n;
		*dst = (*dst)->nxt;
		src = src->nxt;
	}
	*dst = tmp;
}

void	push_swap(t_ps *a, t_ps *b, char **rules)
{
	t_ps	*ta;
	t_ps	*tb;
	char 	***rs;
	int		i;
	int 	k;

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
