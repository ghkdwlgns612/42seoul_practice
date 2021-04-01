/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 17:58:01 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/04/01 16:56:50 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

const char g_hex[] = "0123456789abcdef";

void	ft_print_16(char print)
{
	int		index;
	int		div;
	int		mod;

	index = (int)print;
	write(1, "\\", 1);
	div = index / 16;
	write(1, &g_hex[div], 1);
	mod = index % 16;
	write(1, &g_hex[mod], 1);
}

void	ft_putstr_non_printable(char *str)
{
	int index;

	index = 0;
	while (str[index])
	{
		if (str[index] >= ' ' && str[index] <= '~')
			write(1, &str[index], 1);
		else
			ft_print_16(str[index]);
		index++;
	}
}
