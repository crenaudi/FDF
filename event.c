/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:36:07 by crenaudi          #+#    #+#             */
/*   Updated: 2019/03/10 19:48:18 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void legend(t_env *env)
{
	mlx_string_put(env->mlx_ptr, env->win_ptr, 10, 20, 0xFFFFFFF, "ZOOM :");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 20, 40, 0x999999, "<- / ->");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 10, 70, 0xFFFFFFF, "DISPLACEMENT :");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 20, 90, 0x999999, "W / A / S / D");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 10, 120, 0xFFFFFF, "ANGLE :");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 20, 140, 0x999999, "(arrows)");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 10, 170, 0xFFFFFF, "PROJECTION :");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 20, 190, 0x999999, "I / O / P");
	//mlx_string_put(env->mlx_ptr, env->win_ptr, 10, 220, 0xFFFFFF, "HIGH :");
	//mlx_string_put(env->mlx_ptr, env->win_ptr, 20, 240, 0x999999, "|<- / ->|");
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

static void	move(int key, t_env *env)
{
	if (key == ZOOM)
		env->scale += (float)0.5;
	if (key == DZOOM)
		env->scale -= (float)0.5;
	if (key == UP)
		env->rot_map.x += deg2rad(-1);
	if (key == DOWN)
		env->rot_map.x += deg2rad(1);
	if (key == RIGHT)
		env->rot_map.y += deg2rad(-1);
	if (key == LEFT)
		env->rot_map.y += deg2rad(1);
	if (key == MOVE_U)
		env->trav.x -= 1;
	if (key == MOVE_D)
		env->trav.x += 1;
	if (key == MOVE_R)
		env->trav.y += 1;
	if (key == MOVE_L)
		env->trav.y -= 1;
}

int		event(int key, void *param)
{
	t_env *env;

	env = (void*)param;
	if (key == ESC)
	{
		parciel_clean_env(env);
		mlx_destroy_window(env->mlx_ptr, env->win_ptr);
		exit(0);
	}
	//ft_putnbr(key);
	//ft_putchar('\n');
	if (key == O)
	{
		env->is_spherical = 0;
		env->rot_map.x = deg2rad(-25);
		env->rot_map.y = deg2rad(-25);
		env->rot_map.z = deg2rad(25);
	}
	if (key == P)
	{
		env->is_spherical = 0;
		env->rot_map.x = deg2rad(0);
		env->rot_map.y = deg2rad(-25);
		env->rot_map.z = deg2rad(0);
	}
	if (key == I)
	{
		env->is_spherical = 1;
	}
	/*
	if (key == MOREH)
		env->high += (float)0.5;
	if (key == LESSH)
		env->high -= (float)0.5;
		*/
	move(key, env);
	generate(env);
	return (SUCCESS);
}
