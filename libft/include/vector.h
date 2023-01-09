/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   this.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:44:03 by dwuthric          #+#    #+#             */
/*   Updated: 2023/01/08 21:10:47 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include "libft.h"

typedef struct s_vector
{
	void	*data;
	size_t	size;
	size_t	capacity;
	size_t	element_size;
}	t_vector;

t_vector	*vector_new(size_t element_size);
t_vector	*vector_new_with_capacity(size_t element_size, size_t capacity);
void		vector_destroy(t_vector *this);
void		vector_destroy_with(t_vector *this, void (*del)(void *));
void		vector_clear(t_vector *this);
void		*vector_get(t_vector *this, size_t index);
void		vector_set(t_vector *this, void *data, size_t index);
void		vector_resize(t_vector *this, size_t new_size);
void		vector_add(t_vector *this, void *data);
void		vector_add_at(t_vector *this, void *data, size_t index);
void		vector_remove(t_vector *this, size_t index);
int			vector_is_empty(t_vector *this);

/* Some sugar, wish we could use macros */
int			vector_get_int(t_vector *this, size_t index);
void		vector_set_int(t_vector *this, int data, size_t index);
void		vector_add_int(t_vector *this, int data);
void		vector_add_at_int(t_vector *this, int data, size_t index);

char		*vector_get_str(t_vector *this, size_t index);
void		vector_set_str(t_vector *this, char *data, size_t index);
void		vector_add_str(t_vector *this, char *data);
void		vector_add_at_str(t_vector *this, char *data, size_t index);

double		vector_get_double(t_vector *this, size_t index);
void		vector_set_double(t_vector *this, double data, size_t index);
void		vector_add_double(t_vector *this, double data);
void		vector_add_at_double(t_vector *this, double data, size_t index);

float		vector_get_float(t_vector *this, size_t index);
void		vector_set_float(t_vector *this, float data, size_t index);
void		vector_add_float(t_vector *this, float data);
void		vector_add_at_float(t_vector *this, float data, size_t index);

#endif
