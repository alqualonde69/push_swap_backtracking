/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charjoin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 21:27:59 by shunt             #+#    #+#             */
/*   Updated: 2019/08/13 21:28:00 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*charjoin(char **rule, char buf)
{
	int		i;
	char 	*res;

	if (!(*rule))
	{
		if (!(res = (char *)malloc(sizeof(char) * (2))))
			return (NULL);
		res[0] = buf;
		res[1] = '\0';
		return (res);
	}
	i = -1;
	while((*rule)[++i])
		;
	if (!(res = (char *)malloc(sizeof(char) * (i + 2))))
		return (NULL);
	i = -1;
	while ((*rule)[++i])
		res[i] = (*rule)[i];
	res[i] = buf;
	res[++i] = '\0';
	free(*rule);
	return (res);
}
