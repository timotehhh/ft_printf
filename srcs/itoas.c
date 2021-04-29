/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouger <trouger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 19:04:54 by trouger           #+#    #+#             */
/*   Updated: 2021/04/29 08:34:01 by trouger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int				ft_find_size(unsigned int nb)
{
	int i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char			*ft_uitoa(unsigned int nb)
{
	char	*nbr;
	int		i;

	i = ft_find_size(nb);
	nbr = malloc(sizeof(char) * (i + 1));
	if (nbr == NULL)
		return (NULL);
	nbr[i] = '\0';
	i--;
	while (i >= 0)
	{
		nbr[i] = nb % 10 + 48;
		nb = nb / 10;
		i--;
	}
	return (nbr);
}

unsigned int	ft_uatoi(char *nbr)
{
	unsigned int	nb;
	int				i;

	nb = 0;
	i = 0;
	while (nbr[i])
	{
		nb = nb * 10 + (nbr[i] - 48);
		i++;
	}
	return (nb);
}
