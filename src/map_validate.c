/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:41:37 by dwuthric          #+#    #+#             */
/*   Updated: 2023/01/09 13:12:57 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	_valid_path(t_map *map, int x, int y)
{
	(void)x;
	(void)y;
	(void) map;
	return (0);
}

int	valid_path(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (map->map[i][j] == START_C)
				set_pos(&map->start, i, j);
			else if(map->map[i][j] == EXIT_C)
				set_pos(&map->exit, i, j);
		}
	}

	return (1);
}

int	valid_borders(t_map *map)
{
	int	i;
	int	exit;
	int	startpos;
	int	collectible;

	i = -1;
	exit = 0;
	startpos = 0;
	collectible = 0;
	while (++i < map->height)
	{
		exit += (NULL != ft_strchr((const char *)(map->map[i]), EXIT_C));
		startpos += (NULL != ft_strchr((const char *)(map->map[i]), START_C));
		collectible += (NULL != ft_strchr((const char *)(map->map[i]), COLLECT_C));
		if (map->map[i][0] != '1'
			|| map->map[i][map->width - 1] != '1')
			return (0);
	}
	i = -1;
	while (++i < map->width)
		if (map->map[0][i] != '1' || map->map[map->height - 1][i] != '1')
			return (0);
	return (exit == 1 && startpos == 1 && collectible >= 1);
}

int	valid_line(char *line, int len)
{
	if((int)ft_strlen(line) != len)
		return (0);
	while (*line)
	{
		if (!ft_strchr(VALID_TILES, *line))
			return (0);
		line++;
	}
	return (1);
}

int	valid_map(t_map *map)
{
	int	i;

	if (map->height <= 2 || map->width <= 2)
		return (0);
	i = -1;
	while (++i < map->height)
		if (!valid_line(map->map[i], map->width))
			return (0);
	if (!valid_borders(map) || !valid_path(map))
		return (0);
	return (1);
}
