/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:03:08 by dwuthric          #+#    #+#             */
/*   Updated: 2022/11/24 20:39:58 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	usage(char *name)
{
	ft_printf("Usage: %s map_1 map_2 [...] map_n\n", name);
	ft_printf("%s",  " Treats every argument as a pathname to a map to load.\n");
	ft_printf("%s", " If a pathname provided is invalid, it is skipped.\n");
	exit(0);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac < 2)
		usage(av[0]);
	if (!init(&game, ac - 1, av + 1))
		error("Important game data failed to initialize.\n");
	mlx_hook(game.win_ptr, ON_KEYPRESS, KEY_PRESS_MASK, keypress, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
