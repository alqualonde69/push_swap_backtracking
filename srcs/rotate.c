/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 21:28:44 by shunt             #+#    #+#             */
/*   Updated: 2019/08/13 21:28:45 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rotate(int **stack, int size, int dir)
{
	int		i;
	int		tmp;

	tmp = dir ? (*stack)[size - 1] : (*stack)[0];
	i = dir ? size - 1 : 0;
	if (dir)
		while (--i >= 0)
			(*stack)[i + 1] = (*stack)[i];
	else
		while (++i < size)
			(*stack)[i - 1] = (*stack)[i];
	dir ? ((*stack)[i + 1] = tmp) : ((*stack)[i - 1] = tmp);
}
