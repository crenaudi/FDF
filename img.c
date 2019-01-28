/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:36:07 by crenaudi          #+#    #+#             */
/*   Updated: 2019/01/27 16:40:16 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "includes/fdf.h"

int		deal_key(int key, void *param)
{
	int *i;

	i = (int *)param;
	if (key == ESC)
		exit(1);
	else if (key == UP)
		*i += 1;
	else if (key == DOWN)
		*i -= 1;
	else if (key == RIGHT)
		printf("%d\n", *i);
	return (0);
}

int		main()
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		width;
	int		height;
	int		x;
	int		y;
	int		i;

	i = 0;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 720, 473, "mlx_42");
	mlx_key_hook(win_ptr, deal_key, (void *)&i);
	img_ptr = mlx_xpm_file_to_image(mlx_ptr, "cat.xpm", &width, &height);
	x = (720 - width) / 2;
	y = (473 - height) / 2;
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, x, y);
	if (img == NULL)
	{
		is_perror(-1);
	}
	printf("%d\n %d\n", width, height);
	mlx_loop(mlx_ptr);
	return (0);
}
