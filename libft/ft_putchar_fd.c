/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouger <trouger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 11:05:42 by trouger           #+#    #+#             */
/*   Updated: 2021/04/29 11:26:07 by trouger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_putchar_fd(char c, int fd, t_infos tab)
{
	*(tab.retvalue) = *(tab.retvalue) + 1;
	write(fd, &c, 1);
}
