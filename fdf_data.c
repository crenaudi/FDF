/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 16:36:34 by crenaudi          #+#    #+#             */
/*   Updated: 2019/02/15 18:12:05 by crenaudi         ###   ########.fr       */
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
	int	z;

	z = ft_atoi(*line);
	p = add_point(x, y, z);
	if (fdf->p == NULL)
	{
		fdf->p = p;
	}
	else
	{
		p->next = fdf->p;
		fdf->p = p;
	}
	z = abs(z);
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

	y = fdf->y_max;
	p = fdf->p;
	if (!(fdf->tab_point = (t_point **)malloc(sizeof(t_point *) * fdf->y_max)))
		return (0);
	while (y--)
	{
		x = fdf->x_max;
		if (!(point = (t_point *)malloc(sizeof(t_point) * fdf->x_max)))
			return (0);
		fdf->tab_point[y] = point;
		while (x--)
		{
			point[x].x = p->x;
			point[x].y = p->y;
			point[x].z = p->z;
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
	while (get_next_line(fd, &line) == 1)
	{
		x = 0;
		while (*line != '\0')
		{
			while (*line == ' ')
				line++;
			if (*line == '\0')
				break;
			coordonees(&line, fdf, x, y);
			line++;
			x++;
		}
		y++;
	}
	fdf->x_max = x;
	fdf->y_max = y;
	make_tab(-1, fdf);
	return (1);
}
