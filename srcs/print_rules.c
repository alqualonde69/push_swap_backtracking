/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_rules.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 17:29:22 by shunt             #+#    #+#             */
/*   Updated: 2019/08/14 17:29:23 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_rules(char **rules, char *seq, int fd)
{
	int 	j;

	j = -1;
	while (seq[++j])
	{
		fd != -1 ? write(fd, rules[seq[j] - 48], ft_strlen(rules[seq[j] - 48])) : ft_putstr(rules[seq[j] - 48]);
		fd != -1 ? write(fd, "\n", 1) : write(1, "\n", 1);
	}
}