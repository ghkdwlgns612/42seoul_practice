/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 15:58:14 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/04/08 15:58:23 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int *ret;
	int index;

	if (min >= max)
		return (0);
	ret = (int *)malloc(sizeof(int) * (max - min));
	index = 0;
	while (min < max)
		ret[index++] = min++;
	return (ret);
}
