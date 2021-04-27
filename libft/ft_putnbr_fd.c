/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouger <trouger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 11:05:52 by trouger           #+#    #+#             */
/*   Updated: 2021/04/27 21:43:12 by trouger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;
	char	minus;

	nb = n;
	minus = '-';
	if (nb < 0)
	{
		nb = nb * (-1);
		write(fd, &minus, 1);
	}
	if (nb > 9)
		ft_putnbr_fd(nb / 10, fd);
	ft_putchar_fd(nb % 10 + 48, fd);
}
