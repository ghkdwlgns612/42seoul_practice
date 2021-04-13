#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int		ft_abs(int a,int b)
{
	if (a > b)
		return (a - b);
	else
		return (b - a);
}

int     *ft_rrange(int start, int end)
{
	int range;
	int *ret;
	int i;

	range = ft_abs(start,end) + 1;
	ret = (int *)malloc(sizeof(int) * range);
	i = 0;
	while (start > end)
		ret[i++] = end++;
	while (start < end)
		ret[i++] = end--;
	ret[i] = '\0';
	return (ret);
}

int		main(void)
{
	int *res;
	res = ft_rrange(0,-3);
	printf("%d%d%d%d",res[0],res[1],res[2],res[3]);
}
