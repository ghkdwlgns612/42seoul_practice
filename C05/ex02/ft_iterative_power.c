/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 12:25:29 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/04/06 12:30:18 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_iterative_power(int nb, int power)
{
	int index;
	int tar;

	tar = nb;
	index = 1;
	if (nb < 0 || power < 0)
		return (0);
	else if (power == 0)
		return (1);
	while (index++ < power)
		nb *= tar;
	return (nb);
}
