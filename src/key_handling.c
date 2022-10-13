/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 11:45:52 by yarutiun          #+#    #+#             */
/*   Updated: 2022/10/13 20:42:25 by yarutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

//just wrote that function to exit in the end of the game
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
void	find_player_pos_cpy(t_mlx *mlx_s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (mlx_s->map_cpy[i])
	{
		while (mlx_s->map_cpy[i][j])
		{
			if (mlx_s->map_cpy[i][j] == 'P')
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

void	find_player_pos(t_mlx *mlx_s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (mlx_s->map[i])
	{
		while (mlx_s->map[i][j])
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

void	find_enemie_pos(t_mlx *mlx_s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (mlx_s->map[i])
	{
		while (mlx_s->map[i][j])
		{
			if (mlx_s->map[i][j] == 'e')
			{
				mlx_s->enemie_y_pos = i;
				mlx_s->enemie_x_pos = j;
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
}
