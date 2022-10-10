/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:23:06 by yarutiun          #+#    #+#             */
/*   Updated: 2022/10/10 17:44:56 by yarutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_assets	load_images(t_mlx *mlx_s)
{
    t_assets picture;
    picture.walls = mlx_xpm_file_to_image(mlx_s->mlx_pointer, "images/wall100.xpm",  &mlx_s->sprite_width , &mlx_s->sprite_height);
    picture.floor = mlx_xpm_file_to_image(mlx_s->mlx_pointer, "images/floor.xpm", &mlx_s->sprite_width , &mlx_s->sprite_height );
    picture.portal_on = mlx_xpm_file_to_image(mlx_s->mlx_pointer, "images/portal_on100.xpm", &mlx_s->sprite_width , &mlx_s->sprite_height);
    picture.sprite = mlx_xpm_file_to_image(mlx_s->mlx_pointer,"images/doomslayer100.xpm" , &mlx_s->sprite_width , &mlx_s->sprite_height);
    picture.collectible = mlx_xpm_file_to_image(mlx_s->mlx_pointer, "images/chainsaw100.xpm", &mlx_s->sprite_width , &mlx_s->sprite_height); 
    return (picture);
}

void render_map(t_mlx *mlx_s)
{
    void    *img;
    int     i;
    int     j;
    int     x_cord;
    int     y_cord;
    // x_y_of_map( path, &(mlx_s->map_height), &(mlx_s->map_width));

    x_cord = 0;
    y_cord = 0;
    i = 0;
    j = 0;
    while(i < (mlx_s->map_height / 100))
    {
        while(j < (mlx_s->map_width / 100))
        {
            if (mlx_s->map[i][j] == '1')
                img = mlx_s->picures.walls;
            else if(mlx_s->map[i][j] == '0')
                img = mlx_s->picures.floor;
            else if(mlx_s->map[i][j] == 'C')
                img = mlx_s->picures.collectible;
            else if(mlx_s->map[i][j] == 'P')
                img = mlx_s->picures.sprite;
            else if(mlx_s->map[i][j] == 'E')
                img = mlx_s->picures.portal_on;
            mlx_put_image_to_window(mlx_s->mlx_pointer, mlx_s->window, img, x_cord, y_cord );
            ++j;
            x_cord += 100;
        }
        y_cord += 100;
        x_cord = 0;
        j = 0;
        ++i;    
    } 
}

void render_with_moves (t_mlx *mlx_s)
{
    static int moves_count;
    char *str = ft_itoa(moves_count);
    moves_count ++;
    render_map(mlx_s);
    mlx_string_put(mlx_s->mlx_pointer, mlx_s->window, 20, 20,
		0x44FF0022, str);
    free(str);
}

void	window_create_and_x_y(t_mlx *mlx_s, char *map_adress)
{
    int a;
    int b;
    x_y_of_map(map_adress, &a, &b);
	mlx_s->map_height = a  * 100;
	mlx_s->map_width = b * 100;
    mlx_s->sprite_height = 100;
    mlx_s->sprite_width = 100;
	mlx_s->window = mlx_new_window(mlx_s->mlx_pointer, mlx_s->map_width,
			mlx_s->map_height, "So_long");
}

void	change_map(t_mlx *mlx_s, int row, int col, char new_square)
{
	static char	last_square;
	static bool	was_e = false;
    static int beforex;
    static int beforey;

	if (last_square == 'E')
		was_e = true;
	reset_player_pos(mlx_s, &row, &col);
	new_square = mlx_s->map[col][row];
	if (new_square == '1')
		return ;
	if ((new_square == 'E') && (!if_collectible(mlx_s->map)))
	{
        mlx_s->map[beforey][beforex] = '0';
		mlx_s->map[col][row] = 'P';
		render_map(mlx_s);
        game_over(mlx_s);
		return ;
	}
	last_square = mlx_s->map[col][row];
	mlx_s->map[col][row] = 'P';
	if (was_e == false)
		mlx_s->map[mlx_s->player_y_pos][mlx_s->player_x_pos] = '0';
	else
	{
		mlx_s->map[mlx_s->player_y_pos][mlx_s->player_x_pos] = 'E';
		was_e = false;
	}
    beforex = (int)row;
    beforey = (int)col;
	render_with_moves(mlx_s);
}
