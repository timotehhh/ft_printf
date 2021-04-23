/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouger <trouger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 19:04:54 by trouger           #+#    #+#             */
/*   Updated: 2021/04/23 19:22:09 by trouger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

unsigned int	ft_uitoa(char *nbr)
{
	unsigned int	nb;
	int				i;

	i = -1;
	nb = 0;
	while (nbr[++i])
		nb = nb * 10 + (nbr[i] - '0');
	return (nb);
}

int				ft_itoa(char *nbr)
{
	int	i;
	int	nb;
	int	sign;

	i = -1;
	nb = 0;
	sign = 1;
	if (nbr[++i] == '-')
		sign = sign * (-1);
	while (nbr[++i])
		nb = nb * 10 + (nbr[i] - '0');
	return (nb * sign);
}
