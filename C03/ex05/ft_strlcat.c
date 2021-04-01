/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 20:42:22 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/04/01 21:58:45 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	ft_length(char *str)
{
	unsigned int length;

	length = 0;
	while (*str != '\0')
	{
		str++;
		length++;
	}
	return (length);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int length_src;
	unsigned int length_dest;
	unsigned int src_index;
	unsigned int dest_index;

	src_index = 0;
	length_src = ft_length(src);
	length_dest = ft_length(dest);
	dest_index = length_dest;
	while (src[src_index] != '\0' && size > length_dest + src_index + 1)
	{
		dest[dest_index] = src[src_index];
		dest_index++;
		src_index++;
	}
	dest[dest_index] = '\0';
	if (size < length_dest)
		return (length_src + size);
	else
		return (length_src + length_dest);
}
