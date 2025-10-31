/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 18:52:01 by grcharle          #+#    #+#             */
/*   Updated: 2025/08/27 21:25:11 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char *result)
{
	char	*buffer;
	int		num_byte;

	num_byte = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while ((result == NULL || !ft_strchr(result, '\n')) && num_byte > 0)
	{
		num_byte = read(fd, buffer, BUFFER_SIZE);
		if (num_byte == -1)
		{
			free(result);
			free(buffer);
			return (NULL);
		}
		buffer[num_byte] = '\0';
		result = ft_strjoin(result, buffer);
	}
	free(buffer);
	return (result);
}

char	*ft_get_line(char *result)
{
	char	*line;
	int		i;

	if (!result || result[0] == '\0')
		return (NULL);
	i = 0;
	while (result[i] && result[i] != '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (result[i] && result[i] != '\n')
	{
		line[i] = result[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*update_result(char *result)
{
	char	*new_result;
	int		i;

	i = 0;
	if (!result)
		return (NULL);
	while (result[i] && result[i] != '\n')
		i++;
	if (!result[i])
	{
		free(result);
		return (NULL);
	}
	new_result = ft_strdup(result + i + 1);
	free(result);
	return (new_result);
}

char	*get_next_line(int fd)
{
	static char	*result;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	result = read_line(fd, result);
	if (!result)
		return (NULL);
	line = ft_get_line(result);
	result = update_result(result);
	if (!line)
	{
		free(result);
		free(line);
		return (NULL);
	}
	return (line);
}
