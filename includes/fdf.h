/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:12:16 by crenaudi          #+#    #+#             */
/*   Updated: 2019/03/29 15:08:05 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include "libft/libft.h"
# include "libgfx/gfx.h"

# define ERROR 			-1
# define SUCCESS		0
# define WIN_W			1200
# define WIN_H			 600
# define P				35
# define O				31
# define ESC			53
# define MOVE_U			13
# define MOVE_D			1
# define MOVE_R			2
# define MOVE_L			0
# define LEFT			123
# define RIGHT			124
# define UP				126
# define DOWN			125
# define ZOOM			116
# define DZOOM			121

typedef struct s_env	t_env;
typedef struct s_p		t_p;
typedef struct s_trace	t_trace;
typedef struct s_img	t_img;

struct					s_env
{
	void				*mlx_ptr;
	void				*win_ptr;
	t_point				**tab_p;
	t_point				**tab_m;
	char				*line;
	struct s_p			*p;
	t_img				*img;
	t_vec3				rot_map;
	t_vec2				tr;
	int					y_max;
	int					x_max;
	float				z_min;
	float				z_max;
	float				scl;
	float				bert;
	int					up;
	int					down;
	int					right;
	int					left;
	int					front;
	int					back;
	int					v_up;
	int					v_down;
	int					v_right;
	int					v_left;
};

struct					s_p
{
	float				x;
	float				y;
	float				z;
	struct s_p			*next;
};

struct					s_trace
{
	t_vec2				p1;
	t_vec2				p2;
	t_vec2				dir;
	t_vec2				sens;
	float				t;
	struct s_color		c1;
	struct s_color		c2;
};

struct					s_img
{
	void				*ptr;
	int					*data;
	int					bpp;
	int					sl;
	int					endian;
};

int						event(int key, t_env *env);
void					legend(t_env *env);
void					is_error(int i);
int						stock_env(int fd, t_env *env);
int						generate(void *param);
int						converte(t_env *env);
void					line(t_env *env, t_point p1, t_point p2, t_vec3 z);
int						affichage(t_env *env, t_point **coord);
void					clean_tab(t_point **coord, int coord_y);
void					clean_image(t_img *img);
void					kill_image(t_env *env, t_img *img);
void					parciel_clean_env(t_env *env);
int						key_press_event(int key, void *param);
int						key_release_event(int key, void *param);
int						win_event(void *param);

#endif
