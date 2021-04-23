/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouger <trouger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 12:56:47 by trouger           #+#    #+#             */
/*   Updated: 2021/04/23 18:24:34 by trouger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIB_H
# define FT_LIB_H

# include "libft/libft.h"
# include <stdarg.h>

typedef struct		s_infos
{
	int				zero;
	int				minus;
	int				point;
	int				zeros;
	int				printchar;
	int				spaces;
	int				i;
	char			flag;
	char			*str;
	char			*str_toprint;
}					t_infos;

void		ft_sort(va_list arg, t_infos tab);
void		ft_nbsort(va_list arg, t_infos tab);
void		ft_nbend(va_list arg, t_infos tab, int nb, int nbrlen);
void		ft_sort_result(va_list arg, t_infos tab);

#endif
