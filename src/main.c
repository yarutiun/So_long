/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 13:17:50 by yarutiun          #+#    #+#             */
/*   Updated: 2022/09/18 16:25:07 by yarutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

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
    int a;
    int b;
    // a = malloc(sizeof(int) * 1000);
    // b = malloc(sizeof(int) * 1000);
    x_y_of_map("maps/good_map.ber", &a, &b);
    printf("%i, %i", a, b);
    return 0;
}