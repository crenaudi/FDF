/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:36:07 by crenaudi          #+#    #+#             */
/*   Updated: 2019/02/09 14:29:04 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	is_error(int i)
{
	if (i == -1)
	{
		perror("Error ");
		exit(EXIT_FAILURE);
	}
	if (i == 0)
		exit(EXIT_SUCCESS);
}

static void clear_img(t_env *env, t_img *img)
{
	ft_bzero(img, sizeof(t_img));
	mlx_destroy_image(env->mlx_ptr, img->ptr);
}

int		event(int key, void *param)
{
	t_env *env;

	env = (void*)param;
	if (key == ESC)
	{
		mlx_destroy_window(env->mlx_ptr, env->win_ptr);
		exit(0);
	}
	if (key == ZOOM)
		env->scale += (float)0.1;
	if (key == DZOOM)
		env->scale -= (float)0.1;
	if (key == UP)
		env->c.y += (float)1;
	if (key == DOWN)
		env->c.y += (float)1;
	if (key == RIGHT)
		env->c.x += (float)1;
	if (key == LEFT)
		env->c.x -= (float)1;
	if (key == MOREH)
		env->c.z += (float)1;
	if (key == LESSH)
		env->c.z -= (float)1;
	clear_img(env, env->img);
	return (SUCCESS);
}
/*
int		deal_mouse(int button, void *param)
{
//	if (button == R_MOUSSE)
//		exit(0);
//	if (button == L_MOUSSE)
//		exit(0);
	if (button == SCROLL_UP)
		exit(0);
	if (button == SCROLL_DOWN)
		exit(0);
	return (SUCCESS);
}*/
