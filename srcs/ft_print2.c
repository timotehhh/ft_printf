/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouger <trouger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 20:32:17 by trouger           #+#    #+#             */
/*   Updated: 2021/04/29 10:20:08 by trouger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*ft_initialize_print(va_list arg, t_infos tab)
{
	char			*nb;
	unsigned long	un;
	int				n;

	n = 0;
	nb = NULL;
	if (*(tab.flag) == 'd' || *(tab.flag) == 'i')
	{
		if ((n = va_arg(arg, int)) < 0)
		{
			*(tab.neg) = 1;
			if (n != -2147483648)
				n = n * (-1);
			else
			{
				nb = ft_itoa(n, 1);
			}
		}
	}
	if (*(tab.flag) == 'p' || *(tab.flag) == 'x' || *(tab.flag) == 'X')
		un = va_arg(arg, unsigned long);
	if ((*(tab.flag) == 'd' || *(tab.flag) == 'i') && nb == NULL)
		nb = ft_itoa(n, 0);
	else if (*(tab.flag) == 'x')
		nb = ft_convert_base(un, "0123456789abcdef", tab);
	else if (*(tab.flag) == 'X')
		nb = ft_convert_base(un, "0123456789ABCDEF", tab);
	else if (*(tab.flag) == 'u')
		nb = ft_uitoa(va_arg(arg, unsigned int));
	else if (*(tab.flag) == 'p')
		nb = ft_convert_base(un, "0123456789abcdef", tab);
	return (nb);
}

void	ft_print_int3(t_infos tab, char *nb)
{
	if (tab.zero && !(tab.point) && !(tab.minus))
	{
		if (*(tab.neg))
			ft_putchar_fd('-', 1);
		while (tab.zeros > (ft_strlen(nb) + *(tab.neg)))
		{
			ft_putchar_fd('0', 1);
			tab.zeros = tab.zeros - 1;
		}
		ft_putstr_fd(nb, 1);
	}
	else if (tab.spaces > ft_strlen(nb) && !(tab.minus) && !(tab.point))
	{
		while (tab.spaces > (ft_strlen(nb) + *(tab.neg)))
		{
			ft_putchar_fd(' ', 1);
			tab.spaces = tab.spaces - 1;
		}
		if (*(tab.neg))
			ft_putchar_fd('-', 1);
		ft_putstr_fd(nb, 1);
	}
	else
	{
		if (*(tab.neg))
			ft_putchar_fd('-', 1);
		ft_putstr_fd(nb, 1);
	}
}

void	ft_print_int4(t_infos tab, char *nb)
{
	if ((ft_strlen(nb) + *(tab.neg)) < tab.printchar)
		tab.spaces = tab.spaces - tab.printchar - *(tab.neg);
	else
		tab.spaces = tab.spaces - ft_strlen(nb) - *(tab.neg);
	while (tab.spaces > 0)
	{
		ft_putchar_fd(' ', 1);
		tab.spaces = tab.spaces - 1;
	}
	if (*(tab.neg))
		ft_putchar_fd('-', 1);
	while (tab.printchar > ft_strlen(nb))
	{
		ft_putchar_fd('0', 1);
		tab.printchar = tab.printchar - 1;
	}
	ft_putstr_fd(nb, 1);
}
