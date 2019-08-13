/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 21:44:40 by shunt             #+#    #+#             */
/*   Updated: 2019/08/13 21:44:42 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include "libft.h"
# include "ft_printf.h"
# include <stdio.h>

void	applyrule(int **stack, int **size, char **rule);
char	*charjoin(char **rule, char buf);
int		error(void);
int		issort(int *stack, int size);
int		*atoi_stack(char **av);
void	push(int **stack, int **size, int o);
void	rotate(int **stack, int size, int dir);
void	swap(int **stack);

#endif
