//
// Created by Violet Furr on 2/21/21.
//
#include "lib.h"

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
}

char *ft_texture(char *line, t_config *config)
{
	char *temp;
	line++;
	//if (*line != 'O')
	//	return (0);
	line++;

	temp = ft_strtrim(line, " ");
	return (temp);
}

int ft_color(char *line, t_config *config)
{
	//strtrim(line)
	//isdigit()
	//atoi
	//int < 256
	//skipspace
	//skip,
	//skipspace
	//isdigigt
	//atoi
	//int < 256


//	temp = ft_atoi(*line);
	int count;

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

}

int ch_config2(char *line, t_config *config)
{
		if(*line == 'R')
			ft_resolution(line, config); //ft_r тут мы напишем функцию разрешения.
		else if(line[0] == 'N' && line[1] == 'O')
			config->no_texture = ft_texture(line, config);
		else if(*line == 'S' && line[1] == 'O')
			config->so_texture = ft_texture(line, config);
		else if(*line == 'W' && line[1] == 'E')
			config->wo_texture = ft_texture(line, config);
		else if(*line == 'E' && line[1]== 'A')
			config->eo_texture = ft_texture(line, config);
		else if(*line == 'S' && line[1]== ' ')
			config->sprite_texture = ft_texture(line, config);
		else if(*line == 'F')
			;
		else if(*line == 'C')
			;
		else
			return (-1);
	return 1;
}


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

	int fd = open("/Users/vfurr/workplace/cub3d11/map.cub", O_RDONLY);
	char *line = NULL;

	while (get_next_line(fd, &line) > 0)
	{
		ch_config1(line, config);
	}
	return 0;
}
