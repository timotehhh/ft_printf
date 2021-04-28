
#include "./include/ft_printf.h"

int main()
{
	ft_printf("%*.4s--  --%.4s-\n", 10, "abcde", "abcdefg");
	return (0);
}
