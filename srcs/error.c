/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 21:35:10 by shunt             #+#    #+#             */
/*   Updated: 2019/08/13 21:35:12 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		error(void)
{
	write(1, "Error\n", 6);
	return (0);
}
