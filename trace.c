/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c  		                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 16:32:17 by crenaudi          #+#    #+#             */
/*   Updated: 2019/02/11 19:38:47 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
/*
static void fill_pixel(t_env *env, int x, int y, int color)
{
	env->img[(y * env->sl) + x] = (char)color;
}
*/


static void	init_trace(t_trace *b, t_point p1, t_point p2)
{
	t_color	color;

	ft_bzero(&color, sizeof(color));
	ft_bzero(b, sizeof(t_trace));
	b->p1 = (t_vec2){(int)p1.x, (int)p1.y};
	b->p2 = (t_vec2){(int)p2.x, (int)p2.y};
	b->dir.x = abs(b->p2.x - b->p1.x);
	b->dir.y = abs(b->p2.y - b->p1.y);
	b->sens.x = b->p1.x < b->p2.x ? 1 : -1;
	b->sens.y = b->p1.y < b->p2.y ? 1 : -1;
	b->color = init_color(color, 0x336699);
	b->t = 0;
}

static void	line(t_env *env, t_point p1, t_point p2)
{
	t_trace	b;
	int 		err;
	int 		e2;

	init_trace(&b, p1, p2);
	err = (b.dir.x > b.dir.y ? b.dir.x : -b.dir.y) / 2;
	e2 = 0;
	while ("OUIIIIIIIIIII")
	{
		b.t = interpolation(b.t, p1.x, p2.x);
		//ft_print_bits(lerp_color(env->color, b.color, b.t), 32, 8);
		//ft_putchar('\n');
		//fill_pixel(env.img, 0, 0, lerp_color(0x000000, 0xFFFFFF, t));
		mlx_pixel_put(env->mlx_ptr, env->win_ptr, b.p1.x, b.p1.y, lerp_color(env->color, b.color, b.t));
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

int		trace(t_env *env, t_point **coord)
{
	int			x;
	int			y;

	y = -1;
	while (++y < env->y_max)
	{
		x = -1;
		while (++x < env->x_max)
		{
			if (x < (env->x_max - 1))
				line(env, coord[y][x], coord[y][x + 1]);
			if (y < (env->y_max - 1))
				line(env, coord[y][x], coord[y + 1][x]);
		}
	}
	return (SUCCESS);
}
