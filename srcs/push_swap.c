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

char	*push_swap(t_ps *a, t_ps *b, char **rules)
{
	t_ps	*ta;
	t_ps	*tb;
	char 	***rs;
	int		i;
	int 	k;

	k = 1;
	if (issort(a))
		return (NULL);
	if (!(ta = listcpy(a)))
		return (NULL);
	if (!(tb = listcpy(b)))
		return (NULL);
	i = 1;
	if (!(rs = (char ***)malloc(sizeof(char **) * 2)))
		return (NULL);
	if (!(rs[0] = (char **)malloc(sizeof(char *) * 1)))
		return (NULL);
	if (!(rs[0][0] = (char *)malloc(sizeof(char) * 6000)))
		return (NULL);
	rs[1] = rules;
	ft_bzero(rs[0][0], 6000);
	while (i)
	{
		!k ? k = 1 : 0;
		listcpy2(a, &ta);
		listcpy2(b, &tb);
		if (!(sequence(i, rs[0][0])))
		{
			if (i > 2 && k < i / 2 + i % 2)
			{
				if (!(newp(rs[0][0], i, k)))
				{
					if (k + 1 < i / 2 + i % 2)
						newp(rs[0][0], i, ++k);
					else
					{
						++i;
						k = 0;
					}
				}
			}
			else
			{
				++i;
				k = 0;
			}
		}
		if (k)
			if (test(ta, tb, rs, i))
				return (rs[0][0]);
	}
	return (NULL);
}
