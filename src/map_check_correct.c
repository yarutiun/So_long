/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_correct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:49:08 by yarutiun          #+#    #+#             */
/*   Updated: 2022/09/21 12:20:30 by yarutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
//return 1 if success, 0 if not
int if_rectangle(char *map_path, char **map)
{
    t_data d;
    d.counter = 0;
    int i = 0;
    
    x_y_of_map(map_path, &d.map_height, &d.map_width);
    while(i < d.map_width)
    {
        if(map[0][i] != '1' && map[d.map_height - 1][i] != '1')
        {
            free_all_map(map);
            printf("asigdihaed");
            return(0);
        }
        i++;
    }
    while(d.counter < d.map_height)
    {
        if(map[d.counter][0] != '1' && map[d.counter][d.map_width - 1] != '1')
            {
                free_all_map(map);
                return(0);
            }
        d.counter ++;
    }
    return (1);
}
//return 1 if success, 0 if not
int if_one_player(char *map_path, char **map)
{
    t_data d;
    int i = 0;
    x_y_of_map(map_path, &d.map_height, &d.map_width);
    while (map[i] < map[d.map_height])
    {
        if(!ft_strchr(map[i], 'P'))
        {
            free_all_map(map);
            return (0);
        }
    }
    return (1);
}
//return 1 if success, 0 if not
int if_collectible(char *map_path, char **map)
{
    t_data d;
    int i = 0;
    x_y_of_map(map_path, &d.map_height, &d.map_width);
    while (map[i] < map[d.map_height])
    {
        if(!ft_strchr(map[i], 'E'))
        {
            free_all_map(map);
            return (0);
        }
    }
    return (1);
}
