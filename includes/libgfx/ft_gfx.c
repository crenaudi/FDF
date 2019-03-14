#include <stdio.h>
#include "gfx.h"

float vec2_dist(t_vec2 v2)
{
     return (sqrt(v2.x * v2.x + v2.y * v2.y));
}

t_color init_color(int color)
{
  t_color   c;
  int       mask;

  ft_bzero(&c, sizeof(t_color));
  mask = 0xFF;
  c.r = (color >> 16) & mask;
  c.g = (color >> 8) & mask;
  c.b = color & mask;
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
  r = (int)(s.r + (e.r - s.r) * t);
  g = (int)(s.g + (e.g - s.g) * t);
  b = (int)(s.b + (e.b - s.b) * t);
  return (((r & 0xFF) << 16) | ((g  & 0xFF) << 8) | (b & 0xFF));
}

int lerp_non_init_color(int a, int b, float t)
{
  return (lerp_color(init_color(a), init_color(b), t));
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

void spherical_theta(t_vec3 *v)
{
  return (acos(v.z, -1, 1));
}

void spherical_phi(t_vec3 *v)
{
  float tmp;

  tmp = atan2(v.y, v.x);
  return (tmp < 0 ? tmp + 2 * M_PI : tmp);
}

void to_vec_spherical(t_vec3 *v)
{
  t_vec3  tmp;
  float   theta;
  float   phi;

  theta = spherical_theta(t_vec3 *v);
  phi = spherical_teta(t_vec3 *v);
  v.x = cos(phi) * sin(theta);
  v.y = sin(phi) * sin(theta);
  v.z = cos(theta);
  *v = tmp
}

void spherical_perspective(t_vec3 v, t_point *p)
{
  t_vec3  tmp;

  tmp.x = (v.x * p->x) + (v.y * p->y) + (v.z * p->z);
	tmp.y = (v.x * p->x) + (v.y * p->y) + (v.z * p->z);
	tmp.z = (v.x * p->x) + (v.y * p->y) + (v.z * p->z);
  *p = tmp;
}
