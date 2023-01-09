/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 23:06:21 by dwuthric          #+#    #+#             */
/*   Updated: 2023/01/09 00:04:47 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/vector.h"

int	vector_get_int(t_vector *this, size_t index)
{
	return (*(int *)vector_get(this, index));
}

void	vector_set_int(t_vector *this, int data, size_t index)
{
	vector_set(this, &data, index);
}

void	vector_add_int(t_vector *this, int data)
{
	vector_add(this, &data);
}

void	vector_add_at_int(t_vector *this, int data, size_t index)
{
	vector_add_at(this, &data, index);
}
