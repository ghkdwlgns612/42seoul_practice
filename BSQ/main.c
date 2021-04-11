# include <fcntl.h>
# include <unistd.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <errno.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "ft_h.h"

# define __MSG_MAP_ERROR "map error \n"
# define __BUF 8192
# define __MBUF 15


int		new_plate(char *platepath, int i);

char	**parse_file(char *filepath, t_data *dat);

int		ft_list_push_back(t_buf **liste, char *buf);
t_buf	*ft_create_elem(char *buf);
void	ft_list_clear(t_buf **plate);

void	ft_matrix(char **lines);
void	ft_display(char **lines, t_data dat);
void	ft_reso(char **lines, t_data dat);
void	ft_reso_2(char **lines, t_data dat, t_reso *all, t_carre *carre);
void	ft_fill(char **lines, t_carre carre, t_data dqat);
int		check_ligne(char **lines, t_reso all, t_data dat);
int		check_col(char **lines, t_reso all, t_data dat);
int		square_is_sup(t_carre carre, int vmax);
int		ft_square(char **lines, t_reso all, t_data dat, int *to_jump);
void	free_matrice(char **lines, t_data dat);

void	ft_putchar(char c, int out);
void	ft_putstr(char *str, int out);
void	ft_putstr_buf(char *buf);

t_parsing	g_v;
char		**g_l;


int		dec1(char *filepath, t_data *dat)
{
	g_v.file = -1;
	if (filepath == 0)
		g_v.file = 0;
	if (g_v.file == 0 || (g_v.file = open(filepath, O_RDWR)) != -1)
	{
		g_v.bufsize = __MBUF;
		g_v.state = 0;
		(*dat).row = 0;
		g_v.buf = malloc(sizeof(char) * (g_v.bufsize + 1));
		g_v.j = 0;
		return (1);
	}
	return (0);
}

int		parse_file_first(char *buf, t_data *dat)
{
	int		i;
	int		size;

	size = g_v.nt;
	if (size < 5)
		return (0);
	size -= 2;
	(*dat).fill = buf[size];
	if (((*dat).full = buf[size - 1]) == (*dat).fill)
		return (0);
	if (((*dat).empt = buf[size - 2]) == (*dat).fill ||
		(*dat).empt == (*dat).fill)
		return (0);
	i = -1;
	while (++i < size - 2)
	{
		if (buf[i] >= '0' && buf[i] <= '9')
			(*dat).row = (*dat).row * 10 + (buf[i] - '0');
		else
			return (0);
	}
	return (1);
}

int		dec2(t_data *dat, t_buf *bufs)
{
	if (g_v.k == 0)
		if ((g_l[g_v.l] = malloc(sizeof(char) * ((*dat).col + 2))) == NULL)
			return (0);
	if ((*bufs).buf[g_v.j] == '\n')
	{
		if (g_v.k != (*dat).col - 1)
			return (0);
		g_l[g_v.l][g_v.k] = '\0';
		g_v.k = 0;
		g_v.l++;
	}
	else
		g_l[g_v.l][g_v.k++] = (*bufs).buf[g_v.j];
	if (g_v.state == 2)
		g_v.state++;
	return (1);
}

int		read_to_g_l(t_data *dat)
{
	if (g_v.l >= (*dat).row)
		return (0);
	if ((g_l[g_v.l] = malloc(sizeof(char) * ((*dat).col + 2))) == NULL)
		return (0);
	g_l[g_v.l] = g_v.buf;
	if (g_l[g_v.l][(*dat).col - 1] == '\n')
		g_l[g_v.l++][(*dat).col - 1] = '\0';
	else
		return (0);
	return (1);
}

void	dec4(void)
{
	g_v.nt = g_v.i + 1;
	g_v.state++;
}

void	dec5(t_data *dat)
{
	(*dat).col = g_v.j - g_v.nt + 1;
	if ((g_v.bufsize = (*dat).col - (g_v.readen - (g_v.i + 1))) < 0)
		g_v.bufsize += (*dat).col;
	g_v.state++;
}

