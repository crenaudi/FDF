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
	env->win_ptr = mlx_new_window(env->mlx_ptr, W_WIDTH, W_HEIGHT, "mlx_42");
	img->ptr = mlx_new_image(env->mlx_ptr, W_WIDTH, W_HEIGHT);
	img->data = (int *)(mlx_get_data_addr(img->ptr, &img->bpp, &img->sl, &img->endian));
	env->img = img;
	env->rot_map.x = deg2rad(-50);
	env->rot_map.y = deg2rad(-50);
	env->rot_map.z = deg2rad(30);
	env->scale = scale;
	return (SUCCESS);
}

int	generate(void *param)
{
	t_env	*env;

	env = (void *)param;
	converte(env);
	env->bertrand += 0.05;
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
	scale = ft_strstr(argv[1], "mars") != 0 ? (float)4.5 : (float)16.0;
	if (init_env(&env, scale) == ERROR)
		exit (0);
	stock_env(fd, &env);
	mlx_loop_hook (env.mlx_ptr, generate, (void *)&env);
	mlx_key_hook(env.win_ptr, event, (void *)&env);
	mlx_hook(env.win_ptr, x_event, 0, int (*funct)(), void *param);
	mlx_loop(env.mlx_ptr);
	return (0);
}
