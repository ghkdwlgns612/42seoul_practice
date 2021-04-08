/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 15:59:03 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/04/08 15:59:15 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		len;
	char	*ret;

	len = 0;
	while (src[len] != '\0')
		len++;
	ret = (char *)malloc(sizeof(char) * len + 1);
	ret[len] = 0;
	while (--len >= 0)
	{
		ret[len] = src[len];
	}
	return (ret);
}
