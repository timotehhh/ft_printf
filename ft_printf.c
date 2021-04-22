/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouger <trouger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 10:10:11 by trouger           #+#    #+#             */
/*   Updated: 2021/04/22 12:55:47 by trouger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdarg.h>
#include <stdio.h>

void	(va_list arg, char *str, int i)
{
}

void	ft_sort(va_list arg, t_infos tab)
{
	
}

void	ft_parcour(va_list arg, t_infos tab)
{
	while (str[tab.i])
	{
		if (str[tab.i] == '%')
		{
			ft_sort(arg, str, i);
			tab->i = tab->i + 1;	
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			tab->i = tab->i + 1;	
		}
	}
}

int		ft_printf(const char *format, ...)
{
	va_list	arg;
	t_infos	tab;

	tab->str = ft_strdup(format);
	va_start(arg, format);
	ft_parcour(arg, tab);
	va_end(arg);
	return (1);
}

int main()
{
	ft_printf("Bonsoir %% % %", "toi\n", "tu", "vas", "bien ?\n");
	return (0);
}
