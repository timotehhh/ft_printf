/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouger <trouger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 12:56:47 by trouger           #+#    #+#             */
/*   Updated: 2021/04/30 21:39:08 by trouger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct		s_infos
{
	int				*neg;
	int				zero;
	int				minus;
	int				point;
	int				zeros;
	int				printchar;
	int				spaces;
	int				null;
	int				*i;
	int				*retvalue;
	int				i_toprint;
	char			*flag;
	char			*str;
	char			*str_toprint;
}					t_infos;

char				*ft_itoa(int n, int m);
int					ft_isdigit(int c);
void				ft_putchar_fd(char c, int fd, t_infos tab);
void				ft_putstr_fd(char *s, int fd, t_infos tab);
int					ft_strlen(const char *str);
char				*ft_strdup(const char *s);
int					ft_printf(const char *format, ...);
t_infos				ft_initialize(void);
void				ft_parcour(va_list arg, t_infos tab);
unsigned int		ft_uatoi(char *nbr);
void				ft_print_int(va_list arg, t_infos tab);
void				ft_print_int2(t_infos tab, char *nb);
void				ft_print_s(va_list arg, t_infos tab);
void				ft_print_c(va_list arg, t_infos tab);
void				ft_sort(va_list arg, t_infos tab);
void				ft_nbsort(va_list arg, t_infos tab, int j);
void				ft_nbend(va_list arg, t_infos tab, int nb, int nbrlen);
void				ft_sort_result(va_list arg, t_infos tab);
char				*ft_uitoa(unsigned int nb);
char				*ft_convert_base(unsigned long nb, char *base, t_infos tab);
int					ft_find_len(unsigned long nb, char *base, t_infos tab);
int					ft_fill_p(char *result);
char				*ft_initialize_print(va_list arg, t_infos tab);
char				*ip2(va_list arg, char *nb, unsigned long un, t_infos tab);
void				ft_print_int3(t_infos tab, char *nb);
void				ft_print_int4(t_infos tab, char *nb);
void				ft_print_int5(char *nb, t_infos tab);
void				ft_print_int6(char *nb, t_infos tab);
void				ft_print_int7(t_infos tab, char *nb);
void				ft_print_s2(t_infos tab);
void				ft_print_c2(char c, t_infos tab);

#endif
