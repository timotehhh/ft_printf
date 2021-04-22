/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouger <trouger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 11:05:25 by trouger           #+#    #+#             */
/*   Updated: 2021/03/23 11:05:26 by trouger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*tab_dest;
	unsigned char		*tab_src;

	i = 0;
	tab_dest = (unsigned char *)dest;
	tab_src = (unsigned char *)src;
	while (i < n && (dest || src))
	{
		tab_dest[i] = tab_src[i];
		i++;
	}
	return (dest);
}
