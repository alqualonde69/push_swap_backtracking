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
	char	**rules;
	t_ps	*a;
	t_ps	*b;

	if (ac < 2)
		return (0);
	if (!(a = atoi_stack(av, 0)))
		return (error());
	if (!(b = b_stack(ac - 1)))
		return (0);
	if (!(rules = rules_m()))
		return (0);
	push_swap(a, b, rules);
	return (0);
}
