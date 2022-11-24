/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:41:37 by dwuthric          #+#    #+#             */
/*   Updated: 2022/11/24 23:50:10 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_path(t_map *map)
{
	(void) map;
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
		exit += (NULL != ft_strchr((const char *)(map->map[i]), 'E'));
		startpos += (NULL != ft_strchr((const char *)(map->map[i]), 'P'));
		collectible += (NULL != ft_strchr((const char *)(map->map[i]), 'C'));
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
