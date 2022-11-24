/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 16:58:30 by dwuthric          #+#    #+#             */
/*   Updated: 2022/11/24 23:51:13 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_mlx_ptr(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		return (MLX_ERROR);
	game->win_ptr = mlx_new_window(game->mlx_ptr,
			WINDOW_WIDTH, WINDOW_HEIGHT, "so_long");
	if (!game->win_ptr)
	{
		free(game->mlx_ptr);
		return (MLX_ERROR);
	}
	return (MLX_SUCCESS);
}

int	load_maps(t_game *game, int ac, char **av)
{
	int	i;

	game->levelcount = 0;
	game->levels = malloc(sizeof(*game->levels) * ac);
	if (!game->levels)
	{
		free(game->mlx_ptr);
		return (MLX_ERROR);
	}
	i = -1;
	while (++i < ac)
	{
		game->levels[game->levelcount++] = parse_map(av[i]);
		if (!game->levels[i])
			game->levelcount--;
	}
	if (game->levelcount == 0)
		return (MLX_ERROR);
	return (MLX_SUCCESS);
}

int	load_sprites(t_game *game)
{

}

int	init(t_game *game, int ac, char **av)
{
	if (!init_mlx_ptr(game))
		return (MLX_ERROR);
	if (!load_maps(game, ac, av))
	{
		free_game(game);
		return (MLX_ERROR);
	}
	if (!load_sprites(game))
	{
		free_game(game);
		return (MLX_ERROR);
	}
	return (MLX_SUCCESS);
}
