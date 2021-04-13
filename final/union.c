#include <unistd.h>
#include <stdio.h>

void	zunion(char *str1, char *str2)
{
	int chk[256];
	int i;
	int j;

	i = 0;
	while (i < 256)
		chk[i++] = 0;
	i = 0;
	while (str1[i] != '\0')
	{
		if (!chk[(int)str1[i]])
			write(1, &str1[i], 1);
		chk[(int)str1[i++]] = 1;
	}
	i = 0;
	while (str2[i] != '\0')
	{
		if (!chk[(int)str2[i]])
			write(1, &str2[i], 1);
		chk[(int)str2[i++]] = 1;
	}
}

int		main(int ac, char **av)
{
	int i;
	if (ac == 3)
		zunion(av[1],av[2]);
	write(1, "\n", 1);
	return 0;
}
