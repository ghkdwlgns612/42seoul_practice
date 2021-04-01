/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 22:30:58 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/03/30 14:17:57 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	g_buf[10];

void	ft_solve(int n, int index, int value)
{
	if (index == n)
	{
		write(1, g_buf, n);
		if (g_buf[0] != 10 - n + '0')
			write(1, ", ", 2);
		return ;
	}
	while (value <= 10 - n + index)
	{
		g_buf[index] = value++ + '0';
		ft_solve(n, index + 1, value);
	}
}

void	ft_print_combn(int n)
{
	int value;

	value = 0;
	while (value <= 10 - n)
	{
		g_buf[0] = value++ + '0';
		ft_solve(n, 1, value);
	}
}
