/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 19:12:46 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/04/06 21:30:00 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_is_prime(int nb)
{
	int i;
	int j;

	if (nb < 2)
		return (0);
	i = 1;
	j = 1;
	while (i < nb)
	{
		while (j < nb)
		{
			if (i * j == nb)
				return (0);
			j++;
		}
		i++;
		j = i;
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
