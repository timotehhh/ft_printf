/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouger <trouger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 11:06:47 by trouger           #+#    #+#             */
/*   Updated: 2021/03/23 11:43:01 by trouger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t len)
{
	size_t	i;

	if (dest == NULL || src == NULL)
		return (0);
	i = 0;
	if (len == 0 || src[0] == '\0')
	{
		if (src[0] == '\0')
			dest[0] = '\0';
		return (ft_strlen(src));
	}
	while (i + 1 < len && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}
