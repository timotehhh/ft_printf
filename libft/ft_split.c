/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouger <trouger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 11:06:07 by trouger           #+#    #+#             */
/*   Updated: 2021/03/23 11:38:06 by trouger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_fill_words(char c, const char *str, int place, char *res)
{
	int i;
	int count;
	int j;

	j = 0;
	i = 0;
	count = (-1);
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] && str[i] != c)
		{
			count++;
			while (str[i] && count == place && str[i] != c)
			{
				res[j] = str[i];
				i++;
				j++;
			}
			while (str[i] && str[i] != c)
				i++;
		}
	}
	res[j] = '\0';
}

static int	ft_count_letrs(char c, const char *str, int place)
{
	int i;
	int count;
	int size;

	i = 0;
	count = (-1);
	size = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] && str[i] != c)
		{
			count++;
			while (str[i] && count == place && str[i] != c)
			{
				i++;
				size++;
			}
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (size);
}

static int	ft_count_words(char c, const char *str)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] && str[i] != c)
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}

char		**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		nb_words;
	int		letters;

	if (s == NULL)
		return (NULL);
	nb_words = ft_count_words(c, s);
	if (!(res = malloc(sizeof(char *) * (nb_words + 1))))
		return (NULL);
	i = 0;
	while (i < nb_words)
	{
		letters = ft_count_letrs(c, s, i);
		if (!(res[i] = malloc(sizeof(char) * (letters + 1))))
			return (NULL);
		ft_fill_words(c, s, i, res[i]);
		i++;
	}
	res[nb_words] = NULL;
	return (res);
}
