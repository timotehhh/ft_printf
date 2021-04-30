
#include "./include/ft_printf.h"

int main()
{
	int a = 2;

	printf("%-10.5p-\n", &a);
	printf("%10.5p-\n", &a);
	printf("%05p-\n", &a);
	return (0);
}
