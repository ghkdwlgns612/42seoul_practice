/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 01:47:11 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/04/07 01:56:53 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		main(int argc, char **argv)
{
	int index1;
	int index2;

	index1 = 0;
	index2 = argc - 1;
	while (index2 > 0)
	{
		while (argv[index2][index1] != '\0')
			write(1, &argv[index2][index1++], 1);
		write(1, "\n", 1);
		index2--;
		index1 = 0;
	}
	return (0);
}
