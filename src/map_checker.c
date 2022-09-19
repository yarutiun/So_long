/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 14:20:18 by yarutiun          #+#    #+#             */
/*   Updated: 2022/09/19 15:35:49 by yarutiun         ###   ########.fr       */
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

// char **creat_matrix(char *map_path)
// {
//     t_data map;

//     map.fd = open(map_path, O_RDONLY);
//     x_y_of_map(map_path, map.map_height, map.map_width);
    
// }

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