/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 13:17:50 by yarutiun          #+#    #+#             */
/*   Updated: 2022/10/14 14:32:02 by yarutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int argc, char **argv)
{
	t_mlx	mlx_s;
	int		x;
	int		y;
	x_y_of_map(argv[1], &y, &x);
	initialize(&mlx_s);
	mlx_s.map = create_matrix(argv[1]);
	mlx_s.map_cpy = create_matrix2(argv[1]);
	make_map_size(&mlx_s, argv[1], mlx_s.map_cpy);
	find_player_pos_cpy(&mlx_s);
	if (has_valid_path(&mlx_s) == 1)
		exit(EXIT_FAILURE);
	mega_map_check(argc, argv, mlx_s.map);
	mlx_s.mlx_pointer = mlx_init();
	window_create_and_x_y(&mlx_s, argv[1]);
	mlx_s.picures = load_images(&mlx_s);
	find_player_pos (&mlx_s);
	render_map(&mlx_s);
	mlx_key_hook(mlx_s.window, key_handler, &mlx_s);
	mlx_hook(mlx_s.window, X_CLOSE, 0, x_close, 0);
	mlx_loop(mlx_s.mlx_pointer);
	free_all_map(mlx_s.map);
	free_all_map(mlx_s.map_cpy);
	return (0);
}
