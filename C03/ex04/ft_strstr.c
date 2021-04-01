/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 10:20:09 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/04/01 19:22:56 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_length(char *str)
{
	int length;

	length = 0;
	while (str[length] != '\0')
		length++;
	return (length);
}

int		ft_cmp(char *str, char *to_find, int str_index)
{
	int length;
	int index;

	index = 0;
	length = ft_length(to_find);
	while (index < length)
	{
		if (str[str_index] == to_find[index])
		{
			index++;
			str_index++;
		}
		else
			return (0);
	}
	return (1);
}

char	*ft_strstr(char *str, char *to_find)
{
	int index;
	int find_index;

	find_index = 0;
	index = 0;
	while (str[index] != '\0')
	{
		if ((str[index] == to_find[find_index])
				&& (to_find[find_index] != '\0'))
		{
			if (ft_cmp(str, to_find, index))
				return (&str[index]);
			else
				return (0);
		}
		index++;
	}
	return (0);
}
