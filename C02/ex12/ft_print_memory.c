/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 13:51:35 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/04/01 18:15:41 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	*ft_print_memory(void *addr, unsigned int size)
{
	char 		*str;
	long long	add;

	str = (char *)addr;
	add = (long long)addr;

	printf("%lld\n", add);
	write(1, str, 7);
}

int		main(void)
{
	ft_print_memory("asdfsdf", 7);
}
