/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listcpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 12:44:45 by shunt             #+#    #+#             */
/*   Updated: 2019/08/15 12:44:47 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps	*listcpy(t_ps *src)
{
	t_ps	*res;

	if (!(res = (t_ps *)malloc(sizeof(t_ps))))
		return (NULL);
	res->nxt = NULL;
	res->n = src->n;
	res->prv = NULL;
	res->c = src->c;
	while (src->nxt)
	{
		if (!(res->nxt = (t_ps *)malloc(sizeof(t_ps))))
			return (NULL);
		res->nxt->prv = res;
		res = res->nxt;
		src = src->nxt;
		res->nxt = NULL;
		res->n = src->n;
		res->c = src->c;
	}
	while (res->prv)
		res = res->prv;
	return (res);
}
