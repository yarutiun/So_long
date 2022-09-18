/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 00:01:46 by yarutiun          #+#    #+#             */
/*   Updated: 2022/09/18 16:13:36 by yarutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define ASSETS 64

# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>
# include "get_next_line.h"
# include <X11/keysym.h> //for key buttons
# include "../libftprintf/inc/ft_printf.h"
# include "../libftprintf/inc/libft.h"
# define WIDTH 900	// Width of the window (in pixels)
# define HEIGHT 900	// Height of the window (in pixels)

typedef struct	s_program
 {
	void	*mlx_pointer;
	void	*window;

}				t_program;

typedef struct s_data
{
	char	**map;
	int		fd;
	int		map_width;
	int		map_height;
	
}	t_data;

typedef struct	s_image
{
	void      *pointer;
	char      *pixels;
	int       bits_per_pixel;
	int       line_size;
	int       endian;
} t_image;

typedef struct s_assets
{
	void *walls;
	void *sprite;
	void *collectible;
	void *door;
	void *enemie;
	int  poz_x;
	int  poz_y;
} t_assets;

enum {
	DOWN = 125,
	UP = 126,
	LEFT = 123,
	RIGHT = 124,
	ESC = 53,
	W = 13,
	S = 1,
	A = 0,
	D = 2,
	X_CLOSE = 17,
};

void x_y_of_map(char *map_adress, int *map_height, int *map_width);

#endif