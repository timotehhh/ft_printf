
#include "./include/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main()
{
	ft_printf(" *%-*.*x* *%*.*x* \n", 6, 2, 102, 10, 21, -101);
	printf(" *%-*.*x* *%*.*x* \n", 6, 2, 102, 10, 21, -101);
	return (0);
}
