#include <unistd.h>
#include <stdio.h>

void	wdmatch(char *str1, char *str2)
{
	int len;
	int i;
	int j;

	len = 0;
	i = 0;
	j = 0;
	while (str1[len] != '\0')
		len++;
	while (str2[j] != '\0')
	{
		if (str2[j] == str1[i])
			i++;
		j++;
	}
	if (i == len)
		write(1, str1, len);	
}

int		main(int ac, char **av)
{
	if (ac == 3)
	{
		wdmatch(av[1],av[2]);
	}
	write(1, "\n", 1);
	return (0);
}
