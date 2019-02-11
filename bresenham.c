/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 16:32:17 by crenaudi          #+#    #+#             */
/*   Updated: 2019/02/11 19:38:47 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
/*
int		color(double t)
{
	return(RGB(
				127.5 * (cos(t) + 1),
				127.5 * (sin(t) + 1),
				127.5 * (1 - cos(t))));
}
*/

static void		init_bresenham(t_bresenham *b, t_point p1, t_point p2)
{
	b->p1 = (t_vec2){(int)p1.x, (int)p1.y};
	b->p2 = (t_vec2){(int)p2.x, (int)p2.y};
	b->dir.x = abs(b->p2.x - b->p1.x);
	b->dir.y = abs(b->p2.y - b->p1.y);
	b->sens.x = b->p1.x < b->p2.x ? 1 : -1;
	b->sens.y = b->p1.y < b->p2.y ? 1 : -1;
}

void	line(t_fdf *fdf, t_point p1, t_point p2)
{
	t_bresenham		b;
	int err;
	int e2;

	init_bresenham(&b, p1, p2);
	err = (b.dir.x > b.dir.y ? b.dir.x : -b.dir.y) / 2;
	e2 = 0;
	while ("OUIIIIIIIIIII")
	{
		//fdf->color = color(fdf->color);
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, b.p1.x, b.p1.y, 0xFFFFFF);
		if (b.p1.x == b.p2.x && b.p1.y == b.p2.y)
			return ;
		e2 = err;
		if (e2 > -b.dir.x)
		{
			err -= b.dir.y;
			b.p1.x += b.sens.x;
		}
		if (e2 < b.dir.y)
		{
			err += b.dir.x;
			b.p1.y += b.sens.y;
		}
	}
}
