/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:12:16 by crenaudi          #+#    #+#             */
/*   Updated: 2019/02/15 19:23:50 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FDF_H
# define	FDF_H

# include "mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include "libft.h"
# include "gfx.h"

# define ERROR -1
# define SUCCESS 0
// utiliser << plutot
//# define RGB(r, g, b)(256 * 256 * (int)(r) + 256 * (int)(g) + (int)(b))
# define ESC			53
# define LEFT		123
# define RIGHT		124
# define UP			126
# define DOWN		125
# define L_MOUSSE	1
# define	R_MOUSSE	2
# define SCROLL_UP	5
# define SCROLL_DOWN	7

//foreward declaretion
//typedef int t_vec2 __attribute__((ext_vector_type(2)));
//typedef double t_vec3 __attribute__((ext_vector_type(3)));

typedef struct	s_fdf					t_fdf;
typedef struct	s_p						t_p;
//typedef t_vec3								t_point;
typedef struct	s_bresenham		t_bresenham;

struct	s_fdf
{
	void					*mlx_ptr;
	void					*win_ptr;
	void					*img_ptr;
	char					*img;
	int						bpp;
	int						sl;
	int						endian;
	t_point 			**tab_point;
	struct s_p		*p;
	struct s_cam	*cam;
	float				scale;
	float				color;
	t_vec3				rot_map;
	int						y_max;
	int						x_max;
};

struct	s_p
{
	float			x;
	float			y;
	float			z;
	struct s_p	*next;
};

struct	s_bresenham
{
	t_vec2	p1;
	t_vec2	p2;
	t_vec2	dir;
	t_vec2	sens;
};

int			deal_key(int key, void *param);
int			deal_mouse(int button, void *param);
void		is_error(int i);
int			stock_fdf(int fd, t_fdf *fdf);
int			converte(t_fdf *fdf);
int			affichage(t_fdf *fdf, t_point **coord);
void		line(t_fdf *fdf, t_point p1, t_point ip2);

#endif
