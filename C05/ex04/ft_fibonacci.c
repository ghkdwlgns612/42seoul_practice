/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 12:41:32 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/04/07 00:39:52 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_recursive_fib(int index, int pre, int nb)
{
	int fib;

	if (index == 0)
		return (pre);
	if (index == 1)
		return (nb);
	fib = ft_recursive_fib(index - 1, nb, pre + nb);
	return (fib);
}

int		ft_fibonacci(int index)
{
	int fib;
	int pre;
	int nb;

	pre = 0;
	nb = 1;
	if (index < 0)
		return (-1);
	fib = ft_recursive_fib(index, pre, nb);
	return (fib);
}
