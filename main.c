
#include "./include/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main()
{
	ft_printf(" *%-0*.10d* *%-0*.0d*\n", 21, 1021, 21, -1011);
	printf(" *%-0*.10d* *%-0*.0d*\n", 21, 1021, 21, -1011);
	return (0);
}
