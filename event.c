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
	mlx_string_put(env->mlx_ptr, env->win_ptr, 20, 190, 0x999999, "O / P");
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

int		event(int key, t_env *env)
{
	if (key == ESC)
	{
		parciel_clean_env(env);
		mlx_destroy_window(env->mlx_ptr, env->win_ptr);
		exit(0);
	}
	if (key == O)
	{
		env->rot_map.x = deg2rad(-50);
		env->rot_map.y = deg2rad(-50);
		env->rot_map.z = deg2rad(30);
	}
	if (key == P)
	{
		env->rot_map.x = deg2rad(-25);
		env->rot_map.y = deg2rad(0);
		env->rot_map.z = deg2rad(0);
	}
	return (SUCCESS);
}

int	key_press_event(int key, void *param)
{
	t_env	*env;

	env = (t_env *)param;
	if (key == MOVE_U)
		env->up = 1;
	if (key == MOVE_D)
		env->down = 1;
	if (key == MOVE_R)
		env->right = 1;
	if (key == MOVE_L)
		env->left = 1;
	if (key == ZOOM)
		env->front = 1;
	if (key == DZOOM)
		env->back = 1;
	if (key == UP)
		env->v_up = 1;
	if (key == DOWN)
		env->v_down = 1;
	if (key == RIGHT)
		env->v_left = 1;
	if (key == LEFT)
		env->v_right = 1;
	event(key, env);
	return (0);
}

int	key_release_event(int key, void *param)
{
	t_env	*env;

	env = (t_env *)param;
	if (key == MOVE_U)
		env->up = 0;
	if (key == MOVE_D)
		env->down = 0;
	if (key == MOVE_R)
		env->right = 0;
	if (key == MOVE_L)
		env->left = 0;
	if (key == ZOOM)
		env->front = 0;
	if (key == DZOOM)
		env->back = 0;
	if (key == UP)
		env->v_up = 0;
	if (key == DOWN)
		env->v_down = 0;
	if (key == RIGHT)
		env->v_left = 0;
	if (key == LEFT)
		env->v_right = 0;
	return (0);
}

int	win_event(void *param)
{
	t_env	*env;

	env = (t_env *)param;
	env->up = 0;
	env->down = 0;
	env->left = 0;
	env->right = 0;
	env->front = 0;
	env->back = 0;
	return (0);
}
