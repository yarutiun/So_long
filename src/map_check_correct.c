/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_correct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:49:08 by yarutiun          #+#    #+#             */
/*   Updated: 2022/10/13 22:36:09 by yarutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
//return 0 if success, 1 if not
int	if_rectangle(char *map_path, char **map)
{
	int		i;
	t_mlx	d;

	i = 0;
	d.counter = 0;
	x_y_of_map(map_path, &d.map_height, &d.map_width);
	while (i < d.map_width)
	{
		if (map[0][i] != '1' || map[d.map_height - 1][i] != '1')
		{
			free_all_map(map);
			return (1);
		}
		i++;
	}
	while (d.counter < d.map_height)
	{
		if (map[d.counter][0] != '1' || map[d.counter][d.map_width - 1] != '1')
		{
			free_all_map(map);
			return (1);
		}
	d.counter ++;
	}
	return (0);
}

//return 0 if success, 1 if not
int	if_one_player(char *map_path, char **map)
{
	t_mlx	d;
	int		i;

	i = 0;
	x_y_of_map(map_path, &d.map_height, &d.map_width);
	while (map[i] != map[d.map_height])
	{
		if (ft_strchr(map[i], 'P') != 0)
		{
			return (1);
		}
		i++;
	}
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

	allowed_chars = "10EPC";
	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
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
