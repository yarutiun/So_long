/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   another_file_for_norm.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:38:48 by yarutiun          #+#    #+#             */
/*   Updated: 2022/10/13 13:59:53 by yarutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	press_anything(int keycode, t_mlx *mlx_s)
{
	if (keycode || 0)
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
	mlx_string_put(mlx_s->mlx_pointer, mlx_s->window, \
	20, 20, 0x44FF0022, "Game over");
	mlx_string_put(mlx_s->mlx_pointer, mlx_s->window, 20, 40,
		0x44FF0022, "Press any key to exit");
	mlx_key_hook(mlx_s->window, press_anything, mlx_s);
}

void	game_over_loss(t_mlx *mlx_s)
{
	mlx_string_put(mlx_s->mlx_pointer, mlx_s->window, \
	20, 20, 0x44FF0022, "Game over");
	mlx_string_put(mlx_s->mlx_pointer, mlx_s->window, 20, 40,
		0x44FF0022, "You died lol");
	mlx_key_hook(mlx_s->window, press_anything, mlx_s);
}

//returns 1 if there is an exit, 0 if no
int	if_exit(char *map_path, char **map)
{
	t_mlx	d;
	int		i;

	i = 0;
	x_y_of_map(map_path, &d.map_height, &d.map_width);
	while (map[i] != map[d.map_height - 1])
	{
		if (ft_strchr(map[i], 'E') != 0)
			return (1);
		i++;
	}
	free_all_map(map);
	return (0);
}
