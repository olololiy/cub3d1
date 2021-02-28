#include "lib.h"
t_config		ft_init_config(void)
{
	t_config 		config;

	config.r = 0;
	config.no = 0;
	config.so = 0;
	config.we = 0;
	config.ea = 0;
	config.s = 0;
	config.f = 0;
	config.c = 0;
	config.count_conf = 0;
	config.r_height = 0;
	config.r_weight = 0;
	return (config);
}

int main(int argc, char **argv)
{
	//int fd = open("/Users/vfurr/workplace/cub3d1/map.cub", O_RDONLY);
	//char *line = NULL;
	t_config config;

	config = ft_init_config();
	int check = parser(&config);// только парсер и отрисовка в мэйне


//	while (get_next_line(fd, &line))
//	{
//
//	}

}