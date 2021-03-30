/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 21:26:43 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/03/30 23:08:56 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int		index;

	index = 0;
	while ((*src != '\0') && (index < n))
	{
		*dest = *src;
		src++;
		dest++;
		index++;
	}
	while (index < n)
	{
		*dest = '\0';
		dest++;
		index++;
	}
	return (dest);
}
