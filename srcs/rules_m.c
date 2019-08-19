/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_m.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 17:23:21 by shunt             #+#    #+#             */
/*   Updated: 2019/08/14 17:23:23 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**rules_m(void)
{
	char	**rules;
	int 	i;

	if (!(rules = (char **)malloc(sizeof(char *) * 12)))
		return (0);
	i = -1;
	while (++i < 4)
		if (!(rules[i] = (char *)malloc(sizeof(char) * 3)))
			return (0);
	if (!(rules[i] = (char *)malloc(sizeof(char) * 4)))
		return (0);
	while (++i < 9)
		if (!(rules[i] = (char *)malloc(sizeof(char) * 3)))
			return (0);
	while (i < 11)
		if (!(rules[i++] = (char *)malloc(sizeof(char) * 4)))
			return (0);
	i = -1;
	while (++i < 4)
		rules[i][2] = '\0';
	rules[i][3] = '\0';
	while (++i < 9)
		rules[i][2] = '\0';
	while (i < 11)
		rules[i++][3] = '\0';
	i = 0;
	while (++i < 4)
		rules[i][1] = 'a';
	rules[i][0] = 'r';
	rules[i][1] = 'r';
	rules[i][2] = 'a';
	i = 6;
	while (++i < 11)
	{
		rules[i][0] = 'r';
		rules[i][1] = 'r';
	}
	rules[7][1] = 'b';
	rules[0][0] = 'p';
	rules[0][1] = 'b';
	rules[1][0] = 'p';
	rules[2][0] = 's';
	rules[3][0] = 'r';
	rules[5][0] = 's';
	rules[5][1] = 'b';
	rules[6][0] = 's';
	rules[6][1] = 's';
	rules[9][2] = 'b';
	rules[10][2] = 'r';
	rules[11] = NULL;
	return (rules);
}
