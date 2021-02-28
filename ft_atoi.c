/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 22:23:37 by vfurr             #+#    #+#             */
/*   Updated: 2020/11/26 20:01:33 by vfurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include "lib.h"

static	char	*emptychar(char *s)
{
	while ((*s >= 9 && *s <= 13) || *s == ' ')
		s++;
	return (s);
}

static	char	*skipzero(char *s)
{
	while (*s == '0')
		s++;
	return (s);
}

static	int		onlydigit(char *s, t_config *config)
{
	int (result);

	result = 0;
	while (*s > 47 && *s < 58)
	{
		result = result * 10 + (*s - '0');
		s++;
	}
	//ft_atoi
	return (result);
}

int				ft_atoi(const	char *str, t_config *config)
{
	char	*s;
	int		neg;
	int		result;

	result = 0;
	neg = 1;
	s = (char*)str;
	s = emptychar(s);
	if (!s)
		return (0);
	if (*s == '-')
	{
		neg = -1;
		s++;
	}
	else if (*s == '+')
		s++;
	s = skipzero(s);
	result = onlydigit(s, config);

	return (result * neg);

}
