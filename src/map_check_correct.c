/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_correct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:49:08 by yarutiun          #+#    #+#             */
/*   Updated: 2022/09/30 01:15:52 by yarutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
//return 1 if success, 0 if not
int if_rectangle(char *map_path, char **map)
{
    t_mlx d;
    d.counter = 0;
    int i = 0;
    
    x_y_of_map(map_path, &d.map_height, &d.map_width);
    while(i < d.map_width)
    {
        if(map[0][i] != '1' && map[d.map_height - 1][i] != '1')
        {
            free_all_map(map);
            return (0);
        }
        i++;
    }
    while(d.counter < d.map_height)
    {
        if(map[d.counter][0] != '1' && map[d.counter][d.map_width - 1] != '1')
            {
                free_all_map(map);
                return (0);
            }
        d.counter ++;
    }
    return (1);
}
//return 1 if success, 0 if not
int if_one_player(char *map_path, char **map)
{
    t_mlx d;
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
    t_mlx d;
    int i = 0;
    x_y_of_map(map_path, &d.map_height, &d.map_width);
    while (map[i] < map[d.map_height])
    {
        if((!ft_strchr(map[i], 'E')) || (!ft_strchr(map[i], 'C')))
        {
            free_all_map(map);
            return (0);
        }
        i++;
    }
    return (1);
}
// if there are no more symbols in map but '1' '0' 'c' 'e' 'p' then return value is 1, if else - return value is 0
int if_correct_symbols(char *map_path, char **map)
{
    t_mlx d;
    d.counter = 0;
    d.counter2 = 0;

    x_y_of_map(map_path, &d.map_height, &d.map_width);
    while (map[d.counter] != map[d.map_height - 1])
    {
        while (map[d.counter][d.counter2] != map[d.counter][d.map_width - 1])
        {
            if (map[d.counter][d.counter2] != '1' && map[d.counter][d.counter2] != '0'
             && map[d.counter][d.counter2] != 'C' && map[d.counter][d.counter2] != 'E'
             && map[d.counter][d.counter2] != 'P')
             {
                free_all_map(map);
                return (0);
             }
            d.counter2 ++;
        }
        d.counter ++;
    }
    return (1);
}
//returns 1 if it is a ber file, 0 if not
int if_ber_file(char *map_path)
{
    int len;
    int counter;
    
    len = ft_strlen(map_path);
    counter = (len - 4);
    if (map_path[counter] != '.' || map_path[counter + 1] != 'b' || 
        map_path[counter + 2] != 'e' || map_path[counter + 3] != 'r')
            return(0);
    return (1);
}
