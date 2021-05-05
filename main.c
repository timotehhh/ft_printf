
#include "./include/ft_printf.h"
#include <stdio.h>

int main()
{
	int *p;
	int i;

	i = 9;
	p = NULL;
	ft_printf(">>%-10.p<<\n", p);
	printf(">>%-10.p<<\n", p);
	return (0);
}
