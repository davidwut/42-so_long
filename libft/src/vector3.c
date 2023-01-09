/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 21:14:38 by dwuthric          #+#    #+#             */
/*   Updated: 2023/01/09 12:08:39 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/vector.h"

int	vector_is_empty(t_vector *this)
{
	if (!this)
		return (-1);
	return (this->size == 0);
}

void	vector_destroy_with(t_vector *this, void (*del)(void *))
{
	size_t	i;

	if (!this)
		return ;
	i = 0;
	while (i < this->size)
	{
		del(this->data + i * this->element_size);
		i++;
	}
	vector_destroy(this);
}
