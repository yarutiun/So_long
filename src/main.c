/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 13:17:50 by yarutiun          #+#    #+#             */
/*   Updated: 2022/09/30 01:09:39 by yarutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/so_long.h"

int	main(int argc, char **argv)
{
t_mlx	mlx_s;

	if (mega_map_check(&mlx_s ,argc, argv) == 0)
        {
         print_error_msg("KHSDGFIHWKJSDBNFC");
         return (1);   
        }
    mlx_s.map = create_matrix(argv[1]);
    x_y_of_map( argv[1], &(mlx_s.map_height), &(mlx_s.map_width));
    mlx_s.mlx_pointer = mlx_init();
    window_create_and_x_y(&mlx_s, argv[1]);
	mlx_s.picures = load_images(&mlx_s);
    find_player_pos(&mlx_s);
	render_map(&mlx_s);
	mlx_key_hook(mlx_s.window, key_handler, &mlx_s);
	mlx_hook(mlx_s.window, X_CLOSE, 0, x_close, 0);
	mlx_loop(mlx_s.mlx_pointer);
	return (0);
}