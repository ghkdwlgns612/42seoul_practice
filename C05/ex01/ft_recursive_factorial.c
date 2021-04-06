/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 12:14:15 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/04/06 12:25:00 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_recursive_factorial(int nb)
{
	int result;
	int num;

	result = 1;
	if (nb < 0)
		return (0);
	else if (nb > 1)
		num = ft_recursive_factorial(nb - 1);
	else
	{
		if (nb == 0)
			return (1);
		num = nb;
	}
	result = nb * num;
	return (result);
}
