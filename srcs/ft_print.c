/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouger <trouger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 16:34:47 by trouger           #+#    #+#             */
/*   Updated: 2021/04/30 21:35:58 by trouger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_print_c(va_list arg, t_infos tab)
{
	char	c;

	if (*(tab.flag) == 'c')
		c = va_arg(arg, int);
	else
		c = '%';
	if (tab.minus)
	{
		*(tab.i) = *(tab.i) + 1;
		ft_putchar_fd(c, 1, tab);
	}
	ft_print_c2(c, tab);
	if (!(tab.minus))
	{
		*(tab.i) = *(tab.i) + 1;
		ft_putchar_fd(c, 1, tab);
	}
}

void	ft_print_c2(char c, t_infos tab)
{
	while (tab.spaces > 1 || (tab.zeros > 1 && c == '%'))
	{
		if (tab.zeros > 1 && c == '%')
		{
			ft_putchar_fd('0', 1, tab);
			tab.zeros = tab.zeros - 1;
		}
		else
		{
			ft_putchar_fd(' ', 1, tab);
			tab.spaces = tab.spaces - 1;
		}
	}
}

void	ft_print_s(va_list arg, t_infos tab)
{
	tab.str_toprint = ft_strdup(va_arg(arg, char *));
	if (tab.spaces < 0)
	{
		tab.spaces = tab.spaces * (-1);
		tab.minus = 1;
	}
	if (tab.str_toprint == NULL)
		tab.str_toprint = ft_strdup("(null)");
	if (tab.point)
		tab.str_toprint[tab.printchar] = '\0';
	ft_print_s2(tab);
	free(tab.str_toprint);
}

void	ft_print_s2(t_infos tab)
{
	if (tab.minus)
	{
		*(tab.i) = *(tab.i) + 1;
		ft_putstr_fd(tab.str_toprint, 1, tab);
	}
	while (tab.spaces > ft_strlen(tab.str_toprint))
	{
		ft_putchar_fd(' ', 1, tab);
		tab.spaces = tab.spaces - 1;
	}
	if (!(tab.minus))
	{
		*(tab.i) = *(tab.i) + 1;
		ft_putstr_fd(tab.str_toprint, 1, tab);
	}
}

void	ft_print_int(va_list arg, t_infos tab)
{
	char	*nb;

	nb = ft_initialize_print(arg, tab);
	if (tab.spaces < 0 || tab.zeros < 0)
	{
		if (tab.zeros < 0)
			tab.spaces = tab.zeros;
		tab.spaces = tab.spaces * (-1);
		tab.minus = 1;
	}
	if (tab.point && !(tab.printchar) && nb[0] == '0')
		ft_print_int6(nb, tab);
	if (tab.zero && (tab.minus || tab.point) && !(tab.spaces))
		tab.spaces = tab.zeros;
	if (tab.minus && !(tab.point))
		ft_print_int5(nb, tab);
	else if (tab.point)
		ft_print_int2(tab, nb);
	else
		ft_print_int3(tab, nb);
	*(tab.i) += 1;
	free(nb);
}
