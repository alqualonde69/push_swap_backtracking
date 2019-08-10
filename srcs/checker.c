/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 13:26:51 by shunt             #+#    #+#             */
/*   Updated: 2019/08/10 13:27:02 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		*itoa_stack(char **av, int **stack)
{
	int		i;
	int		j;

	i = 0;
	while (av[++i])
	{
		j = -1;
		while (av[i][++j])
			if (av[i][j] < '0' || av[i][j] > '9')
				return (NULL);
	}
	i = 0;
	while (av[++i])
		(*stack)[i - 1] = ft_itoa(av[i]);
}

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

void	appl

int		main(int ac, char **av)
{
	char	buf;
	char	*rule;
	int		*a;
	int		*b;

	if (ac == 1)
		return (0);
	if (!(a = itoa_stack(av)))
		return (error());
	while ((read(1, buf, 1)))
	{
		if (buf && buf != '\n')
		{
			if (!(rule = charjoin(rule, buf)))
				return (0);
		}
		else if (buf == '\n')
			applyrule(stack, ac - 1, rule);
	}
	if (issort(stack, ac - 1))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}