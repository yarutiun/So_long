/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 13:17:50 by yarutiun          #+#    #+#             */
/*   Updated: 2022/09/20 20:44:56 by yarutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/so_long.h"

int	main(void)
{
	// void	*mlx;
    // void    *mlx_win;
	// void	*img;
	// char	*relative_path = "images/AnyConv.com__ezgif.com-gif-maker.xpm";
	// int		img_width = 10;
	// int		img_height = 10;

	// mlx = mlx_init();
    // mlx_win = mlx_new_window(mlx, 3000, 3000, "Hello world!");
	// img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
    // mlx_put_image_to_window(mlx, mlx_win, img, 10, 10);
    // if (img)
    // {
        
    // }
    // mlx_loop(mlx);
    t_data d;
    char **matrix;
    char *path = "maps/good_map.ber";
    x_y_of_map(path, &d.map_height, &d.map_width);
    matrix = create_matrix(path);
    if_rectangle(path, matrix);
    // while(i < e)
    // {
    //     printf("%c", matrix[d.map_height - 1][e]);
    //     i ++;
    // }
    // printf("%i %i",d.map_height ,d.map_width);
    
    return 0;
}