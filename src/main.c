/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 13:17:50 by yarutiun          #+#    #+#             */
/*   Updated: 2022/09/21 17:08:25 by yarutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/so_long.h"

int	main(int argc, char **argv)
{
    t_mlx	mlx_s;
    if(mega_map_check(&mlx_s, argc, argv) == 0)
        return (0);
    mlx_s.mlx_pointer = mlx_init();
    x_y_of_map(argv[1], &(mlx_s.map_height), &(mlx_s.map_width));
    

    mega_map_check(&mlx_s, argc, argv);
    printf("%s", mlx_s.map[0]);
    
    mlx_loop(mlx_s.mlx_pointer);
	return (0);
}