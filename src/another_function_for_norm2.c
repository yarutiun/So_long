/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   another_function_for_norm2.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:52:36 by yarutiun          #+#    #+#             */
/*   Updated: 2022/10/13 14:28:21 by yarutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	count(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if ((map[i][j] == 'C') || (map[i][j] == 'E'))
			{
				count++;
			}
			j++;
		}
		i++;
	}
	return (count);
}

void	counting_reachable(t_mlx *mlx_s, int x, int y, int *a)
{
	if ((y < 0 || y >= mlx_s->dlina) || (x < 0 || x >= mlx_s->shirina))
		return ;
	if (mlx_s->map_cpy[y][x] == '1')
		return ;
	if (mlx_s->map_cpy[y][x] == 'C')
		*a += 1;
	if (mlx_s->map_cpy[y][x] == 'E')
		*a += 1;
	mlx_s->map_cpy[y][x] = '1';
	counting_reachable(mlx_s, x, y - 1, a);
	counting_reachable(mlx_s, x - 1, y, a);
	counting_reachable(mlx_s, x + 1, y, a);
	counting_reachable(mlx_s, x, y + 1, a);
}

int	has_valid_path(t_mlx *mlx_s)
{
	int	x;
	int	y;
	int	a;
	int	countt;

	a = 0;
	x = mlx_s->player_x_pos;
	y = mlx_s->player_y_pos;
	countt = count(mlx_s->map_cpy);
	counting_reachable(mlx_s, x, y, &a);
	if (countt != a)
	{
		write(1, "No valid path", 13);
		return (1);
	}
	return (0);
}

void	make_map_size(t_mlx *mlx_s, char *adress, char **map_cpy)
{
	int	i;
	int	j;

	x_y_of_map(adress, &i, &j);
	mlx_s->dlina = j;
	mlx_s->shirina = i;
	mlx_s->map_cpy = map_cpy;
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*temo;

	i = 0;
	temo = (char *)haystack;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (temo[i] && i < len)
	{
		j = 0;
		while (temo[i + j] == needle[j] && len - i >= ft_strlen(needle))
		{
			if (needle[j + 1] == '\0')
			{
				return (&temo[i]);
			}
			j++;
		}
		i++;
	}
	return (0);
}
