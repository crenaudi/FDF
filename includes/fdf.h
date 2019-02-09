/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:12:16 by crenaudi          #+#    #+#             */
/*   Updated: 2019/02/03 19:44:43 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FDF_H
# define	FDF_H

#define RGB(r, g, b)(256 * 256 * (int)(r) + 256 * (int)(g) + (int)(b))
#define ESC			53
#define LEFT		123
#define RIGHT		124
#define UP			126
#define DOWN		125
#define L_MOUSSE	1
#define	R_MOUSSE	2
#define SCROLL_UP	5
#define SCROLL_DOWN	7

#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../libft/libft.h"

typedef struct	s_fdf
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*img;
	int				bpp;
	int				sl;
	int				endian;
	struct s_p		*p;
	struct s_cam	*cam;
	double			e;
	double			color;
	int				y_max;
	int				x_max;
}				t_fdf;

typedef struct	s_p
{
	double		x;
	double		y;
	double		z;
	double		cx;
	double		cy;
	double		cz;
	struct s_p	*next;
}				t_p;

typedef struct	s_index
{
	int				x;
	int				y;
}								t_index;

typedef struct	s_cam
{
	double	vx;
	double	vy;
	double	vz;
	double	vleng;
	struct s_cam	*next;
}				t_cam;

int		deal_key(int key, void *param);
int		deal_mouse(int button, void *param);
void	is_error(int i);
int		stock_fdf(int fd, t_fdf *fdf);
void	converte(t_fdf fdf, t_p *p);
int		affichage(t_fdf fdf, t_p *p);
int		line(t_fdf fdf, t_p *p1, t_p *p2);

#endif
