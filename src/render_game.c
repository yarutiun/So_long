/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:23:06 by yarutiun          #+#    #+#             */
/*   Updated: 2022/10/13 20:43:19 by yarutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_assets	load_images(t_mlx *mlx_s)
{
	t_assets	picture;

	picture.walls = mlx_xpm_file_to_image(mlx_s->mlx_pointer, \
	"images/wall100.xpm", &mlx_s->sprite_width, &mlx_s->sprite_height);
	picture.floor = mlx_xpm_file_to_image(mlx_s->mlx_pointer, \
	"images/floor.xpm", &mlx_s->sprite_width, &mlx_s->sprite_height);
	picture.portal_on = mlx_xpm_file_to_image(mlx_s->mlx_pointer, \
	"images/portal_on100.xpm", &mlx_s->sprite_width, &mlx_s->sprite_height);
	picture.sprite = mlx_xpm_file_to_image(mlx_s->mlx_pointer, \
	"images/doomslayer100.xpm", &mlx_s->sprite_width, &mlx_s->sprite_height);
	picture.collectible = mlx_xpm_file_to_image(mlx_s->mlx_pointer, \
	"images/chainsaw100.xpm", &mlx_s->sprite_width, &mlx_s->sprite_height);
	picture.enemie = mlx_xpm_file_to_image(mlx_s->mlx_pointer, \
	"images/enemie.xpm", &mlx_s->sprite_width, &mlx_s->sprite_height);
	return (picture);
}

void	render_map(t_mlx *mlx_s)
{
	void	*img;
	int		i;
	int		j;
	int		x_cord;
	int		y_cord;

	y_cord = 0;
	i = 0;
	while (i < (mlx_s->map_height / 100))
	{
		x_cord = 0;
		j = 0;
		while (j < (mlx_s->map_width / 100))
		{
			img = put_img(mlx_s, i, j);
			mlx_put_image_to_window(mlx_s->mlx_pointer, \
			mlx_s->window, img, x_cord, y_cord);
			++j;
			x_cord += 100;
		}
		y_cord += 100;
		++i;
	}
}

void	render_with_moves(t_mlx *mlx_s)
{
	static int	moves_count;
	char		*str;

	str = ft_itoa(moves_count);
	++moves_count;
	render_map(mlx_s);
	mlx_string_put(mlx_s->mlx_pointer, mlx_s->window, 20, \
	20, 0x44FF0022, str);
	free(str);
	mlx_s->was_e = false;
}

void	window_create_and_x_y(t_mlx *mlx_s, char *map_adress)
{
	int	a;
	int	b;

	x_y_of_map(map_adress, &a, &b);
	mlx_s->map_height = a * 100;
	mlx_s->map_width = b * 100;
	mlx_s->sprite_height = 100;
	mlx_s->sprite_width = 100;
	mlx_s->window = mlx_new_window(mlx_s->mlx_pointer, mlx_s->map_width, \
			mlx_s->map_height, "So_long");
}

void	change_map(t_mlx *mlx_s, int row, int col, char new_square)
{
	if_last_is_e(mlx_s->last_square, mlx_s);
	reset_player_pos(mlx_s, &row, &col);
	new_square = mlx_s->map[col][row];
	if (new_square == '1')
		return ;
	if (new_square == 'e')
	{
		mlx_s->map[mlx_s->beforey][mlx_s->beforex] = '0';
		mlx_s->map[col][row] = 'P';
		smth2(mlx_s);
		return ;
	}
	if ((new_square == 'E') && (!if_collectible(mlx_s->map)))
	{
		mlx_s->map[mlx_s->beforey][mlx_s->beforex] = '0';
		mlx_s->map[col][row] = 'P';
		smth(mlx_s);
		return ;
	}
	mlx_s->last_square = mlx_s->map[col][row];
	mlx_s->map[col][row] = 'P';
	check_collect(mlx_s->was_e, mlx_s);
	mlx_s->beforex = (int)row;
	mlx_s->beforey = (int)col;
	render_with_moves(mlx_s);
}
