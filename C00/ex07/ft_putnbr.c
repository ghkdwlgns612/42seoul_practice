/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 22:30:58 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/03/30 13:25:14 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(int nb)
{
	char mod;

	mod = (nb) % 10 + '0';
	nb = (nb) / 10;
	if (nb >= 10)
	{
		ft_print(nb);
		write(1, &mod, 1);
	}
	else if (nb >= 0 && nb <= 9)
	{
		write(1, &mod, 1);
	}
	else
	{
		nb = nb + '0';
		write(1, &nb, 1);
		write(1, &mod, 1);
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
