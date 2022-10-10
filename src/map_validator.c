/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 14:20:18 by yarutiun          #+#    #+#             */
/*   Updated: 2022/10/10 20:35:33 by yarutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/so_long.h"
//returns 0 if fail, 1 if success
void mega_map_check(int argc, char **argv, char **mlx_map)
{
    if (argc != 2)
    {
        ft_putstr_fd("There are some missing arguments!");
        exit(EXIT_FAILURE);
    }
    if(if_correct_symbols(argv[1], mlx_map) == 1)
    {
        ft_putstr_fd("There are some incorrect characters on your map!");
        exit(EXIT_FAILURE);
    }
    if (if_ber_file(argv[1]) != 0)
    {
        write(1, "Your file is not a .ber file!", 30);
        exit(EXIT_FAILURE);
    }
    if(if_collectible(mlx_map) != 1 || if_exit(argv[1], mlx_map) != 1)
    {
        ft_putstr_fd("There are no collectibles or exits!");
        exit(EXIT_FAILURE);
    }
    if (if_one_player(argv[1], mlx_map) != 1)
    {
        ft_putstr_fd("There is not only 1 player");
        exit(EXIT_FAILURE);
    }
    if (if_rectangle(argv[1], mlx_map) == 1)
    {
        ft_putstr_fd("not a rectangle");
        exit(EXIT_FAILURE);
    }
}

void x_y_of_map(char *map_adress, int *map_height, int *map_width)
{
    t_mlx info;
    char *str;
    
    info.fd = open(map_adress, O_RDONLY);
    if (info.fd < 0)
        exit(0);
    *map_height = 0;
    str = get_next_line(info.fd);
    *map_width = (int)(ft_strlen(str) -1);
    while(1)
    {
        *map_height += 1;
        free(str);
        str = get_next_line(info.fd);
        if(str == NULL)
        {
            break;
        }
    }
    close (info.fd);
}

char **create_matrix(char *map_path)
{
    t_mlx map;
    map.counter = 0;
    
    map.fd = open(map_path, O_RDONLY);
    x_y_of_map(map_path, &map.map_height, &map.map_width);
    map.map = malloc(sizeof(char *) * map.map_height + 1);
    if (!map.map)
    {
        free(map.map);    
        exit(EXIT_FAILURE);
    }
    while(map.counter != map.map_height)
    {
        map.map[map.counter] = get_next_line(map.fd);
        if (!map.map[map.counter])
        {
            free(map.map[map.counter]);
            exit(EXIT_FAILURE);
        }
        map.counter ++;
    }
    map.map[map.counter] = NULL;
    return(map.map);
}

void free_all_map(char **map)
{
    int counter = 0;

    while (map[counter] != NULL)
    {
        free(map[counter]);
        counter ++;
    }
    free(map);
}