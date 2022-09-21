/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:23:06 by yarutiun          #+#    #+#             */
/*   Updated: 2022/09/21 22:08:47 by yarutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// t_assets	load_images(t_mlx *mlx_s)
// {
//     t_assets picture;
//     // picture.walls = mlx_xpm_file_to_image(mlx_s->mlx_pointer, )
    
//     // picture.collectible = mlx_xpm_file_to_image(mlx_s->mlx_pointer, )

//     // picture.door = mlx_xpm_file_to_image(mlx_s->mlx_pointer, )

//     // picture.sprite = mlx_xpm_file_to_image(mlx_s->mlx_pointer, )
// }

void	window_create_and_x_y(t_mlx *mlx_s, char *map_adress)
{
    int a;
    int b;
    x_y_of_map(map_adress, &a, &b);
	mlx_s->map_height = a  * 100;
	mlx_s->map_width = b * 100;
	mlx_s->window = mlx_new_window(mlx_s->mlx_pointer, mlx_s->map_width,
			mlx_s->map_height, "So_long");
}