void scale(t_point *p, double e)
{
  p->x = p->x * e;
	p->y = p->y * e;
	p->z = p->z * e;
}

double dot_product(t_vec3 a, t_vec3 b)
{
  double angle;
  angle = (a.x * b.x) + (a->y * b.y) + (a.z * b.z);
  return (angle);
}

t_vec3 cross_product(t_vec3 a, t_vec3 b)
{
  t_vec3  c;
  c->x = (a->y * b.z) - (a.z * b.y);
	c->y = (a->z * b.x) - (a.x * b.z);
	c->z = (a->x * b.y) - (a.y * b.x);
  return (c);
}

void rotate_X(t_point *p)
{
	p->x = (p->x * 1) + (p->y * 0) + (p->z * 0);
	p->y = (p->x * 0) + (p->y * cos(p->d)) + (p->z * sin(p->d));
	p->z = (p->x * 0) + (p->y * -sin(p->d)) + (p->z * cos(p->d));
}

void rotate_Y(t_point *p)
{
  p->x = (p->x * cos(p->d)) + (p->y * 0) + (p->z * -sin(p->d));
	p->y = (p->x * 0) + (p->y * 1) + (p->z * 0);
	p->z = (p->x * sin(p->d)) + (p->y * 0) + (p->z * cos(p->d));
}

void rotate_Z(t_point *p)
{
  p->x = (p->x * cos(p->d)) + (p->y * sin(p->d)) + (p->z * 0);
	p->y = (p->x * -sin(p->d)) + (p->y * cos(p->d)) + (p->z * 0);
	p->z = (p->x * 0) + (p->y * 0) + (p->z * 1);
}
