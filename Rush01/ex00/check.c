/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yenam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 01:44:11 by yenam             #+#    #+#             */
/*   Updated: 2021/04/04 17:02:31 by hyojlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

extern	char		g_in[4][4];

bool	is_error(char *str);

bool	is_chk_colu(char **str)
{
	int		idx;
	char	cnt;
	char	base;
	int		row;

	idx = 0;
	row = 0;
	while (row < 4)
	{
		cnt = '1';
		base = g_in[idx][row];
		while (idx < 3)
		{
			if (base < g_in[++idx][row])
			{
				cnt++;
				base = g_in[idx][row];
			}
		}
		idx = 0;
		if (cnt != str[0][row])
			return (false);
		row++;
	}
	return (true);
}

bool	is_chk_cold(char **str)
{
	int		idx;
	char	cnt;
	char	base;
	int		row;

	idx = 3;
	row = 0;
	while (row < 4)
	{
		cnt = '1';
		base = g_in[idx][row];
		while (idx > 0)
		{
			if (base < g_in[--idx][row])
			{
				cnt++;
				base = g_in[idx][row];
			}
		}
		idx = 3;
		if (cnt != str[1][row])
			return (false);
		row++;
	}
	return (true);
}

bool	is_chk_rowr(char **str)
{
	int		idx;
	char	cnt;
	char	base;
	int		col;

	idx = 3;
	col = 0;
	while (col < 4)
	{
		cnt = '1';
		base = g_in[col][idx];
		while (idx > 0)
		{
			if (base < g_in[col][--idx])
			{
				cnt++;
				base = g_in[col][idx];
			}
		}
		idx = 3;
		if (cnt != str[3][col])
			return (false);
		col++;
	}
	return (true);
}

bool	is_chk_rowl(char **str)
{
	int		idx;
	char	cnt;
	char	base;
	int		col;

	idx = 0;
	col = 0;
	while (col < 4)
	{
		cnt = '1';
		base = g_in[col][idx];
		while (idx < 3)
		{
			if (base < g_in[col][++idx])
			{
				cnt++;
				base = g_in[col][idx];
			}
		}
		idx = 0;
		if (cnt != str[2][col])
			return (false);
		col++;
	}
	return (true);
}

bool	is_dup(int x, int y)
{
	int		i;
	int		j;

	i = -1;
	while (++i < y)
	{
		j = i + 1;
		while (j <= y)
		{
			if (g_in[x][i] == g_in[x][j++])
				return (false);
		}
	}
	i = -1;
	while (++i < x)
	{
		j = i + 1;
		while (j <= x)
		{
			if (g_in[i][y] == g_in[j++][y])
				return (false);
		}
	}
	return (true);
}
