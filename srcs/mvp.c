/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mvp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 02:42:09 by shunt             #+#    #+#             */
/*   Updated: 2019/08/17 02:42:11 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int 	mvp(char *seq, int i, int c)
{
	int		k;

	k = seqchr(seq, '0');
	while (c)
	{
		if (movep(seq, i))
		{
			if (k == c)
				return (k);
			if(chcknewp(seq, i))
				return (k + 1);
		}
		else if (k > 1)
		{
			cleanp(seq, i);
			if ((k = mvp(seq, i, c)))
			{
				if (k == c)
					return (k);
				if(chcknewp(seq, i))
					return (k + 1);
			}
		}
		else
			return (0);
	}
	return (0);
}
