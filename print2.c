#include "lib.h"
#include <stdio.h>

char	*ft_initialize_print(va_list arg, t_infos tab)
{
	char	*nb;
	int		n;

	n = 0;
	if (*(tab.flag) == 'd' || *(tab.flag) == 'i')
		nb = ft_itoa(va_arg(arg, int));
	else if (*(tab.flag) == 'x')
		nb = ft_convert_base(va_arg(arg, int), "0123456789abcdef", tab);
	else if (*(tab.flag) == 'X')
		nb = ft_convert_base(va_arg(arg, int), "0123456789ABCDEF", tab);
	else if (*(tab.flag) == 'u')
		nb = ft_uitoa(va_arg(arg, unsigned int));
	else if (*(tab.flag) == 'p')
	{
		n = (unsigned long)va_arg(arg, void *);
		nb = ft_convert_base(n, "0123456789abcdef");
	}
	return (nb);
}

void	ft_print_int3(va_list arg, t_infos tab)
{
	//ecrire la moitié de la fonction print_int dans cette fonction
}
