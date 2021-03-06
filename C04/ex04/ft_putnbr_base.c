/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 17:58:01 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/04/08 12:30:28 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*g_base;

void	ft_print(int nbr, int length)
{
	if (!nbr)
		return ;
	ft_print(nbr / length, length);
	write(1, &g_base[nbr % length], 1);
}

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
		if (chk[(int)g_base[index]] || g_base[index] == '+'
				|| g_base[index] == '-')
			return (0);
		chk[(int)g_base[index++]] = 1;
	}
	return (1);
}

int		ft_length(void)
{
	int index;

	index = 0;
	while (g_base[index] != '\0')
		index++;
	return (index);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int			length;
	long long	temp;

	temp = nbr;
	g_base = base;
	length = ft_length();
	if (length < 2 || !ft_chk())
	{
		return ;
	}
	if (temp < 0)
	{
		temp *= -1;
		write(1, "-", 1);
	}
	ft_print(temp / length, length);
	write(1, &g_base[temp % length], 1);
}
