/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeukim <yeukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 20:22:01 by yeukim            #+#    #+#             */
/*   Updated: 2021/03/28 20:47:17 by yeukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_row(char *data, int x)
{
	int row;

	row = 0;
	while (row < x)
	{
		if (row == 0)
			ft_putchar(data[0]);
		else if (row == x - 1)
			ft_putchar(data[2]);
		else
			ft_putchar(data[1]);
		row++;
	}
	ft_putchar('\n');
}

void	print_col(char *data, int x, int y)
{
	int col;

	col = 0;
	while (col < y)
	{
		if (col == 0)
			print_row(&data[0], x);
		else if (col == y - 1)
			print_row(&data[6], x);
		else
			print_row(&data[3], x);
		col++;
	}
}

void	rush(int x, int y)
{
	if (x > 0 && y > 0)
		print_col("ABCB BABC", x, y);
	else
		ft_putchar('X');
}
