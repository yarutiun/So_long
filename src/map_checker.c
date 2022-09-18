/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 14:20:18 by yarutiun          #+#    #+#             */
/*   Updated: 2022/09/18 17:06:28 by yarutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void x_y_of_map(char *map_adress, int *map_height, int *map_width)
{
    t_data info;
    char *str;
    
    info.fd = open(map_adress, O_RDONLY);
    if (info.fd < 0)
    {
        ft_printf("Something is wrong with your map! Can't open the file.");
        exit(0);
    }
    *map_height = 0;
    str = get_next_line(info.fd);
    *map_width = (int)ft_strlen(str);
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