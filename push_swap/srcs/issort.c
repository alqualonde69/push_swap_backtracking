/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   issort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 21:39:19 by shunt             #+#    #+#             */
/*   Updated: 2019/08/13 21:39:20 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		issort(t_ps *a)
{
	while (a->nxt)
	{
		if (a->n > a->nxt->n)
			return (0);
		a = a->nxt;
	}
	return (1);
}
