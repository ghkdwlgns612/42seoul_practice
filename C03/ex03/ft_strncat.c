/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 17:58:01 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/04/05 11:26:29 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int length;
	unsigned int index;

	index = 0;
	length = 0;
	while (dest[length] != '\0')
	{
		length++;
	}
	while (src[index] != '\0' && index < nb)
	{
		dest[index + length] = src[index];
		index++;
	}
	dest[index + length] = '\0';
	return (dest);
}
