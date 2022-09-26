/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 13:17:50 by yarutiun          #+#    #+#             */
/*   Updated: 2022/09/26 17:39:12 by yarutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/so_long.h"

int	main(int argc, char **argv)
{
t_mlx	mlx_s;
// int i = 0;

	if (mega_map_check(&mlx_s ,argc, argv) == 0)
        {
         print_error_msg("KHSDGFIHWKJSDBNFC");
         return (1);   
        }
    mlx_s.map = create_matrix(argv[1]);
    if (argc)
    {
        
    }
    // while(mlx_s.map[i])
    // {
    //     printf("%s", mlx_s.map[i]);
    //     i ++;
    // }
    x_y_of_map( argv[1], &(mlx_s.map_height), &(mlx_s.map_width));
    mlx_s.mlx_pointer = mlx_init();
    window_create_and_x_y(&mlx_s, argv[1]);
	mlx_s.picures = load_images(&mlx_s);
    find_player_pos(&mlx_s);
    printf ("%i %i", mlx_s.player_x_pos, mlx_s.player_y_pos);
	// // mlx_s.map = create_matrix(argv[1]);
	render_map(&mlx_s);
    
    // mlx_loop(mlx_s.mlx_pointer);
	return (0);
}