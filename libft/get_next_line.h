/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 13:58:03 by crenaudi          #+#    #+#             */
/*   Updated: 2018/12/13 15:56:34 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

typedef struct		s_gnl
{
	struct s_gnl	*next;
	char			*rest;
	int				fd;
}					t_gnl;
int					get_next_line(const int fd, char **line);
int					grep_next_line(const int fd, char *needle, char **line);

#endif
