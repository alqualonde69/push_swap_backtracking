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
	while (++i < 8)
		if (!(rules[i] = (char *)malloc(sizeof(char) * 3)))
			return (0);
	while (i < 11)
		if (!(rules[i++] = (char *)malloc(sizeof(char) * 4)))
			return (0);
	i = -1;
	while (++i < 8)
		rules[i][2] = '\0';
	while (i < 11)
		rules[i++][3] = '\0';
	i = 4;
	while (++i < 11)
	{
		rules[i][0] = 'r';
		rules[i][1] = 'r';
	}
	rules[0][0] = 's';
	rules[0][1] = 'a';
	rules[1][0] = 's';
	rules[1][1] = 'b';
	rules[2][0] = 's';
	rules[2][1] = 's';
	rules[3][0] = 'p';
	rules[3][1] = 'a';
	rules[4][0] = 'p';
	rules[4][1] = 'b';
	rules[5][1] = 'a';
	rules[6][1] = 'b';
	rules[8][2] = 'a';
	rules[9][2] = 'b';
	rules[10][2] = 'r';
	rules[11] = NULL;
	return (rules);
}
