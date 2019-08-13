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

#include "checker.h"

void	applyrule(int **stack, int **size, char **rule)
{
	int		len;

	len = ft_strlen(*rule);
	if (len == 2)
	{
		if ((*rule)[0] == 's' && (*rule)[1] == 'a' && (*size)[0] > 1)
			swap(&stack[0]);
		else if ((*rule)[0] == 's' && (*rule)[1] == 'b' && (*size)[1] > 1)
			swap(&stack[1]);
		else if ((*rule)[0] == 's' && (*rule)[1] == 's')
		{
			(*size)[0] > 1 ? swap(&stack[0]) : 0;
			(*size)[1] > 1 ? swap(&stack[1]) : 0;
		}
		else if ((*rule)[0] == 'p' && (*rule)[1] == 'a' && (*size)[1] > 0)
			push(stack, size, 0);
		else if ((*rule)[0] == 'p' && (*rule)[1] == 'b' && (*size)[0] > 0)
			push(stack, size, 1);
		else if ((*rule)[0] == 'r' && (*rule)[1] == 'a' && (*size)[0] > 1)
			rotate(&stack[0], (*size)[0], 0);
		else if ((*rule)[0] == 'r' && (*rule)[1] == 'b' && (*size)[1] > 1)
			rotate(&stack[1], (*size)[1], 0);
		else if ((*rule)[0] == 'r' && (*rule)[1] == 'r')
		{
			(*size)[0] > 1 ? rotate(&stack[0], (*size)[0], 0) : 0;
			(*size)[1] > 1 ? rotate(&stack[1], (*size)[1], 0) : 0;
		}
	}
	else if (len == 3 && (*rule)[0] == 'r' && (*rule)[1] == 'r')
	{
		if ((*rule)[2] == 'a' && (*size)[0] > 1)
			rotate(&stack[0], (*size)[0], 1);
		else if ((*rule)[2] == 'b' && (*size)[1] > 1)
			rotate(&stack[1], (*size)[1], 1);
		else if ((*rule)[2] == 'r')
		{
			(*size)[0] > 1 ? rotate(&stack[0], (*size)[0], 1) : 0;
			(*size)[1] > 1 ? rotate(&stack[1], (*size)[1], 1) : 0;
		}
	}
	free(*rule);
	*rule = NULL;
}
