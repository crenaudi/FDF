#include <math.h>
#include "includes/fdf.h"
/*
void converte_rot(t_point)
{
	x = cos(delta.x) + sin(delta.x) * x;
	y = cos(delta.y) - sin(delta.y) * y;
}*/

void donnees_coordonnees(t_point *coord, t_point origine)
{
	coord->x = origine.x;
	coord->y = origine.y;
	coord->z = origine.z;
	coord->delta.x = -0.785398;
	coord->delta.y = -0.785398;
}

int		converte(t_fdf *fdf)
{
	t_point	**coord;
	t_point	*point;
	int		x;
	int		y;

	y = -1;
	x = -1;
	ft_putstr("Hey");
	if (!(coord = (t_point **)malloc(sizeof(t_point *) * fdf->y_max)))
		return (ERROR);
	while (++y < fdf->y_max)
	{
		if (!(point = (t_point *)malloc(sizeof(t_point) * fdf->x_max)))
			return (ERROR);
		while (++x < fdf->x_max)
		{
			donnees_coordonnees(&coord[y][x], (*fdf).tab_point[y][x]);
		}
	}
	affichage(fdf, coord);
	return (SUCCESS);
}
/*
t_cam	*parallele(t_p p, t_fdf fdf)
{
	t_cam	*coord;

	coord.x = pow(tan(p.x), fdf.e);
	coord.y	= pow(tan(p.y), fdf.e);
	coord.z	= pow(tan(p.z), fdf.e);
	return(coord);
}
*/
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