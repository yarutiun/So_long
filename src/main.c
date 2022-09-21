/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 13:17:50 by yarutiun          #+#    #+#             */
/*   Updated: 2022/09/21 16:52:13 by yarutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/so_long.h"

int	main(int argc, char **argv)
{
    t_mlx	mlx_s;
    if(argc && argv)
    {
        
    }
    // t_data map;
    // // t_program mlx;
    // mega_map_check(&map, argc, argv);
    // data.map = create_matrix(argv[1]);
    // x_y_of_map(argv[1], &data.map_height, &data.map_width);
    mega_map_check(&mlx_s, argc, argv);
    // mlx.mlx_pointer = mlx_init();
    // mlx.window = mlx_new_window(mlx.mlx_pointer, (data.map_width * 100), (data.map_height * 100), "So_long");
    // printf("%i, %i", map.map_height, map.map_width);
    printf("%s", mlx_s.map[0]);
    
    return 0;
}