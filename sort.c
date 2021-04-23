/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouger <trouger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 17:14:46 by trouger           #+#    #+#             */
/*   Updated: 2021/04/23 21:37:17 by trouger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "lib.h"

//
//
//ft_sort sert a trier les caracteres qui suivent le % pour trouver toutes 
//les infos dont on a besoin pour print la bonne chose selon le %
//ft_sort est la base de la centrale de tri, on y arrive dés qu'on rencontre
//un % et on y repasse a chaque fois qu'un flag est traité
//
void	ft_sort(va_list arg, t_infos tab)
{
	if (ft_isdigit(tab.str[tab.i]))
		ft_nbsort(arg, tab);
	else if (tab.str[tab.i] == '0' || tab.str[tab.i] == '.'
			|| tab.str[tab.i] == '*' || tab.str[tab.i] == '-')
	{
		tab.i = tab.i + 1;
		if (tab.str[tab.i] == '.')
			tab.point = 1;
		else if (tab.str[tab.i] == '0')
			tab.zero = 1;
		else if (tab.str[tab.i] == '-')
			tab.minus = 1;
		ft_nbsort(arg, tab);
	}
	else if ((tab.str[tab.i] == 'p' || tab.str[tab.i] == 'd'
			|| tab.str[tab.i] == 'c' || tab.str[tab.i] == 'X'
			|| tab.str[tab.i] == 'x' || tab.str[tab.i] == 's'
			|| tab.str[tab.i] == '%' || tab.str[tab.i] == 'u'
			|| tab.str[tab.i] == 'i') && tab.flag == 0)
	{
		tab.flag = tab.str[tab.i];
		ft_sort_result(arg, tab);
	}
}

//
//
//
//ft_nbsort sert a gérer quand on va rencontrer un nombre, qu'il désigne un
//nombre d'espace ou autre chose, on le fait passer par ft_nbsort afin de
//transformer ce nombre donné sous forme de string en int
//une fois ce nombre géré on l'envoie a ft_nbend pour déterminer quelle est
//son utilité
//
void	ft_nbsort(va_list arg, t_infos tab)
{
	char			*nbr;
	unsigned int	nb;
	int				i;

	i = tab.i;
	if (tab.str[tab.i] == '*')
		ft_nbend(arg, tab, va_arg(arg, int), 0);
	while (ft_isdigit(tab.str[i]))
		i++;
	nbr = malloc(sizeof(char) * (i + 1));
	if (nbr == NULL)
		return ;
	i = 0;
	while (ft_isdigit(tab.str[tab.i]))
	{
		nbr[i] = tab.str[tab.i];
		printf("passe tab.i = %d\n", tab.i);
		tab.i = tab.i + 1;
		i++;
	}
	nbr[i] = '\0';
	nb = ft_uatoi(nbr);
	ft_nbend(arg, tab, nb, ft_strlen(nbr));
}

//
//
//
//ft_nbend va déterminer, selon le caractère qui précède le nombre qu'on
//vient de traiter, a quoi sert ce nombre et enregistrer ce a quoi il sert
//dans le structure tab
//puis il va retourner dans ft_sort afin de continuer a traiter les flags
//du % rencontré
//
void	ft_nbend(va_list arg, t_infos tab, int nb, int nbrlen)
{
	if (tab.str[tab.i] == '*')
		nb = va_arg(arg, unsigned int);
	if (tab.str[tab.i - (nbrlen + 1)] == '%'
			|| tab.str[tab.i - (nbrlen + 1)] == '-' )
	{
		printf("passe tab.i = %d\n", tab.i);
		tab.spaces = nb;
	}
	else if (tab.str[tab.i - (nbrlen + 1)] == '.')
	{
		tab.i = tab.i + 1;
		tab.printchar = nb;
	}
	else if (tab.str[tab.i - (nbrlen + 1)] == '0')
	{
		tab.i = tab.i + 1;
		tab.zeros = nb;
	}
	ft_sort(arg, tab);
}

//
//
//
//
//ft_sort_result sert a orienter notre chemin selon le dernier flag du %
//pour chaque possibilité il va nous orienter vers la fonction qui permettra
//de print le resultat
//
void	ft_sort_result(va_list arg, t_infos tab)
{
	if (tab.str[tab.i] == 'c' || tab.str[tab.i] == 's') 
		ft_c_s(arg, tab);
//	else if (tab.str[tab.i] == 'd' || tab.str[tab.i] == 'u'
//			|| tab.str[tab.i] == 'i' || tab.str[tab.i] == 'x'
//			|| tab.str[tab.i] == 'X')
//		ft_d_u_i_x_X(va_arg(arg, int), tab);
	if(tab.str[tab.i] == '%')
	{
		tab.i = tab.i + 1;
		ft_putchar_fd('%', 1);
	}
}

void	ft_c_s(va_list arg, t_infos tab)
{
	if (tab.flag == 'c')
	{
		if (tab.minus)
		{
			tab.i = tab.i + 1;
			ft_putchar_fd(va_arg(arg, int), 1);
		}
		while (tab.spaces > 1)
		{
			ft_putchar_fd(' ', 1);
			tab.spaces = tab.spaces - 1; 
		}
		if (!(tab.minus))
		{
			tab.i = tab.i + 1;
			printf("PASSE tab.i = %d, tab.str[tab.i] = %c\n", tab.i, tab.str[tab.i]);
			ft_putchar_fd(va_arg(arg, int), 1);
		}
		ft_parcour(arg, tab);
	}
}