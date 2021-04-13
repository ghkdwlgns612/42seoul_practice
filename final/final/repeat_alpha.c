#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_alp(char a)
{
	int num;
	int b;

	num = 0;
	b = a - 'a' + 1;
	if (a >= 'a' && a <= 'z')
	{
		while (num < b)
		{
			write(1, &a, 1);
			num++;
		}
	}
	else
		write(1, &a, 1);
}

int		main(int ac, char **av)
{
	int index;

	index = 0;
	if (ac == 2)
	{
		while (av[1][index] != '\0')
		{
			ft_alp(av[1][index]);
			index++;
		}
	}
	write(1,"\n",1);
}
