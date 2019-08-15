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

int		ft_seqchr(char *s, char c, int i)
{
	int		j;
	int		k;

	j = -1;
	k = 0;
	while (++j < i)
		if (s[j] == c)
			++k;
	return (k);
}

int		sequence(int i, char **seq)
{
	int		j;

	if (i != (int)ft_strlen(*seq))
	{
		j = -1;
		while (++j < i)
		{
			if (j > 0 && (*seq)[j - 1] == '0' && i > 2)
				(*seq)[j] = '4';
			else if (j > 0 && (*seq)[j - 1] == '0' && i < 2)
				(*seq)[j] = '5';
			(*seq)[j] = '0';
		}
	}
	j = i;
	while (--i >= 0)
	{
		if (i > 0 && (*seq)[i - 1] == '1' && (*seq)[i] == '0' && j > 2)
			(*seq)[i] = ft_seqchr(*seq, '4') ? '3' : '4';
		else if (i > 0 && (*seq)[i - 1] == '1' && (*seq)[i] == '0' && j < 2)
			(*seq)[i] = '5';
		else if (i > 0 && (*seq)[i - 1] == '2' && (*seq)[i] == '0' && j > 2)
			(*seq)[i] = ft_seqchr(*seq, '4') ? '3' : '4';
		else if (i > 0 && (*seq)[i - 1] == '2' && (*seq)[i] == '0' && j > 2)
			(*seq)[i] = '5';
		else
			++(*seq)[i];
		if ((*seq)[i] > ':' && i)
			(*seq)[i] = '0';
		else if ((*seq)[i] > ':' && !i)
			return (2);
		else
			break ;
	}
	return (1);
}
