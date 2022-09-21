/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 13:17:50 by yarutiun          #+#    #+#             */
/*   Updated: 2022/09/21 13:18:52 by yarutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/so_long.h"

int	main(void)
{
    // t_program mlx;
    // mlx.mlx_pointer = mlx_init();
//    t_data d;
    // char **matrix;
    char *path = "maps/good_map.ber";
    // x_y_of_map(path, &d.map_height, &d.map_width);
    // matrix = create_matrix(path);
    if_ber_file(path);
    // if_correct_symbols(path, matrix);
    // if_rectangle(path, matrix);
    // if_one_player(path, matrix);
    // while(i < e)
    // {
    //     printf("%c", matrix[d.map_height - 1][e]);
    //     i ++;
    // }
    // printf("%i %i",d.map_height ,d.map_width);
    
    return 0;
}