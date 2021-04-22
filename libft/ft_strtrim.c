/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouger <trouger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 11:07:36 by trouger           #+#    #+#             */
/*   Updated: 2021/03/24 10:51:37 by trouger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_charset(char c, char const *set)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_find_len(char const *s1, char const *set)
{
	int i;
	int count;

	count = ft_strlen(s1);
	i = 0;
	while (count > 0 && ft_is_charset(s1[count - 1], set))
		count--;
	while (s1[i] && ft_is_charset(s1[i], set) && count > 0)
	{
		count--;
		i++;
	}
	return (count);
}

static int	ft_find_start(char const *s, char const *set)
{
	int i;

	i = 0;
	while (ft_is_charset(s[i], set) && s[i])
		i++;
	return (i);
}

char		*ft_strtrim(char const *s, char const *set)
{
	char	*result;

	if (s == NULL || set == NULL)
		return (NULL);
	if ((result = ft_substr(s, ft_find_start(s, set), ft_find_len(s, set)))
			== NULL)
		return (NULL);
	return (result);
}
