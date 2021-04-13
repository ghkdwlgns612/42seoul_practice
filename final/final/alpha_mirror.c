#include <unistd.h>
#include <stdio.h>

char g_val[26];

void ft_fillalp(void)
{
	int i;
	char a;

	a = 'a';
	i = 0;
	while (i < 26)
		g_val[i++] = a++;
}

int		main(int ac, char **av)
{
	int i;
	int index;

	i = 0;
	if (ac == 2)
	{
		ft_fillalp();
		while (av[1][i] != '\0')
		{
			if ((av[1][i] >= 'a' && av[1][i] <= 'm') || (av[1][i] >= 'A' && av[1][i] <= 'M'))
			{
				index = av[1][i] - 'a';
				write(1, &g_val[25 - index], 1);
			}
			else if ((av[1][i] >= 'n' && av[1][i] <= 'z') || (av[1][i] >= 'N' && av[1][i] <= 'Z'))
			{
				index = av[1][i] - 'm';
				write(1, &g_val[], 1);
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return 0;
}
