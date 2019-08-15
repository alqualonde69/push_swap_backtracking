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

int		seqchr(char *s, char c)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (s[++i])
		if (s[i] == c)
			++j;
	return (j);
}

int		newp(char **seq, int i, int c)
{
	int		j;

	j = -1;
	if (!c)
	{
		(*seq)[++j] = '9';
		(*seq)[++j] = '0';
		(*seq)[++j] = ':';
		while ((*seq)[++j])
			(*seq)[j] = j > 0 && (*seq)[j - 1] == '0' ? '0' : '5';
		return (1);
	}
	while ((*seq)[++j] && (*seq)[j] != ':')
		;
	if ((*seq)[j + 1])
	{
		(*seq)[j] = '0';
		(*seq)[j + 1] = ':';
	}
	else
	{
		j = -1;
		while ((*seq)[++j] && (*seq)[j] != '9')
			;
		if (j + 1 < i - 2)
		{
			(*seq)[j] = '0';
			(*seq)[j + 1] = '9';
		}
		else
			return (2);
	}
	j = -1;
	while ((*seq)[++j])
		if ((*seq)[j] != '9' && (*seq)[j] != ':')
			(*seq)[j] = j > 0 && (*seq)[j - 1] == '0' ? '0' : '5';
	return (1);
}

int		valid(char **seq, int i)
{
	int		j;

	j = i;
	while (--j >= 0)
	{
		if (j && (((*seq)[j - 1] == '0' && (*seq)[j] == '0') ||
			((*seq)[j - 1] == '0' && (*seq)[j] == '3') ||
			((*seq)[j - 1] == '0' && (*seq)[j] == '4') ||
			((*seq)[j - 1] == '1' && (*seq)[j] == '2') ||
			((*seq)[j - 1] == '1' && (*seq)[j] == '5') ||
			((*seq)[j - 1] == '1' && (*seq)[j] == '8') ||
			((*seq)[j - 1] == '2' && (*seq)[j] == '1') ||
			((*seq)[j - 1] == '2' && (*seq)[j] == '6') ||
			((*seq)[j - 1] == '2' && (*seq)[j] == '7') ||
			((*seq)[j - 1] == '3' && (*seq)[j] == '0') ||
			((*seq)[j - 1] == '3' && (*seq)[j] == '3') ||
			((*seq)[j - 1] == '3' && (*seq)[j] == '4') ||
			((*seq)[j - 1] == '4' && (*seq)[j] == '0') ||
			((*seq)[j - 1] == '4' && (*seq)[j] == '3') ||
			((*seq)[j - 1] == '4' && (*seq)[j] == '4') ||
			((*seq)[j - 1] == '5' && (*seq)[j] == '1') ||
			((*seq)[j - 1] == '5' && (*seq)[j] == '7') ||
			((*seq)[j - 1] == '5' && (*seq)[j] == '8') ||
			((*seq)[j - 1] == '6' && (*seq)[j] == '2') ||
			((*seq)[j - 1] == '6' && (*seq)[j] == '7') ||
			((*seq)[j - 1] == '6' && (*seq)[j] == '8') ||
			((*seq)[j - 1] == '7' && (*seq)[j] == '2') ||
			((*seq)[j - 1] == '7' && (*seq)[j] == '5') ||
			((*seq)[j - 1] == '7' && (*seq)[j] == '6') ||
			((*seq)[j - 1] == '8' && (*seq)[j] == '1') ||
			((*seq)[j - 1] == '8' && (*seq)[j] == '5') ||
			((*seq)[j - 1] == '8' && (*seq)[j] == '6')))
			++(*seq)[j];
	}
}

int		sequence(int i, char **seq)
{
	int		j;
	int		c;

	j = -1;
	if (i != ft_strlen(*seq))
		while (++j < i)
			(*seq)[j] = j > 0 && (*seq)[j - 1] == '0' ? '0' : '5';
	else
	{
		c = seqchr(*seq, '9');
		j = i;
		while (--j >= 0)
		{
			if ((*seq)[j] != '9' && (*seq)[j] != ':')
			{
				++(*seq)[j];
				if (((c < 2 && (*seq)[j] > '2') || (c >= 2 && (*seq) > '8')) && j)
					(*seq)[j] = '0';
				else if (((c < 2 && (*seq)[j] > '2') || (c >= 2 && (*seq) > '8')) && !j)
					return (i > 2 ? newp(seq, i, c) : 2);
				else
					break ;
			}
		}
		if (valid(seq, i))
			return (i > 2 ? newp(seq, i, c) : 2);
	}
	return (1);
}
