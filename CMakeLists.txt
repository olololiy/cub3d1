cmake_minimum_required(VERSION 3.17)
project(cub3d1 C)

set(CMAKE_C_STANDARD 11)

add_executable(cub3d1
        main.c parser.c get_next_line.c libft.a)
target_link_libraries( cub3d1 /Users/vfurr/workplace/libft/libft.a)