void	dec6(t_buf ***bufs)
{
	g_v.buf[g_v.bufsize] = '\0';
	ft_list_push_back(*bufs, g_v.buf);
	g_v.i = 0;
}

void	dec7(void)
{
	g_v.l = 0;
	g_v.k = 0;
}

void	dec8(t_data *dat)
{
	g_v.bufsize = (*dat).col;
	g_v.state++;
}

int		dec9(t_buf ***bufs, t_data *dat)
{
	g_v.j = -1;
	while ((***bufs).buf[++g_v.j])
	{
		if (g_v.state != 2 || g_v.j >= g_v.nt)
			dec2(dat, **bufs);
		else if (g_v.j == 0)
		{
			if (parse_file_first((***bufs).buf, dat) == 0)
				return (0);
			g_l = malloc(sizeof(char*) * ((*dat).row + 1));
		}
	}
	**bufs = (**bufs)->next;
	return (1);
}

void	dec10(t_buf **bufs, t_data *dat)
{
	dec6(&bufs);
	while (g_v.i < g_v.readen)
	{
		if (g_v.state == 0 && g_v.buf[g_v.i] == '\n')
			dec4();
		else if (g_v.state == 1 && g_v.buf[g_v.i] == '\n')
			dec5(dat);
		else if ((g_v.state == 2 && g_v.buf[g_v.i] == '\n'
			&& g_v.i == (g_v.readen - 1)) || g_v.bufsize == 0)
		{
			dec7();
			while (*bufs)
				dec9(&bufs, dat);
			dec8(dat);
		}
		g_v.i++;
		g_v.j++;
	}
}


int		check_ligne(char **lines, t_reso all, t_data dat)
{
	all.i += all.n;
	all.j += all.n;
	while (all.j >= 0 && all.n >= 0)
	{
		if (lines[all.i][all.j] == dat.full)
			return (1);
		all.j--;
		all.n--;
	}
	return (0);
}

int		check_col(char **lines, t_reso all, t_data dat)
{
	all.i += all.n;
	all.j += all.n;
	while (all.i >= 0 && all.n >= 0)
	{
		if (lines[all.i][all.j] == dat.full)
			return (1);
		all.i--;
		all.n--;
	}
	return (0);
}

int		square_is_sup(t_carre carre, int vmax)
{
	if (vmax > (carre.maxi - carre.i))
		return (1);
	return (0);
}

int		ft_square(char **lines, t_reso all, t_data dat, int *to_jump)
{
	int	iscol;

	all.n = 0;
	iscol = 0;
	while (all.i + all.n < (dat.row) && all.j + all.n < dat.col &&
			lines[all.i + all.n][all.j + all.n] == dat.empt &&
			check_ligne(lines, all, dat) == 0 &&
			(iscol = check_col(lines, all, dat)) == 0)
	{
		all.n++;
	}
	if (iscol == 1)
		*to_jump = all.n;
	return (all.n);
}

t_buf		*ft_create_elem(char *buf)
{
	t_buf		*created;

	created = NULL;
	created = malloc(sizeof(t_buf));
	if (created)
	{
		created->buf = buf;
		created->next = NULL;
	}
	return (created);
}

void	ft_list_clear(t_buf **bufs)
{
	t_buf	*ptr;
	t_buf	*list;

	list = *bufs;
	if (list)
		while (list)
		{
			ptr = list->next;
			free(list);
			list = ptr;
		}
}

int		ft_list_push_back(t_buf **liste, char *buf)
{
	t_buf		*list;

	list = *liste;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = ft_create_elem(buf);
	}
	else
		*liste = ft_create_elem(buf);
	return (1);
}

int		ft_list_push_front(t_buf **liste, char *buf)
{
	t_buf	*push;

	if (liste)
	{
		push = ft_create_elem(buf);
		if (push == NULL)
			return (0);
		push->next = *liste;
		*liste = push;
	}
	else
	{
		if ((*liste = ft_create_elem(buf)) == NULL)
			return (0);
	}
	return (1);
}



void	ft_putchar(char c, int out)
{
	write(out, &c, 1);
}

void	ft_putstr(char *str, int out)
{
	int		i;

	i = -1;
	while (str[++i])
		ft_putchar(str[i], out);
}

