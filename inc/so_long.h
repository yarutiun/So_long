/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 00:01:46 by yarutiun          #+#    #+#             */
/*   Updated: 2022/09/21 12:20:48 by yarutiun         ###   ########.fr       */
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
# define WIDTH 900	// Width of the window (in pixels)
# define HEIGHT 900	// Height of the window (in pixels)

typedef struct	s_program
 {
	void	*mlx_pointer;
	void	*window;

}				t_program;

typedef struct s_data
{
	char	**map;
	int		fd;
	int		map_width;
	int		map_height;
	int		counter;
	int		counter2;
}	t_data;

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
void print_error_msg(char *msg);
void if_correct_argc(int argc);

//working with map and converting it in char **
void x_y_of_map(char *map_adress, int *map_height, int *map_width);
char **create_matrix(char *map_path);
void free_all_map(char **map);

//validating the map
int if_rectangle(char *map_path, char **map);
int if_one_player(char *map_path, char **map);
int if_collectible(char *map_path, char **map);
#endif