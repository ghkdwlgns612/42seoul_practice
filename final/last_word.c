#include <unistd.h>
#include <stdio.h>

int		ft_len(char *str)
{
	int len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int		main(int ac, char **av)
{
	int len;

	if (ac == 2)
	{
		len = ft_len(av[1]) - 1;
		while (((av[1][len] >= 9 && av[1][len] <= 13) || av[1][len] == ' ') && av[1][len] != '\0')
			len--;
		while (!(av[1][len] >= 9 && av[1][len] <= 13) && !(av[1][len] == ' ') && av[1][len] != '\0')
			len--;
		len++;
		while (!(av[1][len] >= 9 && av[1][len] <= 13) && !(av[1][len] == ' ') && av[1][len] != '\0')
			write(1, &av[1][len++], 1);
	}
	write(1, "\n", 1);
	return 0;
}
