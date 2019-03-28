/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:36:07 by crenaudi          #+#    #+#             */
/*   Updated: 2019/03/10 19:47:14 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "includes/fdf.h"

static int init_env(t_env *env, float scale)
{
	t_img *img;

	if (!(img = (t_img *)malloc(sizeof(t_img))))
		return (ERROR);
	ft_bzero(img, sizeof(t_img));
	ft_bzero(env, sizeof(t_env));
	env->mlx_ptr = mlx_init();
	env->win_ptr = mlx_new_window(env->mlx_ptr, WIN_W, WIN_H, "mlx_42");
	img->ptr = mlx_new_image(env->mlx_ptr, WIN_W, WIN_H);
	img->data = (int *)(mlx_get_data_addr(img->ptr, &img->bpp, &img->sl, &img->endian));
	env->img = img;
	env->rot_map.x = deg2rad(-50);
	env->rot_map.y = deg2rad(-50);
	env->rot_map.z = deg2rad(30);
	env->scl = scale;
	return (SUCCESS);
}

static void	is_move(t_env *env)
{
	t_vec2	dir;
	t_vec3	view;

	dir = 0;
	view = 0;
	if (env->up != 0)
		dir.x -= 1;
	if (env->down != 0)
		dir.x += 1;
	if (env->left != 0)
		dir.y -= 1;
	if (env->right != 0)
		dir.y += 1;
	if (env->v_up != 0)
		view.x += deg2rad(-1);
	if (env->v_down != 0)
		view.x += deg2rad(1);
	if (env->v_right != 0)
		view.y += deg2rad(-1);
	if (env->v_left != 0)
		view.y += deg2rad(1);
	env->tr += dir;
	env->rot_map.x += view.x;
	env->rot_map.y += view.y;
}

int	generate(void *param)
{
	t_env		*env;
	float	zoom;

	env = (t_env *)param;
	zoom = 0;
	if (env->front != 0)
		zoom += 0.5f;
	if (env->back != 0)
		zoom -= 0.5f;
	env->scl += zoom;
	is_move(env);
	converte(env);
	env->bert += 0.05;
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img->ptr, 0, 0);
	legend(env);
	return (SUCCESS);
}


int		main(int argc, char **argv)
{
	t_env		env;
	int			fd;
	float		scale;

	if (argc != 2)
	{
		ft_putstr("Usage: ./env <filename>\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY | O_NOFOLLOW);
	if (fd < 0 || ft_strcmp(ft_strstr(argv[1], ".fdf"), ".fdf") != 0)
		is_error(-1);
	scale = ft_strstr(argv[1], "mars") != 0 ? 5.0f : 20.0f;
	if (init_env(&env, scale) == ERROR)
		exit (0);
	stock_env(fd, &env);
	mlx_loop_hook (env.mlx_ptr, generate, (void *)&env);
	mlx_hook(env.win_ptr, 2, 0, key_press_event, (void *)&env);
	mlx_hook(env.win_ptr, 3, 0, key_release_event, (void *)&env);
	mlx_hook(env.win_ptr, 12, 0, win_event, (void *)&env);
	mlx_loop(env.mlx_ptr);
	return (0);
}
