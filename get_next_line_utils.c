/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucpardo <lucpardo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 12:51:37 by lucpardo          #+#    #+#             */
/*   Updated: 2025/06/03 20:35:11 by lucpardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (unsigned char)c)
		{
			return ((char *)str + i);
		}
		++i;
	}
	if (str[i] == '\0' && (unsigned char)c == '\0')
	{
		return ((char *)str + i);
	}
	return (NULL);
}

char	*ft_gnl_substr(char const *str, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	slen;
	size_t	i;

	if (str == NULL)
		return (NULL);
	slen = ft_strlen(str);
	if (start >= slen)
	{
		ptr = malloc(1);
		if (ptr)
			ptr[0] = '\0';
		return (ptr);
	}
	if (len > slen - start)
		len = slen - start;
	ptr = malloc(len + 1);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < len)
		ptr[i] = str[start + i];
		i++;
	ptr[i] = '\0';
	return (ptr);
}
