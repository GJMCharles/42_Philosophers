/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 19:20:37 by grcharle          #+#    #+#             */
/*   Updated: 2025/10/30 16:14:40 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	num_of_lines(t_game *game)
{
	int		fd;
	int		i;
	char	buffer;
	int		check;

	fd = open(game->name_map_file, O_RDONLY);
	if (fd == -1)
		return (0);
	i = 1;
	while (1)
	{
		check = read(fd, &buffer, 1);
		if (check == -1)
			return (0);
		if (check == 0)
			break ;
		if (buffer == '\n')
			i++;
	}
	close(fd);
	return (i);
}

int	fill_map(int num_line, t_game *game)
{
	int	i;
	int	fd;

	fd = open(game->name_map_file, O_RDONLY);
	if (fd == -1)
		return (0);
	i = 0;
	game->map = malloc((num_line + 1) * sizeof(char *));
	if (!game->map)
		return (0);
	while (i < num_line)
	{
		game->map[i] = get_next_line(fd);
		if (game->map[i] == NULL)
		{
			free_map(game->map);
			close(fd);
			return (0);
		}
		i++;
	}
	game->map[i] = NULL;
	close(fd);
	return (1);
}

int	get_length(t_game *game, int i)
{
	int	j;

	j = 0;
	while (game->map[i][j])
		j++;
	return (j);
}

int	num_char_in_map(char **map, char c)
{
	int	y;
	int	x;
	int	count;

	count = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == c)
				count++;
			x++;
		}
		y++;
	}
	return (count);
}
