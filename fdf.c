/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:36:07 by crenaudi          #+#    #+#             */
/*   Updated: 2019/01/21 19:30:02 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		deal_key(int key, void *param)
{
	ft_putnbr(key);
	return (0);
}

int		main()
{
	void	*mlx_ptr;
	void	*win_ptr;
	

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 720, 473, "mlx_42");
//	mlx_key_hook(win_ptr, int (*mlx_destroy_window)(void *mlx_ptr, void *win_ptr), (void *)53);
	//pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFF);
	mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_loop(mlx_ptr);
	return (0);
}
