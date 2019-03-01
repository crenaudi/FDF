#ifndef		GFX_H
# define	GFX_H

# include <math.h>

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
//float   interpolation(float t, float a, float b);
t_color init_color(t_color c, int color);
int     lerp_color(t_color a, t_color b, float t);
int     lerp_non_init_color(t_color color, int s, int e, float t);
float   deg2rad(float d);
float   rad2deg(float r);
void    scale(t_point *p, float e);
float   dot_product(t_vec3 a, t_vec3 b);
t_vec3  cross_product(t_vec3 a, t_vec3 b);
void    rotate_x(t_point *p, float a);
void    rotate_y(t_point *p, float a);
void    rotate_z(t_point *p, float a);

#endif
