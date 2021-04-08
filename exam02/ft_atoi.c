int	ft_atoi(const char *str)
{
	int num;
	int index;
	int minus;

	index = 0;
	minus = 1;
	while (((str[index] >= 9) && (str[index] <=13)) || str[index] = ' ')
		index++;
	while (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			minus *= -1;
	}
	while (str[index] 
	return (num);
}
