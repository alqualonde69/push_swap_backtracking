/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 21:27:37 by shunt             #+#    #+#             */
/*   Updated: 2019/08/13 21:27:39 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		*atoi_stack(char **av)
{
	int		i;
	int		j;
	int		*stack;

	i = 0;
	while (av[++i])
	{
		j = -1;
		while (av[i][++j])
			if (av[i][j] < '0' || av[i][j] > '9')
				return (NULL);
	}
	if (!(stack = (int *)malloc(sizeof(int) * (i - 1))))
		return (NULL);
	i = 0;
	while (av[++i])
		stack[i - 1] = ft_atoi(av[i]);
	return (stack);
}
