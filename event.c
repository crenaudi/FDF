/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:36:07 by crenaudi          #+#    #+#             */
/*   Updated: 2019/01/27 16:35:57 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int		deal_key(int key, void *param)
{
	ft_putnbr(key);
	if (key == ESC)
		exit(0);
	if (key == UP)
		exit(0);
	if (key == DOWN)
		exit(0);
	if (key == RIGHT)
		exit(0);
	if (key == LEFT)
		exit(0);
	return (0);
}

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
	return (0);
}
