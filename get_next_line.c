/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 15:29:15 by vfurr             #+#    #+#             */
/*   Updated: 2020/12/31 00:31:27 by vfurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "lib.h"
size_t		ft_strlenn(const char *str)
{
	int i;

	i = 0;
	while (str && *str != '\0' && *str != '\n')
	{
		str++;
		i++;
	}
	return (i);
}

char		*ft_strjoinn(char *line, char **buf, int i, int length2)
{
	int		length1;
	char	*new_line;

	length2 = ft_strlenn(*buf);
	length1 = ft_strlenn(line);
	if (!(new_line = (char *)malloc(sizeof(char) * (length1 + length2 + 1))))
	{
		free(line);
		return (0);
	}
	while (line && line[++i] != '\0')
	{
		*new_line = line[i];
		new_line++;
	}
	free(line);
	while (**buf != '\0' && **buf != '\n')
	{
		*new_line = **buf;
		(*buf)++;
		new_line++;
		i++;
	}
	*new_line = '\0';
	return (new_line - i);
}
int		check_ok(int fd, char **line)
{
	if (!line)
		return (-1);
	else
	{
		if (!(*line = malloc(sizeof(char))))
			return (-1);
		(*line)[0] = '\0';
	}
	if (!line || (read(fd, 0, 0)) < 0 || (BUFFER_SIZE < 1))
		return (-1);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	strong_buf[BUFFER_SIZE + 1];
	static int	size;
	static char	*buf;

	if (check_ok(fd, line) < -1)
		return (-1);
	while (buf == NULL || *buf != '\n')
	{
		if (buf == NULL || *buf == '\0')
		{
			strong_buf[0] = '\0';
			size = read(fd, strong_buf, BUFFER_SIZE);
			strong_buf[size] = '\0';
			buf = strong_buf;
		}
		if (size == 0)
			return (0);
		if (size < 0)
			return (-1);
		*line = ft_strjoinn(*line, &buf, -1, 0);
		if (*line == NULL)
			return (-1);
	}
	buf++;
	return (1);
}
