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

# define ERROR 				-1
# define SUCCESS			0
# define ESC					53
# define LEFT					123
# define RIGHT				124
# define UP						126
# define DOWN					125
# define ZOOM					116
# define DZOOM				121
# define MOREH				115
# define LESSH				119


typedef struct	s_env			t_env;
typedef struct	s_p				t_p;
typedef struct	s_trace		t_trace;
typedef struct	s_img			t_img;


struct	s_env
{
	void						*mlx_ptr;
	void						*win_ptr;
	void						*img_ptr;
	struct s_img		*img;
	t_point 				**tab_point;
	struct s_p			*p;
	float						scale;
	struct s_color	color;
	t_vec3					rot_map;
	t_vec3					c;
	int							y_max;
	int							x_max;
};

struct	s_p
{
	float				x;
	float				y;
	float				z;
	struct s_p	*next;
};

struct	s_trace
{
	t_vec2					p1;
	t_vec2					p2;
	t_vec2					dir;
	t_vec2					sens;
	float							t;
	struct s_color	color;
};

struct	s_img
{
	char		*data;
	int			bpp;
	int			sl;
	int			endian;
};

int			event(int key, void *param);
void		is_error(int i);
int			stock_env(int fd, t_env *env);
int			converte(t_env *env);
int			affichage(t_env *env, t_point **coord);
int			trace(t_env *env, t_point **coord);

#endif
