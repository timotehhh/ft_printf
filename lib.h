/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouger <trouger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 12:56:47 by trouger           #+#    #+#             */
/*   Updated: 2021/04/24 15:58:14 by trouger          ###   ########.fr       */
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
	int				null;
	int				*i;
	int				i_toprint;
	char			*flag;
	char			*str;
	char			*str_toprint;
}					t_infos;

int				ft_printf(const char *format, ...);
t_infos			ft_initialize(void);
void			ft_parcour(va_list arg, t_infos tab);
unsigned int	ft_uatoi(char *nbr);
void			ft_c_s(va_list arg, t_infos tab);
void			ft_sort(va_list arg, t_infos tab);
void			ft_nbsort(va_list arg, t_infos tab);
void			ft_nbend(va_list arg, t_infos tab, int nb, int nbrlen);
void			ft_sort_result(va_list arg, t_infos tab);

#endif
