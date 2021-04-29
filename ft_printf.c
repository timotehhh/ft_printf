/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouger <trouger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 10:10:11 by trouger           #+#    #+#             */
/*   Updated: 2021/04/29 11:30:03 by trouger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/ft_printf.h"

void	ft_parcour(va_list arg, t_infos tab)
{
	while (tab.str[*(tab.i)])
	{
		if (tab.str[*(tab.i)] == '%')
		{
			*(tab.i) = *(tab.i) + 1;
			ft_sort(arg, tab);
			*(tab.flag) = 'w';
		}
		else
		{
			ft_putchar_fd(tab.str[*(tab.i)], 1, tab);
			*(tab.i) = *(tab.i) + 1;
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
	tab.null = 0;
	tab.printchar = 0;
	tab.spaces = 0;
	tab.i = malloc(sizeof(int) * 1);
	if (tab.i == NULL)
		tab.null = 1;
	*(tab.i) = 0;
	tab.i_toprint = 0;
	tab.neg = malloc(sizeof(int) * 1);
	if (tab.neg == NULL)
		tab.null = 1;
	*(tab.neg) = 0;
	tab.flag = malloc(sizeof(char) * 1);
	if (tab.flag == NULL)
		tab.null = 1;
	*(tab.flag) = 'w';
	tab.retvalue = malloc(sizeof(int) * 1);
	if (tab.retvalue == NULL)
		tab.null = 1;
	*(tab.retvalue) = 0;
	tab.str = NULL;
	tab.str_toprint = NULL;
	return (tab);
}

int		ft_printf(const char *format, ...)
{
	va_list	arg;
	t_infos	tab;
	int		i;

	tab = ft_initialize();
	tab.str = ft_strdup(format);
	if (tab.null)
		return (0);
	va_start(arg, format);
	ft_parcour(arg, tab);
	va_end(arg);
	i = *(tab.retvalue);
	free(tab.i);
	free(tab.flag);
	free(tab.str);
	free(tab.str_toprint);
	return (i);
}
