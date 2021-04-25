/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouger </var/mail/trouger>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 17:49:38 by trouger           #+#    #+#             */
/*   Updated: 2021/04/25 18:27:45 by trouger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include <stdio.h>

int		ft_find_len(int nb, char *base)
{
	int i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb = nb / ft_strlen(base);
		i++;
	}
	return (i);
}

char	*ft_convert_base(int nb, char *base)
{
	int		i;
	char	*result;

	i = ft_find_len(nb, base);
	result = malloc(sizeof(char) * (i + 1));
	if (result == NULL)
		return (NULL);
	result[i] = '\0';
	while (--i >= 0)
	{
		result[i] = base[nb % ft_strlen(base)];
		nb = nb / ft_strlen(base);
	}
	return (result);
}
