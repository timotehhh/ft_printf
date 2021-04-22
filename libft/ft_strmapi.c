/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouger <trouger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 11:07:08 by trouger           #+#    #+#             */
/*   Updated: 2021/03/23 11:39:51 by trouger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	size;
	char			*result;

	if (str == NULL)
		return (NULL);
	i = 0;
	size = ft_strlen(str);
	if (!(result = malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (i < size)
	{
		result[i] = f(i, str[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
