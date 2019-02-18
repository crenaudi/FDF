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

void converte_rot(t_point *point)
{
	point->x = (point->x * 1) + (point->y * 0) + (point->z * 0);
	point->y = (point->x * 0) + (point->y * cos(point->delta.y)) + (point->z * sin(point->delta.y));
	point->z = (point->x * 0) + (point->y * -sin(point->delta.y)) + (point->z * cos(point->delta.y));
	point->x = point->x + 20;
	point->y = point->y + 20;
}

void	scale(t_point *point, t_fdf *fdf)
{
	fdf->scale = 20;
	point->x = point->x * fdf->scale;
	point->y = point->y * fdf->scale;
}

int		converte(t_fdf *fdf)
{
	t_point	**coord;
	t_point	*point;
	int		x;
	int		y;

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
			point[x].x = fdf->tab_point[y][x].x;
			point[x].y = fdf->tab_point[y][x].y;
			point[x].z = fdf->tab_point[y][x].z;
			point[x].delta.x = -1.5708;
			point[x].delta.y = -0.785398;
			converte_rot(&point[x]);
			scale(&point[x], fdf);
		}
	}
	affichage(fdf, coord);
	return (SUCCESS);
}

/*
t_cam	*isometric(t_p p, t_fdf fdf)
{
	t_cam	*coord;
	double w;

	w = 1;
	coord.x = p.x * cos(p.x) + p.x * 0 + p.z * -sin(p.x) + w * 0;
	coord.y = p.x * 0 + p.y * 1 + p.z * 0 + w * 0;
	coord.z = p.x * sin(p.z) + p.y * 0 + p.z * cos(p.z) + w * tan();
	w = p.x * 0 + p.y * 0 + p.z * 0 + w * 0;
	if (w != 1 || w != 0)
	{
		coord.x /= w;
		coord.y /= w;
		coord.z	/= w;
	}
	return(coord);
}
*/
