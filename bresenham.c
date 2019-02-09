/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 16:32:17 by crenaudi          #+#    #+#             */
/*   Updated: 2019/02/03 19:30:59 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int		color(double t)
{
	return(RGB(
				127.5 * (cos(t) + 1),
				127.5 * (sin(t) + 1),
				127.5 * (1 - cos(t))));
}

int		degrade_color(double t, int x1)
{
	return(t - 0.1);
}

int		line(t_fdf fdf, t_p *p1, t_p *p2)
{
	int sx;
	int sy;
	int dx;
	int dy;
	int err;
	int e2;

	p1->cx = (int)p1->cx;
	p2->cx = (int)p2->cx;
	p1->cy = (int)p1->cy;
	p2->cy = (int)p2->cy;
	dx = abs((int)p2->cx - (int)p1->cx);
	dy = abs((int)p2->cy - (int)p1->cy);
	sx = (int)p1->cx < (int)p2->cx ? 1 : -1;
	sy = (int)p1->cy < (int)p2->cy ? 1 : -1;
	err = (dx > dy ? dx : -dy) / 2;
	e2 = 0;
	while (1)
	{
		fdf.color = color(fdf.color);
		mlx_pixel_put(fdf.mlx_ptr, fdf.win_ptr, (int)p1->cx , (int)p1->cy, fdf.color);
		if ((int)p1->cx == (int)p2->cx && (int)p1->cy == (int)p2->cy)
			return (0);
		e2 = err;
		if (e2 > -dx)
		{
			err -= dy;
			p1->cx += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			p1->cy += sy;
		}
	}
	return (1);
}
