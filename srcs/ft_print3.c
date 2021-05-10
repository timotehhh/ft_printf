/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouger <trouger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 16:34:47 by trouger           #+#    #+#             */
/*   Updated: 2021/05/10 18:47:09 by trouger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_print_int6(char *nb, t_infos tab)
{
	if (*(tab.flag) == 'p' && nb[2] == '0')
		nb[2] = '\0';
	else
		nb[0] = '\0';
}

void	ft_print_int5(char *nb, t_infos tab)
{
	if (*(tab.neg))
		ft_putchar_fd('-', 1, tab);
	ft_putstr_fd(nb, 1, tab);
	while (tab.spaces > (ft_strlen(nb) + *(tab.neg)))
	{
		ft_putchar_fd(' ', 1, tab);
		tab.spaces = tab.spaces - 1;
	}
}

void	ft_print_int2(t_infos tab, char *nb)
{
	if (tab.minus)
	{
		if ((ft_strlen(nb) + *(tab.neg)) <= tab.printchar)
			tab.spaces = tab.spaces - tab.printchar - *(tab.neg);
		else
			tab.spaces = tab.spaces - ft_strlen(nb) - *(tab.neg);
		if (*(tab.neg))
			ft_putchar_fd('-', 1, tab);
		while (tab.printchar > ft_strlen(nb))
		{
			ft_putchar_fd('0', 1, tab);
			tab.printchar = tab.printchar - 1;
		}
		ft_putstr_fd(nb, 1, tab);
		while (tab.spaces > 0)
		{
			ft_putchar_fd(' ', 1, tab);
			tab.spaces = tab.spaces - 1;
		}
	}
	else
		ft_print_int4(tab, nb);
}

t_infos	ft_print_int7(t_infos tab)
{
	if (tab.spaces < 0 || tab.zeros < 0)
	{
		if (tab.zeros < 0)
			tab.spaces = tab.zeros;
		tab.spaces = tab.spaces * (-1);
		tab.minus = 1;
	}
	if (tab.zeros > 0 && tab.minus && tab.spaces == 0 && tab.printchar >= 0)
		tab.spaces = tab.zeros;
	//continuer de copier le début de ft_print_int
}
