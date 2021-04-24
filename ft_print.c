/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouger <trouger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 16:34:47 by trouger           #+#    #+#             */
/*   Updated: 2021/04/24 18:48:43 by trouger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include <stdio.h>

void	ft_print_c(va_list arg, t_infos tab)
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

void	ft_print_s(va_list arg, t_infos tab)
{
	tab.str_toprint = ft_strdup(va_arg(arg, char *));
	if (tab.point)
	{
		tab.str_toprint[tab.printchar] = '\0';
	}
	if (tab.minus)
	{
		*(tab.i) = *(tab.i) + 1;
		ft_putstr_fd(tab.str_toprint, 1);
	}
	while (tab.spaces > ft_strlen(tab.str_toprint))
	{
		ft_putchar_fd(' ', 1);
		tab.spaces = tab.spaces - 1;
	}
	if (!(tab.minus))
	{
		*(tab.i) = *(tab.i) + 1;
		ft_putstr_fd(tab.str_toprint, 1);
	}
}

void	ft_print_d(va_list arg, t_infos tab)
{
	char	*nb;

	nb = ft_itoa(va_arg(arg, int));
	if (tab.minus)
	{
		*(tab.i) = *(tab.i) + 1;
		ft_putstr_fd(nb, 1);
	}
	if (tab.spaces > ft_strlen(nb))
	{
		while (tab.spaces > ft_strlen(nb))
		{
			ft_putchar_fd(' ', 1);
			tab.spaces = tab.spaces - 1;
		}
	}
	else if (tab.zeros > ft_strlen(nb) && tab.minus == 0 && tab.point == 0)
	{
		while (tab.zeros > ft_strlen(nb))
		{
			ft_putchar_fd('0', 1);
			tab.zeros = tab.zeros - 1;
		}
	}
	if (!(tab.minus))
	{
		*(tab.i) = *(tab.i) + 1;
		ft_putstr_fd(nb, 1);
	}
}
