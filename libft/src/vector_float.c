/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 00:07:41 by dwuthric          #+#    #+#             */
/*   Updated: 2023/01/09 00:08:14 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/vector.h"

float	vector_get_float(t_vector *this, size_t index)
{
	return (*(float *)vector_get(this, index));
}

void	vector_set_float(t_vector *this, float data, size_t index)
{
	vector_set(this, &data, index);
}

void	vector_add_float(t_vector *this, float data)
{
	vector_add(this, &data);
}

void	vector_add_at_float(t_vector *this, float data, size_t index)
{
	vector_add_at(this, &data, index);
}
