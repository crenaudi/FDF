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

int		converte(t_env *env)
{
	int		x;
	int		y;

	y = -1;
	while (++y < env->y_max)
	{
		x = -1;
		while (++x < env->x_max)
		{
			env->tab_m[y][x].x = env->tab_p[y][x].x - (env->x_max / 2);
			env->tab_m[y][x].y = env->tab_p[y][x].y - (env->y_max / 2);
			env->tab_m[y][x].z = env->tab_p[y][x].z - (env->z_max / 2);
			scale(&env->tab_m[y][x], env->scale);
			rotate_x(&env->tab_m[y][x], env->rot_map.x);
			rotate_y(&env->tab_m[y][x], env->rot_map.y);
			rotate_z(&env->tab_m[y][x], env->rot_map.z);
		}
	}
	clean_image(env->img);
	trace(env, env->tab_m);
	return (SUCCESS);
}
