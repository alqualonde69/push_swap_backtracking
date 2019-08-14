/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 17:24:32 by shunt             #+#    #+#             */
/*   Updated: 2019/08/14 17:24:33 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		*intcpy(int *src, int sz)
{
	int 	*res;
	int 	i;

	if (!sz)
		return (NULL);
	if (!(res = (int *)malloc(sizeof(int) * sz)))
		return (NULL);
	i = -1;
	while (++i < sz)
		res[i] = src[i];
	return (res);
}
