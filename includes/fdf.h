/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:12:16 by crenaudi          #+#    #+#             */
/*   Updated: 2019/01/27 16:56:49 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FDF_H
# define	FDF_H

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
#include "../libft/libft.h"

typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
}		t_mlx;

typedef struct	s_fdf
{
	struct s_p	*p;
	struct s_cam	*cam;
	double			e;
	int		delta;
	int		nb_p;
	int		y_max;
	int		x_max;
	int		z_max;
}				t_fdf;

typedef struct	s_p
{
	double		x;
	double		y;
	double		z;
	struct s_p	*next;
}				t_p;

typedef struct	s_cam
{
	double	x;
	double	y;
	double	z;
	double	vx;
	double	vy;
	double	vz;
	double	vleng;
	struct s_cam	*next;
}

int		deal_key(int key, void *param);
int		deal_mouse(int button, void *param);
void	is_error(int i);
int		stock_fdf(int fd, t_fdf *fdf);

#endif
