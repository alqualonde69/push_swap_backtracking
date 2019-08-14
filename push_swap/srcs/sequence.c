/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sequence.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 17:24:05 by shunt             #+#    #+#             */
/*   Updated: 2019/08/14 17:24:06 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		sequence(int i, char **seq)
{
	int 	len;

	if (i != ft_strlen(*seq))
	{
		while (--i >= 0)
			(*seq)[i] = '0';
	}
	while (--i >= 0)
	{
		++(*seq)[i];
		if ((*seq)[i] > ':' && i)
			(*seq)[i] = '0';
		else if ((*seq)[i] > ':' && !i)
			return (2);
		else
			break ;
	}
	return (1);
}
