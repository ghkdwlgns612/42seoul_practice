/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 01:58:43 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/04/07 03:53:42 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strcmp(char *s1, char *s2)
{
	int index;

	index = 0;
	while (s1[index] == s2[index])
	{
		if (s1[index] == '\0' && s2[index] == '\0')
			return (0);
		index++;
	}
	if (s1[index] > s2[index])
		return (1);
	else
		return (-1);
}

void	ft_print(int nb, char **str)
{
	int index1;
	int index2;

	index1 = 0;
	index2 = 1;
	while (index2 < nb)
	{
		while (str[index2][index1] != '\0')
			write(1, &str[index2][index1++], 1);
		write(1, "\n", 1);
		index2++;
		index1 = 0;
	}
}

int		main(int argc, char **argv)
{
	char	*str;
	int		i;
	int		j;
	int		temp;

	i = 0;
	while (i < argc - 2)
	{
		j = 1;
		while (j < argc - i - 1)
		{
			temp = ft_strcmp(argv[j], argv[j + 1]);
			if (temp == 1)
			{
				str = argv[j + 1];
				argv[j + 1] = argv[j];
				argv[j] = str;
			}
			j++;
		}
		i++;
	}
	ft_print(argc, argv);
	return (0);
}
