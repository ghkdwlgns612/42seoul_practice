/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 19:12:46 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/04/08 21:16:23 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_is_prime(int nb)
{
	int i;

	i = 2;
	if (nb <= 1)
		return (0);
	if (nb == 2 || nb == 3)
		return (1);
	while (i <= 46341)
	{
		if ((nb % i++) == 0)
			return (0);
	}
	return (1);
}

int		ft_find_next_prime(int nb)
{
	int num;

	num = nb;
	while (!ft_is_prime(num))
		num++;
	return (num);
}
