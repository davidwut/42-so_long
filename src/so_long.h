/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 11:37:16 by dwuthric          #+#    #+#             */
/*   Updated: 2022/11/24 23:51:00 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/include/libft.h"
# include "keycodes.h"

# include <fcntl.h>
# include <math.h>
# include <stdlib.h>

# ifdef __gnu_linux__
#  include <mlx.h>
# elif __APPLE__
#  include "../mlx/mlx.h"
# endif

# define WINDOW_WIDTH 1200
# define WINDOW_HEIGHT 600
# define MLX_ERROR 0
# define MLX_SUCCESS 1

# define VALID_TILES "01CEP"

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_image;

typedef struct s_map
{
	int	width;
	int	height;
	char **map;
}	t_map;

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_image	tile_sprites[256];
	t_map	**levels;
	int		levelcount;
}	t_game;

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_player
{
	t_pos	pos;
	t_image	sprite;
}	t_player;

/* colors.c */
int		create_trgb(int t, int r, int g, int b);
int		get_t(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);

/* init_data.c */
int	init(t_game *game, int ac, char **argv);
int	init_mlx_ptr(t_game *game);
int	load_maps(t_game *game, int ac, char **av);
int	load_sprites(t_game);

/* event_handler.c */
void	close_window(t_game *game);
int		keypress(int keycode, t_game *game);

/* errors.c */
void	error(char *msg);

/* free.c */
void	free_map(t_map *map);
void	free_game(t_game *game);

/* map_parser.c */
void	append_to_map(t_map *map, char *line);
int		fill_map(t_map *map, int fd);
t_map	*parse_map(char *pathname);

/* map_validate.c */
int	valid_line(char *line, int len);
int	valid_map(t_map *map);
int	valid_path(t_map *map);
int	valid_borders(t_map *map);

#endif
