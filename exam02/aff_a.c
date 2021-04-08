/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_a.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 21:31:56 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/04/08 21:37:39 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		main(int argc, char **argv)
{
	int index;

	index = 0;
	if (argc == 2)
	{
		while (argv[1][index] != '\0')
		{
			if (argv[1][index++] == 'a')
			{
				write(1, "a", 1);
				write(1, "\n", 1);
				return (0);
			}
		}
	}
	return (0);
}
