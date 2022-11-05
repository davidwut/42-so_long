/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:03:08 by dwuthric          #+#    #+#             */
/*   Updated: 2022/11/05 16:42:55 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// on MacOS, x_mask of mlx_hook is useless -> set to 0

void	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free(data->mlx_ptr);
	exit(0);
}

int	handle_no_event(void *data)
{
	(void) data;
	return (0);
}

int	handle_keydown(int keycode, t_data *data)
{
	(void) data;
	ft_printf("Key down: %d\n", keycode);
	if (keycode == KEY_ESC)
		close_window(data);
	return (0);
}

int	handle_keyup(int keycode, t_data *data)
{
	(void) data;
	ft_printf("Key up: %d\n", keycode);
	return (0);
}

int	init(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (MLX_ERROR);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "so_long");
	if (data->win_ptr == NULL)
	{
		free(data->mlx_ptr);
		return (MLX_ERROR);
	}
	return (MLX_SUCCESS);
}

int	main(void)
{
	t_data	data;

	if (!init(&data))
		return (1);
	mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data);
	mlx_hook(data.win_ptr, ON_KEYDOWN, 0, handle_keydown, &data);

	mlx_loop(data.mlx_ptr);

	free(data.mlx_ptr);
	return (0);
}
