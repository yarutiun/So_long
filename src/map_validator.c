/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 14:20:18 by yarutiun          #+#    #+#             */
/*   Updated: 2022/10/14 16:56:01 by yarutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
//returns 0 if fail, 1 if success
void	mega_map_check(int argc, char **argv, char **mlx_map)
{
	if (argc != 2)
		exit(EXIT_FAILURE);
	if (if_ber_file(argv[1]) != 1)
		exit(EXIT_FAILURE);
	if (if_collectible(mlx_map) != 1 || if_exit(argv[1], mlx_map) != 1)
	{
		ft_putstr_fd("There are no collectibles or exits!");
		exit(EXIT_FAILURE);
	}
	if (if_one_player(argv[1], mlx_map) != 1)
	{
		ft_putstr_fd("There is not only 1 player");
		exit(EXIT_FAILURE);
	}
	if (if_correct_symbols(mlx_map))
	{
		exit(EXIT_FAILURE);
	}
	if (!(if_rectangle(argv[1], mlx_map)))
	{
		ft_putstr_fd("not a rectangle");
		exit(EXIT_FAILURE);
	}
}

void	x_y_of_map(char *map_adress, int *map_height, int *map_width)
{
	t_mlx	info;
	char	*str;

	info.fd = open(map_adress, O_RDONLY);
	if (info.fd < 0)
		exit(0);
	*map_height = 0;
	str = get_next_line(info.fd);
	*map_width = (int)(ft_strlen(str) -1);
	while (1)
	{
		*map_height += 1;
		free(str);
		str = get_next_line(info.fd);
		if (str == NULL)
		{
			break ;
		}
	}
	close(info.fd);
}

char	**create_matrix(char *map_path)
{
	t_mlx	map;

	map.counter = 0;
	map.fd = open(map_path, O_RDONLY);
	x_y_of_map(map_path, &map.map_height, &map.map_width);
	map.map = malloc(sizeof(char *) * map.map_height + 1);
	if (!map.map)
	{
		free(map.map);
		exit(EXIT_FAILURE);
	}
	while (map.counter != map.map_height)
	{
		map.map[map.counter] = malloc(sizeof(char) * map.map_width + 1);
		if (!map.map[map.counter])
		{
			free(map.map[map.counter]);
			exit(EXIT_FAILURE);
		}
		read(map.fd, map.map[map.counter], map.map_width + 1);
		map.map[map.counter][map.map_width] = '\0';
		map.counter++;
	}
	map.map[map.counter] = NULL;
	return (map.map);
}

char	**create_matrix2(char *map_path)
{
	t_mlx	map2;

	map2.counter = 0;
	map2.fd = open(map_path, O_RDONLY);
	x_y_of_map(map_path, &map2.map_height, &map2.map_width);
	map2.map_cpy = malloc(sizeof(char *) * map2.map_height + 1);
	if (!map2.map)
	{
		free(map2.map);
		exit(EXIT_FAILURE);
	}
	while (map2.counter != map2.map_height)
	{
		map2.map_cpy[map2.counter] = malloc(sizeof(char) * map2.map_width + 1);
		if (!map2.map_cpy[map2.counter])
		{
			free(map2.map_cpy[map2.counter]);
			exit(EXIT_FAILURE);
		}
			read(map2.fd, map2.map_cpy[map2.counter], map2.map_width + 1);
		map2.map_cpy[map2.counter][map2.map_width] = '\0';
		map2.counter++;
	}
	map2.map_cpy[map2.counter] = NULL;
	return (map2.map_cpy);
}

void	free_all_map(char **map)
{
	int	counter;

	counter = 0;
	while (map[counter] != NULL)
	{
		free(map[counter]);
		counter ++;
	}
	free(map);
}
