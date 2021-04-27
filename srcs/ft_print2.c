/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouger <trouger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 20:32:17 by trouger           #+#    #+#             */
/*   Updated: 2021/04/27 15:19:46 by trouger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libftprintf.h"

char	*ft_initialize_print(va_list arg, t_infos tab)
{
	char			*nb;
	unsigned long	n;

	n = 0;
	if (*(tab.flag) == 'd' || *(tab.flag) == 'i')
		nb = ft_itoa(va_arg(arg, int));
	else if (*(tab.flag) == 'x')
		nb = ft_convert_base(va_arg(arg, int), "0123456789abcdef", tab);
	else if (*(tab.flag) == 'X')
		nb = ft_convert_base(va_arg(arg, int), "0123456789ABCDEF", tab);
	else if (*(tab.flag) == 'u')
		nb = ft_uitoa(va_arg(arg, unsigned int));
	else
	{
		n = (unsigned long)va_arg(arg, void *);
		nb = ft_convert_base(n, "0123456789abcdef", tab);
	}
	return (nb);
}

void	ft_print_int3(t_infos tab, char *nb)
{
	if (tab.zeros && !(tab.point) && !(tab.point))
	{
		while (tab.zeros > ft_strlen(nb))
		{
			ft_putchar_fd('0', 1);
			tab.zeros = tab.zeros - 1;
		}
		ft_putstr_fd(nb, 1);
	}
	else if (tab.spaces > ft_strlen(nb) && !(tab.minus) && !(tab.point))
	{
		while (tab.spaces > ft_strlen(nb))
		{
			ft_putchar_fd(' ', 1);
			tab.spaces = tab.spaces - 1;
		}
		ft_putstr_fd(nb, 1);
	}
	else
		ft_putstr_fd(nb, 1);
}

void	ft_print_int4(t_infos tab, char *nb)
{
	tab.spaces = tab.spaces - tab.printchar;
	while (tab.spaces > 0)
	{
		ft_putchar_fd(' ', 1);
		tab.spaces = tab.spaces - 1;
	}
	while (tab.printchar > ft_strlen(nb))
	{
		ft_putchar_fd('0', 1);
		tab.printchar = tab.printchar - 1;
	}
	ft_putstr_fd(nb, 1);
}
