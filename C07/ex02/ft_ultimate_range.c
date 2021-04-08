/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 15:57:42 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/04/08 15:57:51 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int ret;
	int *arr;
	int index;

	ret = max - min;
	index = 0;
	if (min > max)
		return (0);
	*range = (int *)malloc(sizeof(int) * ret);
	if (!*range)
		return (-1);
	arr = *range;
	while (min < max)
		arr[index++] = min++;
	return (ret);
}
