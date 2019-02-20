#include "gfx.h"

/*
int lenght()
{
}
*/
int lerp_color(t_vec3 a, t_vec3 b, float t)
{
  int     mask;
  t_color c;

  mask = 0xFF;
  c.rgb.x = (b.x - a.x) * t + a.x;
  c.rgb.y = (b.y - a.y) * t + a.y;
  c.rgb.z = (b.z - a.z) * t + a.z;
  c.color = ((int)c.rgb.x << 16) & mask + ((int)c.rgb.y << 8) & mask + (int)c.rgb.z & mask;
  return (c.color);
}

float deg2rad(float d)
{
  float r;

  r = (d / 180.0f) * M_PI;
  return (r);
}

float rad2deg(float r)
{
  float d;

  d = (r / M_PI) * 180.0f;
  return (d);
}

void scale(t_point *p, float e)
{
  p->x = p->x * e;
	p->y = p->y * e;
	p->z = p->z * e;
}

float dot_product(t_vec3 a, t_vec3 b)
{
  float angle;
  angle = (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
  return (angle);
}

t_vec3 cross_product(t_vec3 a, t_vec3 b)
{
  t_vec3  c;

  c.x = (a.y * b.z) - (a.z * b.y);
	c.y = (a.z * b.x) - (a.x * b.z);
	c.z = (a.x * b.y) - (a.y * b.x);
  return (c);
}

void rotate_x(t_point *p, float a)
{
  t_vec3  tmp;

	tmp.x = (p->x * 1) + (p->y * 0) + (p->z * 0);
	tmp.y = (p->x * 0) + (p->y * cos(a)) + (p->z * sin(a));
	tmp.z = (p->x * 0) + (p->y * -sin(a)) + (p->z * cos(a));
  *p = tmp;
}

void rotate_y(t_point *p, float a)
{
  t_vec3  tmp;

  tmp.x = (p->x * cos(a)) + (p->y * 0) + (p->z * -sin(a));
	tmp.y = (p->x * 0) + (p->y * 1) + (p->z * 0);
  tmp.z = (p->x * sin(a)) + (p->y * 0) + (p->z * cos(a));
  *p = tmp;
}

void rotate_z(t_point *p, float a)
{
  t_vec3  tmp;

  tmp.x = (p->x * cos(a)) + (p->y * sin(a)) + (p->z * 0);
	tmp.y = (p->x * -sin(a)) + (p->y * cos(a)) + (p->z * 0);
	tmp.z = (p->x * 0) + (p->y * 0) + (p->z * 1);
  *p = tmp;
}
