/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:36:07 by crenaudi          #+#    #+#             */
/*   Updated: 2019/02/15 19:24:28 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "includes/fdf.h"

static void init_env(t_env *env, int x, int y)
{
	t_color color;

	ft_bzero(&color, sizeof(t_color));
	env->rot_map.x = deg2rad(-45);
	env->rot_map.y = deg2rad(-25);
	env->rot_map.z = deg2rad(25);
	env->scale = (float)20.0;
	env->c.x = (float)8.0;
	env->c.y = (float)44.0;
	env->c.z = (float)0.0;
	env->color = init_color(color, 0x000000);
	env->z_min = 0.0;
	env->z_max = 0.0;
	env->x = (float)x;
	env->y = (float)y;
	env->bertrand = 0;
}
/*
void init_img(t_env *env)
{
	t_img *img;

	ft_bzero(&img, sizeof(t_img));
	img->data = mlx_new_image(img.data, y, x);
	mlx_get_data_addr(img->data, &img->bpp, &img->sl, &img->endian);
	fdf->img = img;
}
*/
int	generate(t_env *env)
{
	converte(env);
	env->bertrand += 0.1;
	//mlx_put_image_to_window(env, env->img, env->win_ptr, 0, 0);
	return (SUCCESS);
}

int		main(int argc, char **argv)
{
	t_env		env;
	int			fd;
	int			x;
	int			y;

	y = 1200;
	x = 600;
	if (argc != 2)
	{
		ft_putstr("Usage: ./env <filename>\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY | O_NOFOLLOW);
	if (fd < 0 || ft_strstr(argv[1], ".fdf") == 0)
		is_error(-1);

	init_env(&env, x, y);
	env.mlx_ptr = mlx_init();
	env.win_ptr = mlx_new_window(env.mlx_ptr, y, x, "mlx_42");
	stock_env(fd, &env);
	//init_img(&env);

	mlx_loop_hook (env.mlx_ptr, generate, (void *)&env);
	mlx_key_hook(env.win_ptr, event, (void *)&env);
	mlx_loop(env.mlx_ptr);
	return (0);
}
