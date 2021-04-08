/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 21:31:02 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/04/08 20:50:36 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int			g_cnt;

void		ft_print(int *result)
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = result[i] + '0';
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

int			ft_abs(int a, int b)
{
	if (a >= b)
		return (a - b);
	else
		return (b - a);
}

int			is_valid(int queen, int *result)
{
	int			i;

	i = 0;
	while (i < queen)
	{
		if (result[queen] == result[i] ||
				ft_abs(result[queen], result[i]) == (queen - i))
			return (0);
		i++;
	}
	return (1);
}

void		ft_back(int queen, int *result)
{
	result[queen] = 0;
	while (result[queen] < 10)
	{
		if (is_valid(queen, result))
		{
			if (queen == 9)
			{
				ft_print(result);
				g_cnt++;
			}
			else
				ft_back(queen + 1, result);
		}
		result[queen]++;
	}
}

int			ft_ten_queens_puzzle(void)
{
	int			arr[10];
	int			queen;
	int			index;

	index = 0;
	while (arr[index])
		arr[index++] = 0;
	queen = 0;
	g_cnt = 0;
	ft_back(queen, arr);
	return (g_cnt);
}
