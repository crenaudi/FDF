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

int		converte(t_fdf *fdf)
{
	t_point	**coord;
	t_point	*point;
	int		x;
	int		y;

	fdf->rot_map.x = deg2rad(-45);
	fdf->rot_map.y = deg2rad(-25);
	fdf->rot_map.z = deg2rad(25);
	y = -1;
	if (!(coord = (t_point **)malloc(sizeof(t_point *) * fdf->y_max)))
		return (ERROR);
	while (++y < fdf->y_max)
	{
		if (!(point = (t_point *)malloc(sizeof(t_point) * fdf->x_max)))
			return (ERROR);
		coord[y] = point;
		x = -1;
		while (++x < fdf->x_max)
		{
			point[x].x = fdf->tab_point[y][x].x - (fdf->x_max / 2);
			point[x].y = fdf->tab_point[y][x].y - (fdf->y_max / 2);
			point[x].z = fdf->tab_point[y][x].z;
			fdf->scale = 20;
			scale(&point[x], fdf->scale);
			rotate_x(&point[x], fdf->rot_map.x);
			rotate_y(&point[x], fdf->rot_map.y);
			rotate_z(&point[x], fdf->rot_map.z);
		}
	}
	affichage(fdf, coord);
	return (SUCCESS);
}
