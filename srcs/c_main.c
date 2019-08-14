/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 13:26:51 by shunt             #+#    #+#             */
/*   Updated: 2019/08/10 13:27:02 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		main(int ac, char **av)
{
	char	buf;
	char	*rule;
	int		**stack;
	int		*size;

	buf = 0;
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
	while ((read(0, &buf, 1)))
	{
		if (buf && buf != '\n')
		{
			if (!(rule = charjoin(&rule, buf)))
				return (0);
		}
		else if (buf == '\n')
			applyrule(stack, &size, &rule);
	}
	if (size[1] == 0 && issort(stack[0], size[0]))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	stack[0] ? free(stack[0]) : 0;
	stack[1] ? free(stack[1]) : 0;
	free(size);
	free(stack);
	return (0);
}