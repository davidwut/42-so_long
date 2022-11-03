/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 14:27:32 by dwuthric          #+#    #+#             */
/*   Updated: 2022/10/29 15:03:14 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static void	free_null(char **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

static char	*strslice(char **memory, int idx)
{
	char	*res;
	char	*tmp;

	if (idx <= 0)
	{
		if (**memory == 0)
		{
			free_null(memory);
			return (NULL);
		}
		res = *memory;
		*memory = NULL;
		return (res);
	}
	tmp = ft_substr(*memory, idx, BUFFER_SIZE);
	res = *memory;
	res[idx] = 0;
	*memory = tmp;
	return (res);
}

static char	*read_line(int fd, char **memory)
{
	char	*buffer;
	char	*tmp;
	int		bytes_read;

	bytes_read = 0;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (ft_strchr(*memory, '\n') == NULL)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			free(buffer);
			return (strslice(memory, bytes_read));
		}
		buffer[bytes_read] = 0;
		tmp = ft_strjoin(*memory, buffer);
		free(*memory);
		*memory = tmp;
	}
	free(buffer);
	return (strslice(memory, ft_strchr(*memory, '\n') - *memory + 1));
}

char	*get_next_line(int fd)
{
	static char	*memory[OPEN_MAX];
	char		*line;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	if (!memory[fd])
		memory[fd] = ft_strdup("");
	line = read_line(fd, &memory[fd]);
	return (line);
}
