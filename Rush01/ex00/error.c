/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojlee <hyojlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 08:16:50 by hyojlee           #+#    #+#             */
/*   Updated: 2021/04/04 20:25:17 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

extern	char	g_in[4][4];

int		ft_strlen(char *str)
{
	int cnt;

	cnt = 0;
	while (*str++ != '\0')
		cnt++;
	return (cnt);
}

int		absol_val(int a)
{
	if (a < 0)
		return (a * -1);
	return (a);
}

bool	is_error(char *argv)
{
	int i;

	i = 0;
	if (ft_strlen(argv) != 31)
		return (true);
	while (argv[i] != '\0')
	{
		if (i % 2 == 0)
		{
			if (argv[i] < '1' || argv[i] > '4')
				return (true);
		}
		else
		{
			if (argv[i] != ' ')
				return (true);
		}
		i++;
	}
	return (false);
}

bool	is_err_arr(char *str1, char *str2)
{
	int idx;
	int sub;

	idx = 0;
	while (idx < 4)
	{
		sub = str1[idx] - str2[idx];
		if (sub == 0 && str1[idx] != '2')
			return (true);
		if (str1[idx] == '4' || str2[idx] == '4')
		{
			if (absol_val(sub) != 3)
				return (true);
		}
		idx++;
	}
	return (false);
}
