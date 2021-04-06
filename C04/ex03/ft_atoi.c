/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 17:58:01 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/04/05 15:30:34 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_atoi(char *str)
{
	int num;
	int index;
	int minus;

	num = 0;
	index = 0;
	minus = 1;
	while (str[index] == '\t' || str[index] == '\n'
			|| str[index] == '\v' || str[index] == '\f'
			|| str[index] == '\r' || str[index] == ' ')
		index++;
	while (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			minus *= (-1);
		index++;
	}
	while (str[index] >= '0' && str[index] <= '9')
	{
		num *= 10;
		num += (minus) * (str[index] - '0');
		index++;
	}
	return (num);
}
