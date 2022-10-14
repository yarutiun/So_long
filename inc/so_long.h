/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 00:01:46 by yarutiun          #+#    #+#             */
/*   Updated: 2022/10/14 14:30:33 by yarutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../mlx/mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif
// window size is going to be: x amount of elements 
//in row * 100, y amount of elements in colomn * 100
// if so, then texture size is going to be 100, 100
typedef struct t_tuple
{
	int	row;
	int	col;
}			t_tuple;

typedef struct s_assets
{
	void	*walls;
	void	*floor;
	void	*sprite;
	void	*collectible;
	void	*portal_off;
	void	*portal_on;
	void	*enemie;
	int		img_width;
	int		img_height;
	int		poz_x;
	int		poz_y;
}	t_assets;

typedef struct s_mlx
{
	void		*mlx_pointer;
	void		*window;
	char		**map;
	char		**map_cpy;
	int			fd;
	int			row;
	int			col;
	int			dlina;
	int			shirina;
	int			beforex;
	int			beforey;
	bool		was_e;
	char		last_square;
	int			map_width;
	int			map_height;
	int			elements_count;
	int			elements_counted;
	int			counter;
	int			counter2;
	size_t		len;
	int			player_x_pos;
	int			player_y_pos;
	int			enemie_x_pos;
	int			enemie_y_pos;
	int			sprite_width;
	int			sprite_height;
	int			current_score;
	t_assets	picures;
	t_tuple		coordinates;
}	t_mlx;

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

//all the get_next_line functions and utils
char		*get_next_line(int fd);
char		*read_to_nl_or_eof(int fd, char *line);
char		*ft_strjoin(char *s1, char *s2);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
size_t		ft_strlen(const char *s);
char		*ft_strchr(char *str, int c);
void		ft_putstr_fd(char *s);
char		*ft_itoa(int nb);
char		*if_zero(char *s);
int			len(long nb);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
void		*put_img(t_mlx *mlx_s, int i, int j);
void		initialize(t_mlx *mlx_s);

//errors
int			print_error_msg(char *msg);
void		if_correct_argc(int argc);

//working with map and converting it in char **
void		x_y_of_map(char *map_adress, int *map_height, int *map_width);
char		**create_matrix(char *map_path);
void		free_all_map(char **map);

//validating the map
int			if_rectangle(char *map_path, char **map);
int			if_one_player(char *map_path, char **map);
int			if_collectible(char **map);
int			if_correct_symbols(char **map);
int			if_ber_file(char *map_path);
void		check_collect(bool was_e, t_mlx *mlx_s);
int			if_exit(char *map_path, char **map);
void		mega_map_check(int argc, char **argv, char **map);
void		game_over_loss(t_mlx *mlx_s);
void		smth(t_mlx *mlx_s);
void		smth2(t_mlx *mlx_s);
void	if_last_is_e(char i, t_mlx *mlx_s);
//key handling
int			press_anything(int keycode, t_mlx *mlx_s);
void		find_player_pos_cpy(t_mlx *mlx_s);
void		find_player_pos(t_mlx *mlx_s);
void		push_to_img(t_mlx *mlx_s, int i, int j, void *img);
int			x_close(void);
void		reset_player_pos(t_mlx *mlx_s, int *row, int *col);
void		game_over(t_mlx *mlx_s);
int			count(char **map);
void		counting_reachable(t_mlx *mlx_s, int x, int y, int *a);
int			has_valid_path(t_mlx *mlx_s);
char		**create_matrix2(char *map_path);
int			find_player_pos_y(t_mlx *mlx_s);
int			find_player_pos_x(t_mlx *mlx_s);
void		make_map_size(t_mlx *mlx_s, char *adress, char **map_cpy);
void		map_cpy_to_struct(t_mlx *mlx_s, char **map_cpy);
//rendering the map
void		window_create_and_x_y(t_mlx *mlx_s, char *map_adress);
void		render_map(t_mlx *mlx_s);
t_assets	load_images(t_mlx *mlx_s);
void		change_map(t_mlx *mlx_s, int row, int col, char new_square);
int			key_handler(int keycode, t_mlx *mlx_s);

#endif