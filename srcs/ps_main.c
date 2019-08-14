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

char	**rules_m(void)
{
	char	**rules;

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
		r[i][2] = '\0';
	while (i < 11)
		r[i++][3] = '\0';
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

int		sequence(int i, int **seq)
{
	int		j;

	if (!(*seq))
	{
		if (!(*seq = (int *)malloc(sizeof(int) * i)))
			return (0);
		j = -1;
		while (++j < i)
			(*seq)[i] = 0;
	}
	else
	{
		j = i;
		while (--j >= 0)
		{
			++(*seq)[j];
			if ((*seq)[j] > 10 && j)
				(*seq)[j] = 0;
			else if ((*seq)[j] > 10 && !j)
				return (i + 1);
			else
				break ;
		}
	}
	return (i);
}

int		*intcpy(int *src, int sz)
{
	int 	*res;
	int 	i;

	if (!(res = (int *)malloc(sizeof(int) * sz)))
		return (NULL);
	i = -1;
	while (++i < sz)
		res[i] = src[i];
	return (res);
}

void	push_swap(int **stack, int *size, char **rules)
{
	int		**tst;
	int		*ts;
	int		i;
	int		*seq;
	int		j;

	i = 1;
	seq = NULL;
	if (!(tst = (int **)malloc(sizeof(int *) * 2)))
		return ;
	while (i < 12)
	{
		tst[0] = intcpy(stack[0], size[0]);
		tst[1] = intcpy(stack[1], size[1]);
		ts = intcpy(size, 2);
		if (!(i = sequence(i, &seq)))
			return ;
		j = -1;
		while (++j < i)
			applyrule(tst, &size, rules[seq[j]]);
		if (ts[1] == 0 && issort(tst[0], ts[0]))
			return (print_rules(rules, seq));
		free(tst[0]);
		free(tst[1]);
		free(ts);
	}
}

int 	main(int ac, char **av)
{
	char	**rules;
	int		**stack;
	int		*size;

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
	if (!(rules = rules_m()))
		return (0);
	push_swap(stack, size, rules);
	return (0);
}
