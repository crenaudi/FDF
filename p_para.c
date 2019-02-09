#include <math.h>
#include "includes/fdf.h"

void converte(t_fdf fdf, t_p *p)
{
	while (p != NULL)
	{
		p->cx = p->z * tan(p->x);
		p->cy =	p->z * tan(p->y);
		p = p->next;
	}
	ft_putstr("all right");
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
