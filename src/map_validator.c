/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 14:20:18 by yarutiun          #+#    #+#             */
/*   Updated: 2022/09/21 11:54:05 by yarutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/so_long.h"

void x_y_of_map(char *map_adress, int *map_height, int *map_width)
{
    t_data info;
    char *str;
    
    info.fd = open(map_adress, O_RDONLY);
    if (info.fd < 0)
    {
       ft_putstr_fd("Something is wrong with your map! Can't open the file.", 1);
        exit(0);
    }
    *map_height = 0;
    str = get_next_line(info.fd);
    *map_width = (int)(ft_strlen(str) -1);
    while(1)
    {
        *map_height += 1;
        str = get_next_line(info.fd);
        if(str == NULL)
        {
            break;
        }
        free(str);
    }
    close (info.fd);
}

char **create_matrix(char *map_path)
{
    t_data map;
    map.counter = 0;
    
    map.fd = open(map_path, O_RDONLY);
    x_y_of_map(map_path, &map.map_height, &map.map_width);
    map.map = malloc(sizeof(char *) * map.map_height + 1);
    if (!map.map)
        exit(EXIT_FAILURE);
    while(map.counter != map.map_height)
    {
        map.map[map.counter] = get_next_line(map.fd);
        if (!map.map[map.counter])
        {
            free(map.map[map.counter]);
            exit(EXIT_FAILURE);
        }
        // read(map.fd, map.map[map.counter], map.map_width + 1);
        // map.map[map.counter][map.map_width + 1] = '\0';
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