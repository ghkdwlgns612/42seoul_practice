/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 17:58:01 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/04/08 12:31:45 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char *g_base;
int g_minus;

int		ft_chk(void)
{
	int chk[256];
	int index;

	index = 0;
	while (index < 256)
		chk[index++] = 0;
	index = 0;
	while (g_base[index] != '\0')
	{
		if (chk[(int)g_base[index]] ||
				g_base[index] == '+' || g_base[index] == '-' ||
				g_base[index] == ' ' ||
				(g_base[index] >= '\t' && g_base[index] <= '\r'))
			return (0);
		chk[(int)g_base[index++]] = 1;
	}
	return (1);
}

int		ft_front_chk(int len, char *str)
{
	int index;

	index = 0;
	g_minus = 1;
	if (!ft_chk() || len < 2)
		return (-1);
	while ((str[index] >= '\t' && str[index] <= '\r') ||
			str[index] == ' ')
		index++;
	while (str[index] == '+' || str[index] == '-')
	{
		if (str[index] == '-')
			g_minus *= -1;
		index++;
	}
	return (index);
}

int		ft_ret(char a)
{
	int index;

	index = 0;
	while (g_base[index] != '\0')
	{
		if (g_base[index] == a)
			return (index);
		index++;
	}
	return (-1);
}

int		ft_atoi_base(char *str, char *base)
{
	int length;
	int index;
	int flag;
	int result;

	length = 0;
	g_base = base;
	result = 0;
	while (g_base[length] != '\0')
		length++;
	flag = ft_front_chk(length, str);
	if (flag == -1)
		return (0);
	while (str[flag] != '\0')
	{
		index = ft_ret(str[flag]);
		if (index == -1)
			break ;
		result *= length;
		result += (g_minus) * (index);
		flag++;
	}
	return (result);
}
