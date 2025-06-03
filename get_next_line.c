/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucpardo <lucpardo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 12:58:46 by lucpardo          #+#    #+#             */
/*   Updated: 2025/06/03 22:26:49 by lucpardo         ###   ########.fr       */
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
		return (ft_free_and_zero(buffer));
	newline_i = ft_strchr(*buffer, '\n');
	if (newline_i)
		len = newline_i - *buffer + 1;
	else
		len = ft_strlen(*buffer);
	line = ft_gnl_substr(*buffer, 0, len);
	if (line == NULL)
		return (ft_free_and_zero(buffer));
	if (newline_i && *(newline_i + 1))
	{
		temp = ft_gnl_substr(*buffer, len, ft_strlen(*buffer) - len);
		free(*buffer);
		*buffer = temp;
	}
	else
		*buffer = (free(*buffer), NULL);
	return (line);
}

static	char	*ft_freer(char **line_buffer, char *fd_buffer, char *result)
{
	if (line_buffer && *line_buffer)
	{
		free(*line_buffer);
		*line_buffer = NULL;
	}
	if (fd_buffer)
		free(fd_buffer);
	return (result);
}

char	*get_next_line(int fd)
{
	int			bytes_read;
	char		*fd_buffer;
	static char	*line_buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	fd_buffer = malloc(BUFFER_SIZE + 1);
	if (fd_buffer == NULL)
		return (NULL);
	while (!line_buffer || !ft_strchr(line_buffer, '\n'))
	{
		bytes_read = read(fd, fd_buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			if (bytes_read < 0)
				return (ft_freer(&line_buffer, fd_buffer, NULL));
			break ;
		}
		fd_buffer[bytes_read] = '\0';
		line_buffer = ft_gnl_strjoin(line_buffer, fd_buffer);
		if (line_buffer == NULL)
			return (ft_freer(NULL, fd_buffer, NULL));
	}
	free(fd_buffer);
	return (ft_extract_line(&line_buffer));
}
