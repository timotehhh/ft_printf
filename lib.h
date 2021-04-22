/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouger <trouger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 12:56:47 by trouger           #+#    #+#             */
/*   Updated: 2021/04/22 12:12:47 by trouger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIB_H
# define FT_LIB_H

# include "libft/libft.h"
# include <stdarg.h>

typedef struct		s_infos
{
	char			specifier;
	int				intvalue;
	unsigned int	u_intvalue;
	char			*str_or_charvalue;
}					t_infos;

#endif
