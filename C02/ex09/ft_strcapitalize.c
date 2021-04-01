/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 17:58:01 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/04/01 12:08:46 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_upper(char *str, int index)
{
	if (str[index] >= 'a' && str[index] <= 'z')
		str[index] = str[index] - 32;
}

void	ft_lower(char *str, int index)
{
	if (str[index] >= 'A' && str[index] <= 'Z')
		str[index] = str[index] + 32;
}

int		ft_flag(char *str, int index)
{
	if (index == 0)
		ft_upper(str, index);
	else
	{
		if (str[index - 1] >= 'a' && str[index - 1] <= 'z')
			return (0);
		if (str[index - 1] >= 'A' && str[index - 1] <= 'Z')
			return (0);
		if (str[index - 1] >= '0' && str[index - 1] <= '9')
			return (0);
		return (1);
	}
	return (1);
}

char	*ft_strcapitalize(char *str)
{
	int index;

	index = 0;
	while (str[index] != '\0')
	{
		if (ft_flag(str, index))
			ft_upper(str, index);
		else
			ft_lower(str, index);
		index++;
	}
	return (str);
}
