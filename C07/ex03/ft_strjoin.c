/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 15:32:41 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/04/08 15:56:38 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		ft_len(char *str)
{
	int len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strcat(char *dst, char *src)
{
	while (*src)
		*(dst++) = *(src++);
	return (dst);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		len_strs;
	int		i;
	char	*ret;
	char	*temp;

	if (!size)
	{
		ret = ((char *)malloc(1));
		ret[0] = 0;
		return (ret);
	}
	i = 0;
	len_strs = 0;
	while (i < size)
		len_strs += ft_len(strs[i++]);
	ret = (char *)malloc(len_strs + (size - 1) * (ft_len(sep)) + 1);
	temp = ft_strcat(ret, strs[0]);
	i = 1;
	while (i < size + 1)
	{
		temp = ft_strcat(temp, sep);
		temp = ft_strcat(temp, strs[i++]);
	}
	return (ret);
}
