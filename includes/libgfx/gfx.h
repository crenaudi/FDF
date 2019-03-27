#ifndef		GFX_H
# define	GFX_H

# include <math.h>
# include "../libft/libft.h"

typedef int t_vec2 __attribute__((ext_vector_type(2)));
typedef float t_vec3 __attribute__((ext_vector_type(3)));
typedef t_vec3 t_point;
typedef struct s_color t_color;

struct  s_color
{
  int   r;
  int   g;
  int   b;
  int   color;
};

float   vec2_dist(t_vec2 v2);
t_color init_color(int color);
int     lerp_color(t_color s, t_color e, float t);
int     lerp_non_init_color(int a, int b, float t);
float   deg2rad(float d);
float   rad2deg(float r);
void    scale(t_point *p, float e);
float   dot_product(t_vec3 a, t_vec3 b);
t_vec3  cross_product(t_vec3 a, t_vec3 b);
void    rotate_x(t_point *p, float a);
void    rotate_y(t_point *p, float a);
void    rotate_z(t_point *p, float a);
t_point normalize(t_point v);

float   spherical_theta(t_point v);
float   spherical_phi(t_point v);
t_point to_vec_spherical(t_point v);
void    spherical_perspective(t_point v, t_point *p);

//void    sph_point(float lat, float lg, t_point *p);
//void    sph_perspective(t_point u, t_point v, t_point *p, float x, float y);

#endif
