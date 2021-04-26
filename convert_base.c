/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouger <trouger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 17:49:38 by trouger           #+#    #+#             */
/*   Updated: 2021/04/26 11:16:21 by trouger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include <stdio.h>

int		ft_find_len(unsigned long nb, char *base, t_infos tab)
{
	int i;

	i = 0;
	if (nb == 0)
		i = 1;
	while (nb)
	{
		nb = nb / ft_strlen(base);
		i++;
	}
	if (*(tab.flag) == 'p' && nb)
		i = i + 5;
	if (*(tab.flag) == 'p' && !(nb))
		i = i + 2;
	return (i);
}

int		ft_fill_p(unsigned long nb, char *result)
{
	if (nb)
	{
		result[0] = '0';
		result[1] = 'x';
		result[2] = '7';
		result[3] = 'f';
		result[4] = 'f';
		return (5);
	}
	result[0] = '0';
	result[1] = 'x';
	return (2);
}

char	*ft_convert_base(unsigned long nb, char *base, t_infos tab)
{
	int		i;
	int		stop;
	char	*result;

	stop = 0;
	i = ft_find_len(nb, base, tab);
	result = malloc(sizeof(char) * (i + 1));
	if (result == NULL)
		return (NULL);
	result[i] = '\0';
	if (*(tab.flag) == 'p')
		stop = ft_fill_p(nb, result);
	while (--i >= stop)
	{
		result[i] = base[nb % ft_strlen(base)];
		nb = nb / ft_strlen(base);
	}
	return (result);
}
