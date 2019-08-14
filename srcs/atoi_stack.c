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

t_ps	*atoi_stack(char **av, unsigned short f)
{
	int		i;
	int		j;
	t_ps	*head;
	t_ps	*a;

	i = f + 1;
	if ((av[i][0] < '0' || av[i][0] > '9') && av[i][0] != '-' &&
		av[i][0] != '+')
		return (NULL);
	while (av[++i])
	{
		if (!av[i][0])
			return (NULL);
		j = -1;
		while (av[i][++j])
			if (av[i][j] < '0' || av[i][j] > '9')
				return (NULL);
	}
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
	return (head);
}
