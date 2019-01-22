/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:12:16 by crenaudi          #+#    #+#             */
/*   Updated: 2019/01/21 18:47:15 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FDF_H
# define	FDF_H

#define ESC 53

#include <mlx.h>
#include <stdio.h>
#include <string.h>
#include "libft/libft.h"

typedef struct	s_mlx
{
		void	*mlx_ptr;
		void	*win_ptr;
}				t_mlx;

void	fdf();

#endif
