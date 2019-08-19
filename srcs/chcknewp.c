/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chcknewp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 02:46:50 by shunt             #+#    #+#             */
/*   Updated: 2019/08/17 02:46:51 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int 	chcknewp(char *seq, int i)
{
	int 	j;

	if (i != (int)ft_strlen(seq))
	{
		seq[0] = '0';
		seq[1] = '2';
		seq[2] = '1';
		j = 2;
		while (++j < i)
			seq[j] = seq[j - 1] == '2' ? '3' : '2';
		return (1);
	}
	j = i;
	while (--j >= 0 && seq[j] != '0')
		;
	while (seq[++j])
	{
		if (MVP && MVP2 && MVP3 && (MVP4))
		{
			seq[j] = '0';
			seq[j + 1] = '2';
			seq[j + 2] = '1';
			return (1);
		}
	}
	return (0);
}
