/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouger <trouger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 10:10:11 by trouger           #+#    #+#             */
/*   Updated: 2021/04/23 21:42:53 by trouger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include <stdio.h>

void	ft_parcour(va_list arg, t_infos tab)
{
	while (tab.str[tab.i])
	{
		printf("\ntab.i = %d\n", tab.i);
		if (tab.str[tab.i] == '%')
		{
			tab.i = tab.i + 1;	
			ft_sort(arg, tab);
			tab.i = tab.i + 1;	
		}
		else
		{
//			printf("tab.str[tab.i] = %c\n", tab.str[tab.i]);
			ft_putchar_fd(tab.str[tab.i], 1);
			tab.i = tab.i + 1;	
		}
	}
}

t_infos	ft_initialize(void)
{
	t_infos	tab;

	tab.zero = 0;
	tab.zeros = 0;
	tab.minus = 0;
	tab.point = 0;
	tab.printchar = 0;
	tab.spaces = 0;
	tab.i = 0;
	tab.i_toprint = 0;
	tab.flag = 0;
	tab.str = NULL;
	tab.str_toprint = NULL;
	return (tab);
}

int		ft_printf(const char *format, ...)
{
	va_list	arg;
	t_infos	tab;

	tab = ft_initialize();
	tab.str = ft_strdup(format);
	va_start(arg, format);
	ft_parcour(arg, tab);
	va_end(arg);
	return (1);
}

int main()
{
	ft_printf("%5consoir\n", 'B');
	return (0);
}
