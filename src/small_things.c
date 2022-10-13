/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_things.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:55:14 by yarutiun          #+#    #+#             */
/*   Updated: 2022/10/13 20:39:50 by yarutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	smth(t_mlx *mlx_s)
{
	render_map(mlx_s);
	game_over(mlx_s);
}

void	smth2(t_mlx *mlx_s)
{
	render_map(mlx_s);
	game_over_loss(mlx_s);
}

void	if_last_is_e(char i, t_mlx *mlx_s)
{
	if (i == 'E')
		mlx_s->was_e = true;
}

void	*put_img(t_mlx *mlx_s, int i, int j)
{
	void	*img;

	img = NULL;
	if (mlx_s->map[i][j] == '1')
		img = mlx_s->picures.walls;
	else if (mlx_s->map[i][j] == '0')
		img = mlx_s->picures.floor;
	else if (mlx_s->map[i][j] == 'C')
		img = mlx_s->picures.collectible;
	else if (mlx_s->map[i][j] == 'P')
		img = mlx_s->picures.sprite;
	else if (mlx_s->map[i][j] == 'E')
		img = mlx_s->picures.portal_on;
	else if (mlx_s->map[i][j] == 'e')
		img = mlx_s->picures.enemie;
	return (img);
}

void	initialize(t_mlx *mlx_s)
{
	mlx_s->beforex = 0;
	mlx_s->beforey = 0;
	mlx_s->was_e = false;
}
