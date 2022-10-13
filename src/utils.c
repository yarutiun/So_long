/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 13:42:51 by yarutiun          #+#    #+#             */
/*   Updated: 2022/10/13 14:41:06 by yarutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_putstr_fd(char *s)
{
	if (!s)
		return ;
	write(1, s, ft_strlen(s));
}

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

void	check_collect(bool was_e, t_mlx *mlx_s)
{
	if (was_e == false)
		mlx_s->map[mlx_s->player_y_pos][mlx_s->player_x_pos] = '0';
	else
	{
		mlx_s->map[mlx_s->player_y_pos][mlx_s->player_x_pos] = 'E';
		was_e = false;
	}
}
