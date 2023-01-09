/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:43:21 by dwuthric          #+#    #+#             */
/*   Updated: 2023/01/09 12:08:07 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/vector.h"

t_vector	*vector_new(size_t element_size)
{
	t_vector	*this;

	this = malloc(sizeof(*this));
	if (!this)
		return (NULL);
	this->data = malloc(element_size);
	if (!this->data)
	{
		free(this);
		return (NULL);
	}
	this->size = 0;
	this->capacity = 1;
	this->element_size = element_size;
	return (this);
}

t_vector	*vector_new_with_capacity(size_t element_size, size_t capacity)
{
	t_vector	*this;

	this = malloc(sizeof(*this));
	if (!this)
		return (NULL);
	this->data = malloc(element_size * capacity);
	if (!this->data)
	{
		free(this);
		return (NULL);
	}
	this->size = 0;
	this->capacity = capacity;
	this->element_size = element_size;
	return (this);
}

void	vector_destroy(t_vector *this)
{
	if (!this)
		return ;
	free(this->data);
	free(this);
}

void	vector_clear(t_vector *this)
{
	if (!this)
		return ;
	this->size = 0;
}

void	*vector_get(t_vector *this, size_t index)
{
	if (!this || index >= this->size)
		return (NULL);
	return (this->data + index * this->element_size);
}
