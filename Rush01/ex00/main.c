/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yenam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 01:44:11 by yenam             #+#    #+#             */
/*   Updated: 2021/04/07 00:31:51 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

char	g_in[4][4];
bool	g_index[4];

bool	is_err_arr(char *str1, char *str2);

bool	is_error(char *str);

bool	is_chk_colu(char **str);

bool	is_chk_cold(char **str);

bool	is_chk_rowr(char **str);

bool	is_chk_rowl(char **str);

bool	is_dup(int x, int y);

void	init_array(void);

void	put_char(char **str);

bool	is_sum_64(void);

void	rec_arr(char **str)
{
	g_index[0] = is_chk_colu(str);
	g_index[1] = is_chk_cold(str);
	g_index[2] = is_chk_rowl(str);
	g_index[3] = is_chk_rowr(str);
}

bool	is_chk_all(char **str)
{
	int index;

	index = -1;
	if (g_index[0] && g_index[1])
	{
		while (++index < 3)
		{
			if (str[2][index] <= '2')
			{
				if (g_index[3])
					return (true);
				return (false);
			}
			if (str[3][index] <= '2')
			{
				if (g_index[2])
					return (true);
				return (false);
			}
		}
		return (true);
	}
	return (false)
}

int		fill_in(int x, int y, char **str)
{
	int		i;

	if (y > 3)
	{
		x++;
		y = 0;
	}
	if (x > 3)
	{
		rec_arr(str);
		if (is_chk_all(str))
			return (1);
		return (0);
	}
	i = 0;
	while (++i < 5)
	{
		g_in[x][y] = i + '0';
		if (is_dup(x, y) && fill_in(x, y + 1, str))
			return (1);
	}
	return (0);
}

char	**ft_malloc(char **argv)
{
	char	**col_row;
	int		i;
	int		j;
	int		idx;

	col_row = (char **)malloc(sizeof(char *) * 4);
	i = 0;
	idx = 0;
	while (i < 4)
	{
		col_row[i] = (char *)malloc(sizeof(char) * 4);
		j = 0;
		while (j < 4)
		{
			col_row[i][j++] = argv[1][idx];
			idx += 2;
		}
		i++;
	}
	return (col_row);
}

int		main(int argc, char **argv)
{
	int		i;
	char	**str;

	i = 0;
	if (argc != 2 || is_error(argv[1]))
	{
		write(1, "Error\n", 6);
		return (-1);
	}
	str = ft_malloc(argv);
	if (is_err_arr(str[0], str[1]) || is_err_arr(str[2], str[3]))
	{
		write(1, "Error\n", 6);
		return (-1);
	}
	init_array();
	fill_in(0, 0, str);
	if (is_sum_64())
	{
		write(1, "Error\n", 6);
		return (-1);
	}
	put_char(str);
	return (0);
}
