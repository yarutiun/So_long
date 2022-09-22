/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 13:17:50 by yarutiun          #+#    #+#             */
/*   Updated: 2022/09/22 14:29:08 by yarutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/so_long.h"

int	main(int argc, char **argv)
{
t_mlx	mlx_s;

	// if (mega_map_check(&mlx_s ,argc, argv) == 0)
	// 	return (1);
    if (argc)
    {
        
    }
    mlx_s.map = create_matrix(argv[1]);
	mlx_s.mlx_pointer = mlx_init();
	x_y_of_map( argv[1], &(mlx_s.map_height), &(mlx_s.map_width));
	mlx_s.picures = load_images(&mlx_s);
	window_create_and_x_y(&mlx_s, argv[1]);
	// mlx_s.map = create_matrix(argv[1]);
	render_map(&mlx_s);
    
    mlx_loop(mlx_s.mlx_pointer);
	return (0);
}