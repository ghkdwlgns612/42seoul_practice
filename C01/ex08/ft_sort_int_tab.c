/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 21:26:43 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/03/29 21:19:22 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int index1;
	int index2;
	int size1;

	size -= 1;
	index1 = 0;
	index2 = 0;
	while (index2 < size)
	{
		size1 = size - index2;
		while (index1 < size1)
		{
			if (tab[index1] > tab[index1 + 1])
				ft_swap(&tab[index1], &tab[index1 + 1]);
			index1++;
		}
		index1 = 0;
		index2++;
	}
}
