/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 21:27:37 by shunt             #+#    #+#             */
/*   Updated: 2019/08/13 21:27:39 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int 	freetps(t_ps *a)
{
	while (a->nxt)
	{
		a->prv ? free(a->prv) : 0;
		a = a->nxt;
	}
	free(a);
	return (1);
}

int 	isdup(t_ps *a)
{
	t_ps	*b;

	while (a->nxt)
	{
		b = a->nxt;
		while (b)
		{
			if (a->n == b->n)
				return (freetps(a));
			b = b->nxt;
		}
		a = a->nxt;
	}
	return (0);
}

int 	chckstack(char	**av, int i)
{
	int		len;
	while (av[++i])
	{
		if ((len = ft_strlen(av[i])) > 11)
			return (1);
		else if (len == 11)
		{
			if (av[i][0] != '-' && av[i][0] != '+')
				return (1);
			if (av[i][1] > '2')
				return (1);
			if (av[i][1] == '2' && av[i][2] > '1')
				return (1);
			if (av[i][1] == '2' && av[i][2] == '1' && av[i][3] > '4')
				return (1);
			if (av[i][1] == '2' && av[i][2] == '1' && av[i][3] == '4' && av[i][4] > '7')
				return (1);
			if (av[i][1] == '2' && av[i][2] == '1' && av[i][3] == '4' && av[i][4] == '7' && av[i][5] > '4')
				return (1);
			if (av[i][1] == '2' && av[i][2] == '1' && av[i][3] == '4' && av[i][4] == '7' && av[i][5] == '4' && av[i][6] > '8')
				return (1);
			if (av[i][1] == '2' && av[i][2] == '1' && av[i][3] == '4' && av[i][4] == '7' && av[i][5] == '4' && av[i][6] == '8' && av[i][7] > '3')
				return (1);
			if (av[i][1] == '2' && av[i][2] == '1' && av[i][3] == '4' && av[i][4] == '7' && av[i][5] == '4' && av[i][6] == '8' && av[i][7] == '3' && av[i][8] > '6')
				return (1);
			if (av[i][1] == '2' && av[i][2] == '1' && av[i][3] == '4' && av[i][4] == '7' && av[i][5] == '4' && av[i][6] == '8' && av[i][7] == '3' && av[i][8] == '6' && av[i][9] > '4')
				return (1);
			if (av[i][0] == '-' && av[i][1] == '2' && av[i][2] == '1' && av[i][3] == '4' && av[i][4] == '7' && av[i][5] == '4' && av[i][6] == '8' && av[i][7] == '3' && av[i][8] == '6' && av[i][9] == '4' && av[i][10] > '8')
				return (1);
			if (av[i][0] == '+' && av[i][1] == '2' && av[i][2] == '1' && av[i][3] == '4' && av[i][4] == '7' && av[i][5] == '4' && av[i][6] == '8' && av[i][7] == '3' && av[i][8] == '6' && av[i][9] == '4' && av[i][10] > '7')
				return (1);
		}
		else if (len == 10)
		{
			if (av[i][0] > '2')
				return (1);
			if (av[i][0] == '2' && av[i][1] > '1')
				return (1);
			if (av[i][0] == '2' && av[i][1] == '1' && av[i][2] > '4')
				return (1);
			if (av[i][0] == '2' && av[i][1] == '1' && av[i][2] == '4' && av[i][3] > '7')
				return (1);
			if (av[i][0] == '2' && av[i][1] == '1' && av[i][2] == '4' && av[i][3] == '7' && av[i][4] > '4')
				return (1);
			if (av[i][0] == '2' && av[i][1] == '1' && av[i][2] == '4' && av[i][3] == '7' && av[i][4] == '4' && av[i][5] > '8')
				return (1);
			if (av[i][0] == '2' && av[i][1] == '1' && av[i][2] == '4' && av[i][3] == '7' && av[i][4] == '4' && av[i][5] == '8' && av[i][6] > '3')
				return (1);
			if (av[i][0] == '2' && av[i][1] == '1' && av[i][2] == '4' && av[i][3] == '7' && av[i][4] == '4' && av[i][5] == '8' && av[i][6] == '3' && av[i][7] > '6')
				return (1);
			if (av[i][0] == '2' && av[i][1] == '1' && av[i][2] == '4' && av[i][3] == '7' && av[i][4] == '4' && av[i][5] == '8' && av[i][6] == '3' && av[i][7] == '6' && av[i][7] > '4')
				return (1);
			if (av[i][0] == '2' && av[i][1] == '1' && av[i][2] == '4' && av[i][3] == '7' && av[i][4] == '4' && av[i][5] == '8' && av[i][6] == '3' && av[i][7] == '6' && av[i][7] == '4' && av[i][9] > '8')
				return (1);
		}
	}
	return (0);
}

t_ps	*atoi_stack(char **av, unsigned short f)
{
	int		i;
	int		j;
	t_ps	*head;
	t_ps	*a;

	i = f;
	while (av[++i])
	{
		if ((av[i][0] < '0' || av[i][0] > '9') && av[i][0] != '-' &&
			av[i][0] != '+')
			return (NULL);
		if ((av[i][0] == '-' || av[i][0] == '+') && !av[i][1])
			return (NULL);
		j = 0;
		while (av[i][++j])
			if (av[i][j] < '0' || av[i][j] > '9')
				return (NULL);
	}
	if (chckstack(av, f))
		return (NULL);
	if (!(head = (t_ps *)malloc(sizeof(t_ps))))
		return (NULL);
	head->n = ft_atoi(av[++f]);
	head->c = 1;
	head->prv = NULL;
	head->nxt = NULL;
	a = head;
	while (av[++f])
	{
		if (!(a->nxt = (t_ps *)malloc(sizeof(t_ps))))
			return (NULL);
		a->nxt->prv = a;
		a = a->nxt;
		a->n = ft_atoi(av[f]);
		a->c = 1;
		a->nxt = NULL;
	}
	if (isdup(head))
		return (NULL);
	return (head);
}
