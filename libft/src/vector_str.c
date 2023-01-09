/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 23:11:02 by dwuthric          #+#    #+#             */
/*   Updated: 2023/01/09 00:04:57 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/vector.h"

char	*vector_get_str(t_vector *this, size_t index)
{
	return (*(char **)vector_get(this, index));
}

void	vector_set_str(t_vector *this, char *data, size_t index)
{
	vector_set(this, &data, index);
}

void	vector_add_str(t_vector *this, char *data)
{
	vector_add(this, &data);
}

void	vector_add_at_str(t_vector *this, char *data, size_t index)
{
	vector_add_at(this, &data, index);
}
