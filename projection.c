/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 16:19:28 by crenaudi          #+#    #+#             */
/*   Updated: 2019/02/15 19:31:38 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

static void clean_tab(t_point **coord, int coord_y)
{
	int i;

	i = 0;
	while (i < coord_y)
	{
		free(coord[i]);
		i++;
	}
	free(coord);
}

int		converte(t_env *env)
{
	t_point	**coord;
	t_point	*point;
	int		x;
	int		y;

	y = -1;
	if (!(coord = (t_point **)malloc(sizeof(t_point *) * env->y_max)))
		return (ERROR);
	while (++y < env->y_max)
	{
		if (!(point = (t_point *)malloc(sizeof(t_point) * env->x_max)))
			return (ERROR);
		coord[y] = point;
		x = -1;
		while (++x < env->x_max)
		{
			point[x].x = (env->tab_p[y][x].x - (env->x_max / 2));
			point[x].y = (env->tab_p[y][x].y - (env->y_max / 2));
			point[x].z = env->tab_p[y][x].z + env->c.z;
			scale(&point[x], env->scale);
			rotate_x(&point[x], env->rot_map.x);
			rotate_y(&point[x], env->rot_map.y);
			rotate_z(&point[x], env->rot_map.z);
		}
	}
	trace(env, coord);
	clean_tab(coord, env->y_max);
	return (SUCCESS);
}
