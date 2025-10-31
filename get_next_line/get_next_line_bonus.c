/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 20:00:24 by grcharle          #+#    #+#             */
/*   Updated: 2025/08/25 20:17:13 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <limits.h>

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
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (result[i] && result[i] != '\n')
	{
		line[i] = result[i];
		i++;
	}
	if (result[i] == '\n')
	{
		line[i] = '\n';
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
	static char	*result[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= OPEN_MAX)
		return (NULL);
	result[fd] = read_line(fd, result[fd]);
	if (!result[fd])
		return (NULL);
	line = ft_get_line(result[fd]);
	result[fd] = update_result(result[fd]);
	return (line);
}

// int main(void)
// {
//     int fd1 = open("file1.txt", O_RDONLY);
//     int fd2 = open("file2.txt", O_RDONLY);
//     char *line;
//     if (fd1 < 0 || fd2 < 0)
//         return 1;
//     line = get_next_line(fd1);
//     printf("fd1: %s", line); free(line);
//     line = get_next_line(fd2);
//     printf("fd2: %s", line); free(line);
//     line = get_next_line(fd1);
//     printf("fd1: %s", line); free(line);
//     line = get_next_line(fd2);
//     printf("fd2: %s", line); free(line);
//     close(fd1);
//     close(fd2);
//     return 0;
// }