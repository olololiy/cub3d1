/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 20:06:40 by vfurr             #+#    #+#             */
/*   Updated: 2020/11/19 23:09:23 by vfurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	*ft_strchr(const void *s, int c)
{
	unsigned char *g;

	g = (unsigned char*)s;
	c = (unsigned char)c;
	while (*g != '\0')
	{
		if (*g == c)
		{
			return (g);
		}
		g++;
	}
	if (c == '\0')
		return (g);
	return (0);
}
