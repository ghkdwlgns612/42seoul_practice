/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 01:01:30 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/04/07 01:18:46 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		main(int argc, char **argv)
{
	int index;

	index = 0;
	if (argc == 1)
	{
		while (argv[0][index] != '\0')
			write(1, &argv[0][index++], 1);
	}
	write(1, "\n", 1);
	return (0);
}
