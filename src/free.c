/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:59:00 by dwuthric          #+#    #+#             */
/*   Updated: 2022/11/24 23:01:24 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_map *map)
{
	int	i;

	if (!map)
		return ;
	i = -1;
	while (++i < map->height)
	{
		if (map->map[i])
		{
			free(map->map[i]);
			map->map[i] = NULL;
		}
	}
	free(map);
}

void	free_game(t_game *game)
{
	int	i;

	if (!game)
		return ;
	i = -1;
	while (++i < game->levelcount)
		free_map(game->levels[i]);
	if (game->mlx_ptr)
		free(game->mlx_ptr);
}
