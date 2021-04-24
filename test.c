
#include <stdio.h>
#include <stdlib.h>

typedef	struct	s_list
{
	int *i;
	int d;
}				t_list;

void	ft_change(t_list tab)
{
	*(tab.i) = 7;
}

int main ()
{
	t_list	tab;
	int *i;

	tab.d = 7;
	tab.i = malloc(sizeof(int) * 1);
	*(tab.i) = 0;
	printf("%d-\n", *(tab.i));
	*(tab.i) = *(tab.i) + 1;
	printf("%d-\n", *(tab.i));
	ft_change(tab);
	printf("%d-\n", *(tab.i));
	return (0);
}
