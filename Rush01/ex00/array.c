/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojlee <hyojlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 19:03:13 by hyojlee           #+#    #+#             */
/*   Updated: 2021/04/04 19:44:15 by hyojlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>

extern	char	g_in[4][4];

void	init_array(void)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
			g_in[i][j++] = '0';
		i++;
	}
}

void	put_char(char **str)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 3)
		{
			write(1, &g_in[i][j++], 1);
			write(1, " ", 1);
		}
		write(1, &g_in[i][j], 1);
		write(1, "\n", 1);
		i++;
	}
	i = 0;
	while (i < 4)
		free(str[i++]);
	free(str);
}

bool	is_sum_64(void)
{
	int i;
	int j;
	int sum;

	i = 0;
	sum = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
			sum = sum + g_in[i][j++] - '0';
		i++;
	}
	if (sum == 64)
		return (true);
	return (false);
}
