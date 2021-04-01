/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 17:58:01 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/04/01 22:21:45 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int length;
	unsigned int end;
	unsigned int index;
	unsigned int src_index;

	index = 0;
	length = 0;
	src_index = 0;
	while (dest[index] != '\0')
	{
		length++;
		index++;
	}
	end = length + nb;
	while (length < end)
	{
		dest[index] = src[src_index];
		length++;
		index++;
		src_index++;
	}
	dest[index] = '\0';
	return (dest);
}
