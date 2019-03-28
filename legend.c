/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   legend.c                                            :+:      :+:    :+:   */
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
