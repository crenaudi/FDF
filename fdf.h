/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:12:16 by crenaudi          #+#    #+#             */
/*   Updated: 2019/01/21 18:47:15 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FDF_H
# define	FDF_H

#define ESC 53
#define LEFT 123
#define RIGHT 124
#define UP 126
#define DOWN 125

#include "mlx.h"
#include <stdio.h>
#include <string.h>
#include "libft/libft.h"

typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
}		t_mlx;

typedef struct s_fdf
{
	int	x;
	int	y;
	int	h;
	void	*next;
}		t_fdf;

int	deal_key(int key, void *param);
int	deal_mouse(int button, void *param);
void	is_error(int i);
void	stock_fdf(int fd);

#endif
