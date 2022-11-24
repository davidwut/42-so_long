/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:07:09 by dwuthric          #+#    #+#             */
/*   Updated: 2022/11/07 12:08:39 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// on MacOS, x_mask of mlx_hook is useless -> set to 0

// ON_KEYDOWN		2	int (*f)(int keycode, void *param)
// ON_KEYUP*		3	int (*f)(int keycode, void *param)
// ON_MOUSEDOWN*	4	int (*f)(int button, int x, int y, void *param)
// ON_MOUSEUP		5	int (*f)(int button, int x, int y, void *param)
// ON_MOUSEMOVE	6	int (*f)(int x, int y, void *param)
// ON_EXPOSE*		12	int (*f)(void *param)
// ON_DESTROY		17	int (*f)(void *param)
// the int return value is almost never used

// int mlx_hook(mlx_win_list_t *win_ptr, int x_event, int x_mask,
//				int (*f)(), void *param)
// has aliases for:
// ON_KEYUP		-> int mlx_key_hook (void *win_ptr,
//					int (*funct_ptr)(), void *param);
// ON_MOUSEDOWN	-> int mlx_mouse_hook (void *win_ptr,
//					int (*funct_ptr)(), void *param);
// ON_EXPOSE	-> int mlx_expose_hook (void *win_ptr,
//					int (*funct_ptr)(), void *param);

void	close_window(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	free_game(game);
	exit(0);
}

int	keypress(int keycode, t_game *game)
{
	ft_printf("Keydown: %d\n", keycode);
	if (keycode == KEY_ESC)
		close_window(game);
	return (1);
}
