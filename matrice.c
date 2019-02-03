#include "includes/fdf.h"

t_p	*cal_coordonnees(t_p *p, t_cam *c, t_fdf *f)
{
	t_p	*tmp;
	t_p	*coord;
	double	x;
	double	y;
	double	z;

	x = (p->x * f->delta) - c->x;
	y = (p->y * f->delta) - c->y;
	z = p->z - c->z;
	tmp = add_point(0, 0, 0);
	coord = add_point(0, 0, 0;
	tmp->x = (cos(c->ry) * ((sin(c->vz) * y) + (cos(c->vz) * x)))
                    - (sin(c->vy) * z);
	tmp->y = (sin(c->vx) * ((cos(c->vy) * z) + (sin(c->vy) * ((sin(c->vy) * y) + (cos(c->vz) * x)))))
                    + (cos(c->vx) * ((cos(c->vy) * y) - (sin(c->vz) * x)));
	tmp->z = (cos(c->rx) * ((cos(c->vy) * z) + (sin(c->vy) * ((sin(c->vy) * y) + (cos(c->vz) * x)))))
                    - (sin(c->vx) * ((cos(c->vz) * y) - (sin(c->vz) * x)));
	coord->x = (c->vleng / tmp->z) * tmp->x;
	coord->y = (c->vleng / tmp->z) * tmp->y;
	free(tmp);
	return (coord);
}