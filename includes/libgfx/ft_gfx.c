#include <stdio.h>
#include "gfx.h"

/*
int lenght()
{
}
*/
float interpolation(float t, float a, float b)
{
  if (t == a)
    return (0);
  if (t == b)
    return (1);
  return ((t - a) / (b - a));
}

t_color init_color(t_color c, int color)
{
  int     mask;

  mask = 0xFF;
  c.r = (color >> 16) & mask;
  c.g = (color >> 8) & mask;
  c.b = (color >> 0) & mask;
  c.color = color;
  return (c);
}

int lerp_color(t_color s, t_color e, float t)
{
  int   r;
  int   g;
  int   b;

  if (s.color == e.color)
    return (s.color);
  r = s.r + ((e.r - s.r) * t);
  g = s.g + ((e.g - s.g) * t);
  b = s.b + ((e.b - s.b) * t);
  return (r << 16 | g << 8 | b);
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
