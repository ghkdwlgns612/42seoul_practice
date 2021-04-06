/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 21:31:02 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/04/07 00:31:23 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char g_pre_index[10];
char g_index[10];
char g_aft_index[10];

void	init(void)
{
	int i;
	
	i = 0;
	while (i <= 10)
	{
		g_pre_index[i] = '0';
		g_index[i] = '0';
		g_aft_index[i] = '0';
		i++;
	}

}

int		ft_ten_queens_puzzle(void)
{
	init();
	int i;
	int j;

	i = 0;
	j = 0;
	g_pre_index[0] = '1';
	while(i < 10)
	{
		if (
	}
}
