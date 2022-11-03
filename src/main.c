/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:03:08 by dwuthric          #+#    #+#             */
/*   Updated: 2022/11/03 12:13:06 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(void)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);

	ft_printf("success\n");
}
