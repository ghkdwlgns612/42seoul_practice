/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 17:47:58 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/03/28 22:29:20 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(char *first, char *second)
{
	if ((first[0] == '9') && (first[1] == '8'))
		break ;
	write(1, first, 2);
	write(1, " ", 1);
	write(1, second, 2);
	write(1, ",", 1);
}

void	ft_print_comb2(void)
{
	char first[2];
	char second[2];

	first[0] = '0' - 1;
	first[1] = '0' - 1;
	second[0] = '0' - 1;
	second[1] = '1' - 1;
	while (first[0]++ <= '9')
	{
		while (first[1]++ <= '9')
		{
			while (second[0]++ <= '9')
			{
				while (second[1]++ <= '9')
				{	
					if ((first[0] == '9') && (first[1] == '8'))
 						break ;
					ft_print(first, second);
				}
				second[1] = '0';
			}
			second[0] = first[0];
			second[1] = first[1] + 1;
		}
		first[1] = '0';
	}
	write(1, "98 99", 5);
}

int		main(void)
{
	ft_print_comb2();
	return (0);
}

