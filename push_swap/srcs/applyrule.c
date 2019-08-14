/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   applyrule.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 21:31:05 by shunt             #+#    #+#             */
/*   Updated: 2019/08/13 21:31:06 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	applyrule(t_ps **a, t_ps **b, char **rule)
{
	int		len;

	len = ft_strlen(*rule);
	if (len == 2)
	{
		if ((*rule)[0] == 's' && (*rule)[1] == 'a' && (*a)->c && (*a)->nxt->c)
			swap(a);
		else if ((*rule)[0] == 's' && (*rule)[1] == 'b' && (*b)->c && (*b)->nxt->c)
			swap(b);
		else if ((*rule)[0] == 's' && (*rule)[1] == 's')
		{
			(*a)->c && (*a)->nxt->c ? swap(a) : 0;
			(*b)->c && (*b)->nxt->c ? swap(b) : 0;
		}
		else if ((*rule)[0] == 'p' && (*rule)[1] == 'a' && (*b)->c)
			push(a, b);
		else if ((*rule)[0] == 'p' && (*rule)[1] == 'b' && (*a)->c)
			push(b, a);
		else if ((*rule)[0] == 'r' && (*rule)[1] == 'a' && (*a)->c && (*a)->nxt->c)
			rotate(a, 0);
		else if ((*rule)[0] == 'r' && (*rule)[1] == 'b' && (*b)->c && (*b)->nxt->c)
			rotate(b, 0);
		else if ((*rule)[0] == 'r' && (*rule)[1] == 'r')
		{
			(*a)->c && (*a)->nxt->c ? rotate(a, 0) : 0;
			(*b)->c && (*b)->nxt->c ? rotate(b, 0) : 0;
		}
	}
	else if (len == 3 && (*rule)[0] == 'r' && (*rule)[1] == 'r')
	{
		if ((*rule)[2] == 'a' && (*a)->c && (*a)->nxt->c)
			rotate(a, 1);
		else if ((*rule)[2] == 'b' && (*b)->c && (*b)->nxt->c)
			rotate(b, 1);
		else if ((*rule)[2] == 'r')
		{
			(*a)->c && (*a)->nxt->c ? rotate(a, 1) : 0;
			(*b)->c && (*b)->nxt->c ? rotate(b, 1) : 0;
		}
	}
//	free(*rule);
//	*rule = NULL;
}
