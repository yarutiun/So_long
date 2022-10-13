/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 13:42:51 by yarutiun          #+#    #+#             */
/*   Updated: 2022/10/13 13:27:18 by yarutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/so_long.h"

void	ft_putstr_fd(char *s)
{
	if (!s)
		return ;
	write(1, s, ft_strlen(s));
}



// int print_error_msg(char *msg)
// {
//     ft_putstr_fd(msg, 1);
//     return (0);
// }

int	len(long nb)
{
	int	len;

	len = 0;
	if (nb < 0)
	{
		nb = nb * -1;
		len++;
	}
	if (nb == 0)
	{
		return (1);
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char	*if_zero(char *s)
{
	s[0] = '0';
	return (s);
}

char	*ft_itoa(int nb)
{
	char	*s;
	long	n;
	int		i;

	n = nb;
	i = len(n);
	s = (char *)malloc(sizeof(char) * (i + 1));
	if (!s)
		return (NULL);
	s[i--] = '\0';
	if (n == 0)
	{
		if_zero(s);
	}
	if (n < 0)
	{
		s[0] = '-';
		n = n * -1;
	}
	while (n > 0)
	{
		s[i--] = '0' + (n % 10);
		n = n / 10;
	}
	return (s);
}

void counting_reachable(t_mlx *mlx_s, int x, int y, int *a)
{
	if ((y < 0 || y >= mlx_s->dlina) || (x < 0 || x >= mlx_s->shirina))
		return;
	if (mlx_s->map_cpy[y][x] == '1')
		return;
	if (mlx_s->map_cpy[y][x] == 'C')
		*a += 1;
	if (mlx_s->map_cpy[y][x] == 'E')
		*a += 1;
	mlx_s->map_cpy[y][x] = '1';
	// printf("%i", *a);
	counting_reachable(mlx_s, x, y - 1, a);
	counting_reachable(mlx_s, x - 1, y, a);
	counting_reachable(mlx_s, x + 1, y, a);
	counting_reachable(mlx_s, x, y + 1, a);
}

int	has_valid_path(t_mlx *mlx_s)
{
	int x = mlx_s->player_x_pos;
	int y = mlx_s->player_y_pos;
	int a = 0;
	int countt;
	countt = count(mlx_s->map_cpy);
	counting_reachable(mlx_s, x, y, &a);
	if (countt != a)
	{
		write(1, "No valid path", 13);
		return (1);
	}
	return (0);
}

void make_map_size(t_mlx *mlx_s, char *adress)
{
	int i;
	int j;

	x_y_of_map(adress, &i, &j);
	mlx_s->dlina = j;
	mlx_s->shirina = i;
}

void map_cpy_to_struct(t_mlx *mlx_s, char **map_cpy)
{
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