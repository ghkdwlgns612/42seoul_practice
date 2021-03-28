/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 22:30:58 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/03/28 23:13:11 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(int nb)
{
	int mod;
	char front;

	mod = 0;
	front = 'a';
	nb = (nb) / 10;
	if (nb >= 10)
	{
		ft_print(nb);
	}
	else
	{
		front = nb + '0';
		write(1, &front, 1);
	}
}

void	ft_except(void)
{
	write(1, "-", 1);
	write(1, "2147483648", 10);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		if (nb == -2147483648)
		{
			ft_except();
		}
		else
		{
			write(1, "-", 1);
			nb = nb * (-1);
			ft_print(nb);
		}
	}
	else
	{
		ft_print(nb);
	}
}

int		main(void)
{
	ft_putnbr(212355);
	return (0);
}
