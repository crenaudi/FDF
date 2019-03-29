/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:36:07 by crenaudi          #+#    #+#             */
/*   Updated: 2019/03/29 14:47:23 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

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

int		key_press_event(int key, void *param)
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

int		key_release_event(int key, void *param)
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

int		win_event(void *param)
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
