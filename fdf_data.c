/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 16:36:34 by crenaudi          #+#    #+#             */
/*   Updated: 2019/02/14 15:54:48 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

t_p		*add_point(int x, int y, int z)
{
	t_p	*p;

	p = (t_p *)malloc(sizeof(t_p) * 1);
	p->x = (double)x;
	p->y = (double)y;
	p->z = (double)z;
	p->next = NULL;
	return (p);
}

static void	coordonees(char **line, t_fdf *fdf, int x, int y)
{
	t_p	*p;
//	t_p	*last;
	int	z;

	z = ft_atoi(*line);
	p = add_point(x, y, z);
//	last = fdf->p;
	if (fdf->p == NULL)
	{
		fdf->p = p;
	}
	else
	{
//		while (last->next != NULL)
//			last = last->next;
		p->next = fdf->p;
		fdf->p = p;
	}
	while (z > 9)
	{
		z = z / 10;
		(*line)++;
	}
}

static int 	make_tab(int y, t_fdf *fdf)
{
	t_point *point;
	t_p		*p;
	int 	x;

	p = fdf->p;
	if (!(fdf->tab_point = (t_point **)malloc(sizeof(t_point *) * fdf->y_max)))
		return (0);
	while (++y < fdf->y_max)
	{
		x = -1;
		if (!(point = (t_point *)malloc(sizeof(t_point) * fdf->x_max)))
			return (0);
		fdf->tab_point[y] = point;
		while (++x < fdf->x_max)
		{
			point[x] = *(t_point*)p;
			p = p->next;
		}
	}
	return (0);
}

int		stock_fdf(int fd, t_fdf *fdf)
{
	char	*line;
	t_p		*p;
	int		x;
	int		y;

	y = 0;
	fdf->p = p;
	p = NULL;
	while (get_next_line(fd, &line) == 1 || y == 6)
	{
		x = 0;
		while (*line != '\0')
		{
			while (*line == ' ' && *line != '\0')
				line++;
			coordonees(&line, fdf, x, y);
			line++;
			x++;
		}
		ft_putchar('\n');
		y++;
	}
	//ft_putstr("ok");
	//ft_putnbr(fdf->p->x);
	fdf->x_max = x;
	fdf->y_max = y;
	make_tab(-1, fdf);
	return (1);
}
