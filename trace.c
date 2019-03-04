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

static void fill_pixel(t_img *img, int x, int y, int color)
{
	*(int *)(img->data + ((x + y * W_WIDTH) * img->bpp)) = color;
}

static void	init_trace(t_trace *b, t_point p1, t_point p2, float z1, float z2)
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
	b->c1 = z1 != 0.0 ? init_color(color, lerp_non_init_color(color, 0x000000,
		0x336699, z1)) : init_color(color, 0x000000);
	b->c2 = z2 != 0.0 ? init_color(color, lerp_non_init_color(color, 0x000000,
		0x336699, z2)) : init_color(color, 0x000000);
	b->t = vec2_dist(b->p2 - b->p1);
}

static void	line(t_env *env, t_point p1, t_point p2, float z1, float z2)
{
	t_trace	b;
	float		t2;
	int 		err;
	int 		e2;

	init_trace(&b, p1, p2, z1, z2);

	err = (b.dir.x > b.dir.y ? b.dir.x : -b.dir.y) / 2;
	e2 = 0;
	while ("OUIIIIIIIIIII")
	{
		t2 = vec2_dist(b.p2 - b.p1);
		fill_pixel(env->img, b.p1.x, b.p1.y,
			lerp_color(b.c2, b.c1, fmod((t2 / b.t) + env->bertrand, 1.0)));
		//mlx_pixel_put(env->mlx_ptr, env->win_ptr, b.p1.x, b.p1.y,
			//lerp_color(b.c2, b.c1, fmod((t2 / b.t) + env->bertrand, 1.0)));
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

static float	lerp_z(t_env *env, float z)
{
	return ((z - env->z_min) / (env->z_max - env->z_min));
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
			if ((x < (env->x_max - 1)) && (((env->tab_p[y][x].x <= W_HEIGHT)
				&& (env->tab_p[y][x].x >= 0)) || ((env->tab_p[y][x + 1].x <= W_HEIGHT)
				&& (env->tab_p[y][x + 1].x >= 0))))
				line(env, coord[y][x], coord[y][x + 1],
					lerp_z(env, env->tab_p[y][x].z),
					lerp_z(env, env->tab_p[y][x + 1].z));
			if ((y < (env->y_max - 1)) && (((env->tab_p[y][x].x <= W_HEIGHT)
				&& (env->tab_p[y][x].x >= 0)) || ((env->tab_p[y + 1][x].x <= W_HEIGHT)
				&& (env->tab_p[y + 1][x].x >= 0))))
				line(env, coord[y][x], coord[y + 1][x],
					lerp_z(env, env->tab_p[y][x].z),
					lerp_z(env, env->tab_p[y + 1][x].z));
		}
		mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img->ptr, 0, 0);
	}
	return (SUCCESS);
}
