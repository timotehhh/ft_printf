
#include "./include/ft_printf.h"
#include <stdio.h>

int main()
{
	ft_printf(">>%.*s<<\n", -10, "abc");
	printf(">>%.*s<<\n", -10 , "abc");
	return (0);
}
