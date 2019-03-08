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

void legend(t_env *env)
{
	char *zoom;
	char *sommet;
	char *deplacement;
	char *projection;

	zoom = "ZOOM : 116 - 121";
	sommet = "MODIF HAUTEUR : 115 -119";
	deplacement = "DEPLACEMENT : fleche";
	projection = "PROJECTION : P, O";
	mlx_string_put(env->mlx_ptr, env->win_ptr, 10, 10, 0xFFFFFF, zoom);
	mlx_string_put(env->mlx_ptr, env->win_ptr, 10, 30, 0xFFFFFF, sommet);
	mlx_string_put(env->mlx_ptr, env->win_ptr, 10, 50, 0xFFFFFF, deplacement);
	mlx_string_put(env->mlx_ptr, env->win_ptr, 10, 70, 0xFFFFFF, projection);
}

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

int		event(int key, void *param)
{
	t_env *env;

	env = (void*)param;
	if (key == ESC)
	{
		parciel_clean_env(env);
		mlx_destroy_window(env->mlx_ptr, env->win_ptr);
		ft_bzero(env, sizeof(t_env));
		exit(0);
	}
	//ft_putnbr(key);
	if (key == ZOOM)
		env->scale += (float)0.5;
	if (key == DZOOM)
		env->scale -= (float)0.5;
	if (key == O)
	{
		env->rot_map.x = deg2rad(-25);
		env->rot_map.y = deg2rad(-25);
		env->rot_map.z = deg2rad(25);
	}
	if (key == P)
	{
		env->rot_map.x = deg2rad(0);
		env->rot_map.y = deg2rad(-25);
		env->rot_map.z = deg2rad(0);
	}
/*
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
*/
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
