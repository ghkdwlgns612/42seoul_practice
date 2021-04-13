#include <unistd.h>
#include <stdio.h>
#include <string.h>

char    *ft_strrev(char *str)
{
	char tmp;
	int len;
	int i;

	len = 0;
	i = 0;
	while (str[len] != '\0')
		len++;
	len -= 1;
	while (i < len)
	{
		tmp = str[i];
		str[i] = str[len];
		str[len] = tmp;
		i++;
		len--;
	}
	return (str);
}

int main()
{
    char *str  = strdup("Quentin <3");
    printf("%s\n", ft_strrev(str));
    return (0);
}
