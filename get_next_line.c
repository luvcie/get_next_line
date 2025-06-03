/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucpardo <lucpardo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 12:58:46 by lucpardo          #+#    #+#             */
/*   Updated: 2025/06/03 20:04:34 by lucpardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static char	*ft_extract_line(char **buffer)
{
	char	*newline_i;
	char	*line;
	char	*temp;
	int		len;

	if (*buffer == NULL || **buffer == '\0')
		return (free_and_zero(buffer));
	newline_i = ft_strchr(*buffer, '\n');
	if (newline_i)
		len = newline_i - *buffer + 1;
	else
		len = ft_strlen(*buffer);
	line = ft_substr(*buffer, 0, len);
	if (line == NULL)
		return (free_and_zero(buffer));
	if (newline_i && *(newline_i + 1))
	{
		temp = ft_substr(*buffer, len, ft_strlen(*buffer) - len);
		free(*buffer);
		*buffer = temp;
	}
	else
		*buffer = (free(*buffer), NULL);
	return (line);
}

char	*get_next_line(int fd)
{
	int			bytes_read;
	char		local_read_buffer[BUFFER_SIZE + 1];
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (!ft_strchr(buffer, '\n'))
	{
		bytes_read = read(fd, local_read_buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			if (bytes_read < 0)
				return (free(buffer), buffer = NULL, NULL);
			break ;
		}
		local_read_buffer[bytes_read] = '\0';
		buffer = ft_strjoin_gnl(buffer, local_read_buffer);
		if (buffer == NULL)
			return (NULL);
	}
	return (extract_line(&buffer));
}
