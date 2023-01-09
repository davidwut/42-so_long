/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 11:37:16 by dwuthric          #+#    #+#             */
/*   Updated: 2023/01/09 13:50:34 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/include/libft.h"
# include "../libft/include/vector.h"
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

# define START_C 'P'
# define EXIT_C 'E'
# define COLLECT_C 'C'

# define VALID_TILES "01CEP"

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

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
	t_pos	start;
	t_pos	exit;
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
int	load_sprites(t_game *game);

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
int	_valid_path(t_map *map, int x, int y);

/* pos_utils.c */
void	set_pos(t_pos *pos, int x, int y);

#endif
