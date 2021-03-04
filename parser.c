//
// Created by Violet Furr on 2/21/21.
//
#include "lib.h"
//#include "get_next_line.h"
//int parser(char *strs)
//#include "libft1/libft.h"


int ft_resolution(char *line, t_config *config)
{
	//skip space
	int count;
	//int a;

	count = 0;
	line++;
	while (*line == ' ')
		line++;
	//if(ft_isdigit(*line))
	config->r_weight = ft_atoi(line);
	//else
	//	return (-1);
	//a = line;
	while (ft_isdigit(*line))
	{
		line++;
		count++;
	}
	//if (count > 4)
	//	return (-1);
	while (*line == ' ')
		line++;
	//ft_isdigit(5);
	config->r_height = ft_atoi(line);

	//isdigit yes=atoi no=error
	//while count isdigit
	// ifcount digit >5 errror
	// skip space
	// isdigit yes=atoi no=error \0 ?
	// skip space else error
	//config->r_height = ft_atoi(line + 1, config);
	//int weight


	return 0;
	//начинаем пытаться
}

int ft_texture(char *line, t_config *config)
{
	//char *b;
	line++;
	if (*line != 'O')
		return (-1);
	line++;

	config->no_texture = ft_strtrim(line, " ");
	return (0);
}

int ch_config2(char *line, t_config *config)
{
	//while(**line != '0' && **line != '1' && **line != ' ')

		if(*line == 'R')
			ft_resolution(line, config); //ft_r тут мы напишем функцию разрешения.
		else if(*line == 'N')
			ft_texture(line, config);
		else if(*line == 'S')
			;
		else if(*line == 'W')
			;
		else if(*line == 'E')
			;
		else if(*line == 'S')
			;
		else if(*line == 'F')
			;
		else if(*line == 'C')
			;
	return 1;
}

/*void	*ft_strchr(const void *s, int c)
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

int		ft_isalpha(int c)
{
	int b;
	if ((c > 64 && c < 91) || (c > 96 && c < 123))
		b = 1;
	else
		b = 0;
	return (b);
}
*/
int ch_config1(char *line, t_config *config)
{
	if (ft_strchr("RNSWESFC ", *line))
	{
		if (ft_isalpha(*line))
		{
			if(ch_config2(line, config))//там попытка занести все в структуру
				return 1;
			return -1;
		}
		else
			return 1;
	}
	else
		return -1;
}

int parser(t_config *config)
{

	int fd = open("/Users/vfurr/workplace/cub3d1/map.cub", O_RDONLY);
	char *line = NULL;

	while (get_next_line(fd, &line) > 0)
	{
		ch_config1(line, config);
	}
	return 0;
}
//void make_map(t_list **head, int size)
//{
//	char **map = ft_calloc(size + 1, sizeof(char *));
//	int i = -1;
//	t_list *tmp = *head;
//
//	while (tmp)
//	{
//		map[++i] = tmp->content;
//		tmp = tmp->next;
//	}
//	i = -1;
//	while (map[++i])
//	{
//		ft_putendl(map[i]);
//	}
//}

//int main(int argc, char **argv)
//{
//	int fd = open("/Users/vfurr/workplace/cub3d/map.cub", O_RDONLY);
//	char *line = NULL;
//	t_list *head = NULL;
//
//	while (get_next_line(fd, &line))
//	{
//		ft_lstadd_back (&head, ft_lstnew(line));
//	}
//	ft_lstadd_back (&head, ft_lstnew(line));
//	make_map(&head, ft_lstsize(head));
//}
