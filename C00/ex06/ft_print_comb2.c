/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 21:16:19 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/03/31 01:36:32 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(int nb1, int nb2)
{
	char str[5];

	str[0] = (nb1 / 10) + '0';
	str[1] = (nb1 % 10) + '0';
	str[2] = ' ';
	str[3] = (nb2 / 10) + '0';
	str[4] = (nb2 % 10) + '0';
	write(1, &str, 5);
	if ((nb1 != 98) || (nb2 != 99))
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb2(void)
{
	int number[2];

	number[0] = 0;
	number[1] = 1;
	while (number[0] <= 98)
	{
		while (number[1] <= 99)
		{
			ft_print(number[0], number[1]);
			number[1]++;
		}
		number[0]++;
		number[1] = number[0] + 1;
	}
}
