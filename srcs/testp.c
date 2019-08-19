/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 02:43:20 by shunt             #+#    #+#             */
/*   Updated: 2019/08/17 02:43:22 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		testp(char *seq, int i, int c, int k)
{
	while (--k >= 0)
		cleannewp(seq, i);
	while (c)
	{
		if (chcknewp(seq, i))
			if (testp(seq, i, c - 1, 0))
				return (1);
		if (!(movep(seq, i)))
			return (cleannewp(seq, i));
	}
	return (1);
}
