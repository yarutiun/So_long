/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_correct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:49:08 by yarutiun          #+#    #+#             */
/*   Updated: 2022/10/14 16:58:47 by yarutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
//return 0 if success, 1 if not
int	if_rectangle(char *map_path, char **map)
{
	int	i;
	int	j;
	int	row;
	int	col;

	x_y_of_map(map_path, &col, &row);
	row--;
	col--;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && (i == 0 || i == col || j == 0 || j == row))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

//return 0 if success, 1 if not
int	if_one_player(char *map_path, char **map)
{
	t_mlx	d;
	int		i;
	int		player;

	player = 0;
	i = 0;
	x_y_of_map(map_path, &d.map_height, &d.map_width);
	while (map[i] != map[d.map_height])
	{
		if (ft_strchr(map[i], 'P') != 0)
		{
			player++;
			if(player > 1)
				return (0);
		}
		i++;
	}
	if(player == 1)
		return (1);
	free_all_map(map);
	return (0);
}

//return 1 if success, 0 if not
int	if_collectible(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

// if there are no more symbols in map but '1' '0' 'c' 'e' 'p' 
//then return value is 0, if else - return value is 1
int	if_correct_symbols(char **map)
{
	int		i;
	int		j;
	char	*allowed_chars;

	allowed_chars = "10EPCe";
	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			// fprintf(stderr, "i is %d, j is %d\n", i, j);
			if (!ft_strchr(allowed_chars, map[i][j]))
				return (1);
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}

//returns 0 if it is a ber file, 1 if not
int	if_ber_file(char *map_path)
{
	int	len;
	int	counter;

	len = ft_strlen(map_path);
	counter = (len - 4);
	if (map_path[counter + 1] != '.' || map_path[counter + 2] != 'b' || \
		map_path[counter + 3] != 'e' || map_path[counter + 4] != 'r')
		return (1);
	return (0);
}
