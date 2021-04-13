#include <unistd.h>
#include <stdio.h>

void	inter(char *str1, char *str2)
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
		j = 0;
		while (str2[j] != '\0')
		{
			if (str1[i] == str2[j])
			{
				if (!chk[(int)str1[i]])
					write(1, &str1[i], 1);
				chk[(int)str1[i]] = 1;
			}
			j++;
		}
		i++;
	}
}

int		main(int ac, char **av)
{
	int i;
	if (ac == 3)
		inter(av[1],av[2]);
	write(1, "\n", 1);
	return 0;
}
