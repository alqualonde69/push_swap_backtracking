/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 01:05:05 by shunt             #+#    #+#             */
/*   Updated: 2019/08/14 01:05:07 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int 	main(int ac, char **av)
{
	char	buf;
	char	*rule;
	int		**stack;
	int		*size;

	if (ac < 2)
		return (0);
	if (!(stack = (int **)malloc(sizeof(int *) * 2)))
		return (0);
	if (!(size = (int *)malloc(sizeof(int) * 2)))
		return (0);
	if (!(stack[0] = atoi_stack(av)))
		return (error());
	stack[1] = NULL;
	size[0] = ac - 1;
	size[1] = 0;
	return (0);
}
