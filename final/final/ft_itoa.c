#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*ft_itoa(int nbr)
{
	int temp;
	int mod;
	int len;
	char  *ret;
	if (nbr < 0)
	{
		temp = -nbr;
		len = 1;
	}
	else
	{
		temp = nbr;
		len = 0;
	}
	while (temp)
	{
		temp /= 10;
		len++;
	}
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (nbr == 0)
	{
		ret[0] = '0';
		return (ret);
	}
	else if (nbr < 0)
	{
		ret[0] = '-';
		nbr *= -1;
	}
	while (len != 0 && nbr != 0)
	{
		mod = (nbr % 10) + '0';
		ret[--len] = mod;
		nbr = nbr / 10;
	}
	return (ret);	
}

int		main(void)
{
	char *str;

	str = ft_itoa(-3);
	printf("%s",str);
}
