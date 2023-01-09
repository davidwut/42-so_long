/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:10:26 by dwuthric          #+#    #+#             */
/*   Updated: 2023/01/09 12:07:37 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/vector.h"

void	vector_set(t_vector *this, void *data, size_t index)
{
	if (!this || index >= this->size)
		return ;
	ft_memcpy(this->data + index * this->element_size,
		data, this->element_size);
}

void	vector_resize(t_vector *this, size_t new_size)
{
	void	*new_data;

	if (!this)
		return ;
	new_data = malloc(this->element_size * new_size);
	if (!new_data)
		return ;
	ft_memcpy(new_data, this->data, this->size * this->element_size);
	free(this->data);
	this->data = new_data;
	this->capacity = new_size;
}

void	vector_add(t_vector *this, void *data)
{
	if (!this)
		return ;
	if (this->size == this->capacity)
		vector_resize(this, this->capacity * 2);
	ft_memcpy(this->data + this->size * this->element_size,
		data,
		this->element_size);
	this->size++;
}

void	vector_add_at(t_vector *this, void *data, size_t index)
{
	if (!this || index > this->size)
		return ;
	if (this->size == this->capacity)
		vector_resize(this, this->capacity * 2);
	ft_memcpy(this->data + (index + 1) * this->element_size,
		this->data + index * this->element_size,
		(this->size - index) * this->element_size);
	ft_memcpy(this->data + index * this->element_size,
		data,
		this->element_size);
	this->size++;
}

void	vector_remove(t_vector *this, size_t index)
{
	if (!this || index >= this->size)
		return ;
	ft_memcpy(this->data + index * this->element_size,
		this->data + (index + 1) * this->element_size,
		(this->size - index - 1) * this->element_size);
	this->size--;
}
