/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 02:44:52 by shunt             #+#    #+#             */
/*   Updated: 2019/08/17 02:44:53 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int 	movep(char *seq, int i)
{
	int 	j;
	int 	k;

	j = i;
	while (--j >= 0 && seq[j] != '0')
		;
	if (j < 0)
		return (0);
	while (seq[++j] && seq[j] != '1')
		;
	if (seq[j + 1] && seq[j + 1] != '1')
	{
		seq[j] = '2';
		seq[j + 1] = '1';
	}
	else
	{
		j = i;
		while (--j >= 0 && seq[j] != '0')
			;
		k = j;
		while (seq[++k] && seq[k] != '1')
			;
		while (seq[++k] && seq[k] != '1')
			;
		if (j + 3 < k)
		{
			while (--k >= 0 && seq[k] != '1')
				;
			seq[j] = '2';
			seq[j + 1] = '0';
			seq[j + 2] = '2';
			seq[k] = '2';
			seq[j + 3] = '1';
		}
		else if (seq[k])
		{
			++j;
			while (seq[++j])
			{
				if (MVP && MVP2 && MVP3 && (MVP4))
				{
					cleanp(seq, i);
					seq[j] = '0';
					seq[j + 1] = '2';
					seq[j + 2] = '1';
					return (1);
				}
			}
			return (0);
		}
		else
			return (0);
	}
	return (1);
}
