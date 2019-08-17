/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 02:39:47 by shunt             #+#    #+#             */
/*   Updated: 2019/08/17 02:39:50 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		newp(char *seq, int i, int c)
{
	int j;
	int k;

	k = seqchr(seq, '9');
	j = -1;
	if (c > k)
		testp(seq, i, c, k);
	else if (k == c)
		if (!(mvp(seq, i, c)))
			return (0);
	j = -1;
	while (seq[++j])
		if (seq[j] != '9' && seq[j] != ':')
			seq[j] = j > 0 && seq[j - 1] == '0' ? '1' : '0';
	return (1);
}