/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouger <trouger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 17:49:38 by trouger           #+#    #+#             */
/*   Updated: 2021/05/05 17:28:49 by trouger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

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

int		ft_fill_p(char *result)
{
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
		stop = ft_fill_p(result);
//	if (*(tab.flag) == 'p' && tab.point && !(tab.printchar))
//		return (result);
	while (--i >= stop)
	{
		result[i] = base[nb % ft_strlen(base)];
		nb = nb / ft_strlen(base);
	}
	return (result);
}
