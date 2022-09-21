/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 00:01:46 by yarutiun          #+#    #+#             */
/*   Updated: 2022/09/21 17:10:50 by yarutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define ASSETS 64

# include "../mlx/mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif
// window size is going to be: x amount of elements in row * 100, y amount of elements in colomn * 100
// if so, then texture size is going to be 100, 100

typedef struct s_mlx
{
	void	*mlx_pointer;
	void	*window;
	char	**map;
	int		fd;
	int		map_width;
	int		map_height;
	int		counter;
	int		counter2;
	size_t 	len;
	int		player_x_pos;
	int 	playery_pos;
	int		current_score;
}	t_mlx;

typedef struct	s_image
{
	void      *pointer;
	char      *pixels;
	int       bits_per_pixel;
	int       line_size;
	int       endian;
} t_image;

typedef struct s_assets
{
	void *walls;
	void *sprite;
	void *collectible;
	void *door;
	void *enemie;
	int  poz_x;
	int  poz_y;
} t_assets;

enum {
	DOWN = 125,
	UP = 126,
	LEFT = 123,
	RIGHT = 124,
	ESC = 53,
	W = 13,
	S = 1,
	A = 0,
	D = 2,
	X_CLOSE = 17,
};

//all the get_next_line functions
char	*get_next_line(int fd);
char	*read_to_nl_or_eof(int fd, char *line);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_strchr(char *str, int c);
void	ft_putstr_fd(char *s, int fd);

//errors
int print_error_msg(char *msg);
void if_correct_argc(int argc);

//working with map and converting it in char **
void x_y_of_map(char *map_adress, int *map_height, int *map_width);
char **create_matrix(char *map_path);
void free_all_map(char **map);

//validating the map
int if_rectangle(char *map_path, char **map);
int if_one_player(char *map_path, char **map);
int if_collectible(char *map_path, char **map);
int if_correct_symbols(char *map_path, char **map);
int if_ber_file(char *map_path);
int mega_map_check(t_mlx *mlx, int argc, char **argv);
#endif