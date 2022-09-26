/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 11:45:52 by yarutiun          #+#    #+#             */
/*   Updated: 2022/09/26 17:40:55 by yarutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

//just wrote that function to exit in the end of the game
void press_anything(int keycode, t_mlx *mlx_s)
{
    if (keycode)
    {
        mlx_destroy_window(mlx_s->mlx_pointer, mlx_s->window);
        free_all_map(mlx_s->map);
        exit(EXIT_SUCCESS);
    }
}

// int     key_handler(int keycode, t_mlx *mlx_s)
// {
//     if (keycode == ESC)
//         {
//             mlx_destroy_window(mlx_s->mlx_pointer, mlx_s->window);
//             free_all_map;
//             exit(EXIT_SUCCESS);
//         }
//     if (keycode == )
// }

//finds players current position and fills t_tuple struct with coordinates
void    find_player_pos(t_mlx *mlx_s)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (mlx_s->map[i])
    {
        while(mlx_s->map[i][j])
        {
            if (mlx_s->map[i][j] == 'P')
            {
                mlx_s->player_y_pos = i + 1;
                mlx_s->player_x_pos = j + 1;
                return ;
            }
            j++;
        }
        j = 0;
        i++;
    }
}