/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouger <trouger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 16:34:47 by trouger           #+#    #+#             */
/*   Updated: 2021/04/24 16:51:15 by trouger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include <stdio.h>

void	ft_print_c(va_list arg, t_infos tab)
{
	if (*(tab.flag) == 'c')
	{
		if (tab.minus)
		{
			*(tab.i) = *(tab.i) + 1;
			ft_putchar_fd(va_arg(arg, int), 1);
		}
		while (tab.spaces > 1)
		{
			ft_putchar_fd(' ', 1);
			tab.spaces = tab.spaces - 1;
		}
		if (!(tab.minus))
		{
			*(tab.i) = *(tab.i) + 1;
			ft_putchar_fd(va_arg(arg, int), 1);
		}
	}
}
