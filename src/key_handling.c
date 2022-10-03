/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 11:45:52 by yarutiun          #+#    #+#             */
/*   Updated: 2022/10/03 15:12:44 by yarutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

//just wrote that function to exit in the end of the game
int press_anything(int keycode, t_mlx *mlx_s)
{
    if (keycode  || 0)
        exit(EXIT_SUCCESS);
        mlx_destroy_window(mlx_s->mlx_pointer, mlx_s->window);
        free_all_map(mlx_s->map);
        exit(EXIT_SUCCESS);
}

int	x_close(void)
{
	exit(EXIT_SUCCESS);
}

void	game_over(t_mlx *mlx_s)
{
	mlx_string_put(mlx_s->mlx_pointer, mlx_s->window, 20, 20, 0x44FF0022, "Game over");
	mlx_string_put(mlx_s->mlx_pointer, mlx_s->window, 20, 40,
		0x44FF0022, "Press any key to exit");
	mlx_key_hook(mlx_s->window, press_anything, mlx_s);
}

int	key_handler(int keycode, t_mlx *mlx_s)
{
	if (keycode == ESC)
		press_anything(0, mlx_s);
	else if (keycode == DOWN || keycode == S)
		change_map(mlx_s, 0, 1, 'x');
	else if (keycode == UP || keycode == W)
		change_map(mlx_s, 0, -1, 'x');
	else if (keycode == LEFT || keycode == A)
		change_map(mlx_s, -1, 0, 'x');
	else if (keycode == RIGHT || keycode == D)
		change_map(mlx_s, 1, 0, 'x');
	return (0);
}
//finds players current position and fills t_tuple struct with coordinates

//just finds a current platers pos and fills the mlx struct with that info
void    find_player_pos(t_mlx *mlx_s)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (mlx_s->map[i])
    {
        while(mlx_s->map[i][j])
        {
            if (mlx_s->map[i][j] == 'P')
            {
                mlx_s->player_y_pos = i;
                mlx_s->player_x_pos = j;
                return ;
            }
            j++;
        }
        j = 0;
        i++;
    }
    i = 0;
}
//pushes a new player pos to arguments row and col (need to monitor moves)
void	reset_player_pos(t_mlx *mlx_s, int *row, int *col)
{
    find_player_pos(mlx_s);
    *row += mlx_s->player_x_pos;
    *col += mlx_s->player_y_pos;
    
    // mlx_s->player_y_pos = 0;
    // mlx_s->player_x_pos = 0;
}
