/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouger <trouger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 17:14:46 by trouger           #+#    #+#             */
/*   Updated: 2021/04/30 19:23:21 by trouger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_sort(va_list arg, t_infos tab)
{
	if (ft_isdigit(tab.str[*(tab.i)]) && tab.str[*(tab.i)] != '0')
		ft_nbsort(arg, tab);
	else if ((tab.str[*(tab.i)] == '0' || tab.str[*(tab.i)] == '.'
				|| tab.str[*(tab.i)] == '*' || tab.str[*(tab.i)] == '-')
			&& *(tab.flag) == 'w')
	{
		if (tab.str[*(tab.i)] == '.')
			tab.point = 1;
		else if (tab.str[*(tab.i)] == '0')
			tab.zero = 1;
		else if (tab.str[*(tab.i)] == '-')
			tab.minus = 1;
		*(tab.i) = *(tab.i) + 1;
		ft_nbsort(arg, tab);
	}
	else if ((tab.str[*(tab.i)] == 'p' || tab.str[*(tab.i)] == 'd'
			|| tab.str[*(tab.i)] == 'c' || tab.str[*(tab.i)] == 'X'
			|| tab.str[*(tab.i)] == 'x' || tab.str[*(tab.i)] == 's'
			|| tab.str[*(tab.i)] == '%' || tab.str[*(tab.i)] == 'u'
			|| tab.str[*(tab.i)] == 'i') && *(tab.flag) == 'w')
	{
		*(tab.flag) = tab.str[*(tab.i)];
		ft_sort_result(arg, tab);
	}
}

void	ft_nbsort(va_list arg, t_infos tab)
{
	char			*nbr;
	unsigned int	nb;
	int				i;

	i = *(tab.i);
	if (tab.str[*(tab.i) - 1] == '*')
		ft_nbend(arg, tab, va_arg(arg, int), 1);
	if (!(ft_isdigit(tab.str[*(tab.i)])))
		ft_sort(arg, tab);
	while (ft_isdigit(tab.str[i]))
		i++;
	nbr = malloc(sizeof(char) * (i + 1));
	if (nbr == NULL)
		return ;
	i = 0;
	while (ft_isdigit(tab.str[*(tab.i)]))
	{
		nbr[i] = tab.str[*(tab.i)];
		*(tab.i) = *(tab.i) + 1;
		i++;
	}
	nbr[i] = '\0';
	nb = ft_uatoi(nbr);
	i = ft_strlen(nbr);
	free(nbr);
	ft_nbend(arg, tab, nb, i);
}

void	ft_nbend(va_list arg, t_infos tab, int nb, int nbrlen)
{
	if (tab.str[*(tab.i) - (nbrlen + 1)] == '%'
			|| tab.str[*(tab.i) - (nbrlen + 1)] == '-')
		tab.spaces = nb;
	else if (tab.str[*(tab.i) - (nbrlen + 1)] == '.')
		tab.printchar = nb;
	else if (tab.str[*(tab.i) - (nbrlen + 1)] == '0')
		tab.zeros = nb;
	ft_sort(arg, tab);
}

void	ft_sort_result(va_list arg, t_infos tab)
{
	if (tab.str[*(tab.i)] == 'c' || tab.str[*(tab.i)] == '%')
		ft_print_c(arg, tab);
	else if (tab.str[*(tab.i)] == 's')
		ft_print_s(arg, tab);
	else if (tab.str[*(tab.i)] == 'd' || tab.str[*(tab.i)] == 'i'
			|| tab.str[*(tab.i)] == 'x' || tab.str[*(tab.i)] == 'X'
			|| tab.str[*(tab.i)] == 'u' || tab.str[*(tab.i)] == 'p')
		ft_print_int(arg, tab);
}