void	ft_putstr_buf(char *buf)
{
	int		i;

	i = 0;
	while (i < __BUF)
	{
		ft_putchar(buf[i], 1);
		i++;
	}
}

void	ft_putnbr(int nb)
{
	long	n;

	n = nb;
	if (n < 0)
	{
		ft_putchar('-', 1);
		n *= -1;
	}
	if (n <= 9)
		ft_putchar(n + '0', 1);
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}

int		new_plate(char *platepath, int i)
{
	char		**lines;
	t_data		dat;

	if (i != 1)
		ft_putstr("\n", 1);
	if ((lines = parse_file(platepath, &dat)) != 0)
	{
		ft_reso(lines, dat);
	}
	else
	{
		ft_putstr(__MSG_MAP_ERROR, 2);
		return (0);
	}
	return (1);
}

void	ft_display(char **lines, t_data dat)
{
	int i;

	i = 0;
	while (i < dat.row)
	{
		write(1, lines[i], dat.col);
		ft_putstr("\n", 1);
		i++;
	}
}

void	free_matrice(char **lines, t_data dat)
{
	int sup;

	sup = 0;
	while (sup++ < dat.row)
		free(lines[sup]);
	free(lines);
}

void	ft_reso_2(char **lines, t_data dat, t_reso *all, t_carre *carre)
{
	while (all->j < dat.col - 1)
	{
		if (all->to_jump > 0)
			all->to_jump--;
		else if (square_is_sup(*carre, all->vmax =
					ft_square(lines, *all, dat, &all->to_jump)) == 1)
		{
			carre->i = all->i;
			carre->j = all->j;
			carre->maxi = all->i + all->vmax;
			carre->maxj = all->j + all->vmax;
		}
		if (lines[all->i][all->j] != dat.empt &&
			lines[all->i][all->j] != dat.full)
		{
			ft_putstr(__MSG_MAP_ERROR, 2);
			free_matrice(lines, dat);
			exit(0);
		}
		all->j++;
	}
}

void	ft_init_struct(t_reso *all, t_carre *carre)
{
	all->i = 0;
	all->j = 0;
	all->to_jump = 0;
	all->vmax = 0;
	carre->i = 0;
	carre->j = 0;
	carre->maxi = 0;
	carre->maxj = 0;
}

void	ft_reso(char **lines, t_data dat)
{
	t_reso	all;
	t_carre carre;

	ft_init_struct(&all, &carre);
	while (all.i < dat.row)
	{
		all.j = 0;
		ft_reso_2(lines, dat, &all, &carre);
		all.i++;
	}
	all.j = all.i;
	ft_fill(lines, carre, dat);
}

void	ft_fill(char **lines, t_carre carre, t_data dat)
{
	int j;

	j = carre.j;
	while (carre.i < carre.maxi)
	{
		while (carre.j < carre.maxj)
		{
			lines[carre.i][carre.j] = dat.fill;
			carre.j++;
		}
		carre.j = j;
		carre.i++;
	}
	ft_display(lines, dat);
	free_matrice(lines, dat);
}


char	**parse_file(char *filepath, t_data *dat)
{
	t_buf	*bufs;

	bufs = 0;
	if (dec1(filepath, dat) == 1)
	{
		while ((g_v.readen = read(g_v.file, g_v.buf, g_v.bufsize)) != 0
			&& g_v.state != 3)
		{
			if (g_v.state != 4)
			{
				dec10(&bufs, dat);
			}
			else
			{
				if (read_to_g_l(dat) == 0)
					return (0);
			}
			g_v.buftmp = malloc(sizeof(char) * g_v.bufsize);
			g_v.buf = g_v.buftmp;
		}
		if ((*dat).row < 2 || g_v.l != (*dat).row)
			return (0);
		g_l[g_v.l] = 0;
	}
	return (g_l);
}

int		main(int argc, char **argv)
{
	int		i;

	i = 1;
	if (argc > 1)
		while (i < argc)
		{
			new_plate(argv[i], i);
			i++;
		}
	else
		new_plate(0, 0);
	return (0);
}
