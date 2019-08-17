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

	if (i != ft_strlen(seq))
	{
		seq[0] = '9';
		seq[1] = '0';
		seq[2] = ':';
		j = 2;
		while (++j < i)
			seq[j] = seq[j - 1] == '0' ? '1' : '0';
		return (1);
	}
	j = i;
	while (--j >= 0 && seq[j] != '9')
		;
	while (seq[++j])
	{
		if (MVP && MVP2 && MVP3 && (MVP4))
		{
			seq[j] = '9';
			seq[j + 1] = '0';
			seq[j + 2] = ':';
			return (1);
		}
	}
	return (0);
}
