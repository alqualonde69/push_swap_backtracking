/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sequence.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 17:24:05 by shunt             #+#    #+#             */
/*   Updated: 2019/08/14 17:24:06 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		sequence(int i, char *seq)
{
	int		j;
	int		c;

	c = seqchr(seq, '0');
	if (i != (int)ft_strlen(seq))
	{
		j = -1;
		while (++j < i)
			seq[j] = j > 0 && seq[j - 1] == '2' ? '3' : '2';
		return (1);
	}
	j = i;
	while (--i >= 0)
	{
		if (seq[i] != '0' && seq[i] != '1')
		{
			++seq[i];
			if ((i && c < 2 && seq[i] > '4') || (i && c > 1 && seq[i] > ':'))
				seq[i] = '2';
			else if ((!i && c < 2 && seq[i] > '4') || (!i && c > 1 && seq[i] > ':'))
				return (0);
			else
				break ;
		}
	}
	while (!(issortseq(seq, j, c)))
	return (1);
}
