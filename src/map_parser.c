/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 00:39:05 by dwuthric          #+#    #+#             */
/*   Updated: 2022/11/24 23:42:17 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	append_to_map(t_map *map, char *line)
{
	int		i;
	char	**new_map;

	if (!line)
		return ;
	new_map = malloc(sizeof(*new_map) * map->height + 1);
	if (!new_map)
		return ;
	i = -1;
	while (++i < map->height)
		new_map[i] = map->map[i];
	line[ft_strlen(line) - 1] = 0;
	new_map[i] = line;
	free(map->map);
	map->map = new_map;
	map->height += 1;
}

int	fill_map(t_map *map, int fd)
{
	char	*line;

	map->map = malloc((sizeof(*map->map)));
	if (!map->map)
		return (MLX_ERROR);
	line = get_next_line(fd);
	if (!line)
	{
		free(map->map);
		return (MLX_ERROR);
	}
	map->width = ft_strlen(line) - 1;
	map->height = 1;
	line[map->width] = 0;
	map->map[0] = line;
	while (line)
	{
		line = get_next_line(fd);
		append_to_map(map, line);
	}
	return (MLX_SUCCESS);
}

t_map	*parse_map(char *pathname)
{
	t_map	*map;
	int		fd;

	fd = open(pathname, O_RDONLY);
	if (fd == -1)
		return (NULL);
	map = ft_calloc(1, sizeof(*map));
	if (!map)
		return (NULL);
	fill_map(map, fd);
	if (!valid_map(map))
	{
		free_map(map);
		return (NULL);
	}
	return (map);
}
