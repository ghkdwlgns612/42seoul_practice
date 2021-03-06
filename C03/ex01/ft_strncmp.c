/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 17:58:01 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/04/05 11:11:45 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int index;

	index = 0;
	while ((s1[index] != '\0' && s2[index] != '\0') && (n > 0))
	{
		if (s1[index] != s2[index])
			break ;
		else
		{
			index++;
			n--;
		}
	}
	if (n == 0)
		return (0);
	if (s1[index] > s2[index])
		return (1);
	else if (s1[index] < s2[index])
		return (-1);
	return (0);
}
