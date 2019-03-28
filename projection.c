/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 16:19:28 by crenaudi          #+#    #+#             */
/*   Updated: 2019/03/10 19:49:11 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

static float	lerp_z(t_env *env, float z)
{
	if (env->z_max == 0 && env->z_min == 0)
		return (1);
	return ((z - env->z_min) / (env->z_max - env->z_min));
}

static int		trace(t_env *env, t_point **coord)
{
	int			x;
	int			y;
	t_vec3	z;

	y = -1;
	while (++y < env->y_max)
	{
		x = -1;
		while (++x < env->x_max)
		{
			if (x < (env->x_max - 1))
			{
				z.x = lerp_z(env, env->tab_p[y][x].z);
				z.y = lerp_z(env, env->tab_p[y][x + 1].z);
				line(env, coord[y][x], coord[y][x + 1], z);
			}
			if (y < (env->y_max - 1))
			{
				z.x = lerp_z(env, env->tab_p[y][x].z);
				z.y = lerp_z(env, env->tab_p[y + 1][x].z);
				line(env, coord[y][x], coord[y + 1][x], z);
			}
		}
	}
	return (SUCCESS);
}

int						converte(t_env *env)
{
	int			x;
	int			y;

	y = -1;
	while (++y < env->y_max)
	{
		x = -1;
		while (++x < env->x_max)
		{
			env->tab_m[y][x].x = env->tab_p[y][x].x - (env->x_max / 2);
			env->tab_m[y][x].y = env->tab_p[y][x].y - (env->y_max / 2);
			env->tab_m[y][x].z = env->tab_p[y][x].z - (env->z_max / 2);
			scale(&env->tab_m[y][x], env->scl);
			rotate_x(&env->tab_m[y][x], env->rot_map.x);
			rotate_y(&env->tab_m[y][x], env->rot_map.y);
			rotate_z(&env->tab_m[y][x], env->rot_map.z);
		}
	}
	clean_image(env->img);
	trace(env, env->tab_m);
	return (SUCCESS);
}
