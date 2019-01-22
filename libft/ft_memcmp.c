/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:35:37 by crenaudi          #+#    #+#             */
/*   Updated: 2018/11/12 14:34:34 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1bis;
	unsigned char	*s2bis;

	s1bis = (unsigned char *)s1;
	s2bis = (unsigned char *)s2;
	while (n > 0)
	{
		if (*s1bis != *s2bis)
			return (*s1bis - *s2bis);
		s1bis++;
		s2bis++;
		n--;
	}
	return (0);
}
