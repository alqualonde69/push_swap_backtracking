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

#include "push_swap.h"

int		main(int ac, char **av)
{
	int 			fd;
	char			buf;
	char			*rule;
	t_ps			*a;
	t_ps			*b;
	unsigned short 	flag[2];

	fd = 0;
	buf = 0;
	flag[0] = 0;
	flag[1] = 0;
	if (ac < 2)
		return (0);
	if (!(ft_strcmp(av[1], "-f")) || (ac > 2 && !(ft_strcmp(av[2], "-f"))) || (ac > 3 && !(ft_strcmp(av[3], "-f"))))
	{
		if (!(ft_strcmp(av[1], "-f")))
			fd = 2;
		else if (ac > 2 && !(ft_strcmp(av[2], "-f")))
			fd = 3;
		else if (ac > 3 && !(ft_strcmp(av[3], "-f")))
			fd = 4;
		if ((fd = open(av[fd], O_RDONLY)) == -1)
			return (error());
		flag[1] += 2;
	}
	if (!(ft_strcmp(av[1], "-v")) || (ac > 2 && !(ft_strcmp(av[2], "-v"))) || (ac > 3 && !(ft_strcmp(av[3], "-v"))))
	{
		flag[0] |= V;
		++flag[1];
	}
	if (!(ft_strcmp(av[1], "-c")) || (ac > 2 && !(ft_strcmp(av[2], "-c"))) || (ac > 3 && !(ft_strcmp(av[3], "-c"))))
	{
		flag[0] |= C;
		++flag[1];
	}
	if (!(a = atoi_stack(av, flag[1])))
		return (error());
	if (!(b = b_stack(ac - 1 - flag[1])))
		return (0);
	while ((read(fd, &buf, 1)))
	{
		if (buf && buf != '\n')
		{
			if (!(rule = charjoin(&rule, buf)))
				return (0);
		}
		else if (buf == '\n')
		{
			applyrule(&a, &b, &rule);
			if (flag[0] & V)
				flag[0] & C ? print(a, b, 1) : print(a, b, 0);
			free(rule);
			rule = NULL;
		}
	}
	if (!(b->c) && issort(a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_t_ps(&a, &b);
	return (0);
}