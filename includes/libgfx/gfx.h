#ifndef		GFX_H
# define	GFX_H

# include <math.h>

typedef int t_vec2 __attribute__((ext_vector_type(2)));
typedef float t_vec3 __attribute__((ext_vector_type(3)));
typedef t_vec3 t_point;
typedef struct s_color t_color;
struct  s_color
{
  t_vec3  rgb;
  int     color;
};

float   deg2rad(float d);
float   rad2deg(float r);
void    scale(t_point *p, float e);
float   dot_product(t_vec3 a, t_vec3 b);
t_vec3  cross_product(t_vec3 a, t_vec3 b);
void    rotate_x(t_point *p, float a);
void    rotate_y(t_point *p, float a);
void    rotate_z(t_point *p, float a);

#endif
