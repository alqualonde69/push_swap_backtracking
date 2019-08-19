/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
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
	int 	fd[2];
	char	**rules;
	char 	*seq;
	t_ps	*a;
	t_ps	*b;

	fd[0] = -1;
	fd[1] = 0;
	if (ac < 2)
		return (0);
	if (!(ft_strcmp(av[1], "-f")))
	{
		if (av[2])
			if ((fd[0] = open(av[2], O_WRONLY | O_CREAT | O_APPEND, S_IWRITE | S_IREAD)) == -1)
				return (error());
		fd[1] = 2;
	}
	if (!(a = atoi_stack(av, fd[1])))
		return (error());
	if (!(b = b_stack(ac - 1)))
		return (0);
	if (!(rules = rules_m()))
		return (0);
	if (!(seq = push_swap(a, b, rules)))
		return (0);
	print_rules(rules, seq, fd[0]);
	free_t_ps(&a, &b);
	return (0);
}
