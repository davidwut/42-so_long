/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_double.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 00:08:21 by dwuthric          #+#    #+#             */
/*   Updated: 2023/01/09 00:08:41 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/vector.h"

double	vector_get_double(t_vector *this, size_t index)
{
	return (*(double *)vector_get(this, index));
}

void	vector_set_double(t_vector *this, double data, size_t index)
{
	vector_set(this, &data, index);
}

void	vector_add_double(t_vector *this, double data)
{
	vector_add(this, &data);
}

void	vector_add_at_double(t_vector *this, double data, size_t index)
{
	vector_add_at(this, &data, index);
}
