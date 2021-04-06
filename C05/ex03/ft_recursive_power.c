/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 12:31:02 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/04/06 12:35:50 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_recursive_power(int nb, int power)
{
	int tar;

	tar = nb;
	if (nb < 0 || power < 0)
		return (0);
	else if (power == 0)
		return (1);
	if (power > 1)
		nb = tar * ft_recursive_power(nb, power - 1);
	return (nb);
}
