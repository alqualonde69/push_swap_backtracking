/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 21:28:27 by shunt             #+#    #+#             */
/*   Updated: 2019/08/13 21:28:29 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	push(int **stack, int **size, int o)
{
	int		a;
	int		b;
	int		i;
	int		*tmp;

	a = o ? 1 : 0;
	b = o ? 0 : 1;
	tmp = stack[a];
	if (!(stack[a] = (int *)malloc(sizeof(int) * (++(*size)[a]))))
		return ;
	stack[a][0] = stack[b][0];
	i = 0;
	while (++i < (*size)[a])
		stack[a][i] = tmp[i - 1];
	tmp ? free(tmp) : 0;
	tmp = stack[b];
	if (!(stack[b] = (int *)malloc(sizeof(int) * (--(*size)[b]))))
		return ;
	i = -1;
	while (++i < (*size)[b])
		stack[b][i] = tmp[i + 1];
	tmp ? free(tmp) : 0;
}
