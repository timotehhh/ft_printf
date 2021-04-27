/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouger <trouger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 11:06:18 by trouger           #+#    #+#             */
/*   Updated: 2021/04/27 21:43:47 by trouger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*ft_strdup(const char *s)
{
	char	*result;
	int		i;
	int		size;

	size = ft_strlen(s);
	i = 0;
	if (!(result = malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (s[i])
	{
		result[i] = s[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
