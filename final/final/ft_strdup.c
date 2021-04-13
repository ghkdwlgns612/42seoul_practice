#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char    *ft_strdup(char *src)
{
	int i;
	int len;
	char *str;

	i = 0;
	len = 0;
	while (src[len] != '\0')
		len++;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if(!str)
		return (0);
	while (src[i] != '\0')
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
