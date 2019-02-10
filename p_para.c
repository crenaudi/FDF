#include <math.h>
#include "includes/fdf.h"
/*
void converte(t_p **p)
{
	t_p		*tmp;

	tmp = *p;
	while (tmp != NULL)
	{
		tmp->cx = tmp->x - ((sin(tmp->y) * cos(tmp->x)) / cos(tmp->y)) * tmp->z;
		tmp->cy = tmp->y - ((sin(tmp->y) * sin(tmp->x)) / cos(tmp->y)) * tmp->z;
		tmp->cx = (tmp->cx * tmp->cx);
		tmp->cy = (tmp->cy * tmp->cy);
		tmp = tmp->next;
	}
}*/

void converte(t_p **p)
{
	t_p		*tmp;

	tmp = *p;
	while (tmp != NULL)
	{
		tmp->cz = 0;
		tmp->cx = tmp->x * 20;
		tmp->cy = tmp->y * 20;
		tmp = tmp->next;
	}
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
