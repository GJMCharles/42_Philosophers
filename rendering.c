/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 19:16:49 by grcharle          #+#    #+#             */
/*   Updated: 2025/10/24 19:44:17 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_player_position(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				game->player.x_player = x;
				game->player.y_player = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	player_render(t_game *game, int keycode)
{
	if (keycode == 0x77)
	{
		mlx_put_image_to_window(game->window.mlx,
			game->window.win, game->texture.player[0],
			game->player.x_player * 64, game->player.y_player * 64);
	}
	else if (keycode == 0x73)
	{
		mlx_put_image_to_window(game->window.mlx,
			game->window.win, game->texture.player[1],
			game->player.x_player * 64, game->player.y_player * 64);
	}
	else if (keycode == 0x64)
	{
		mlx_put_image_to_window(game->window.mlx,
			game->window.win, game->texture.player[3],
			game->player.x_player * 64, game->player.y_player * 64);
	}
	else if (keycode == 0x61)
	{
		mlx_put_image_to_window(game->window.mlx,
			game->window.win, game->texture.player[2],
			game->player.x_player * 64, game->player.y_player * 64);
	}
}

void	render(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	game->num_of_coin = 0;
	mlx_clear_window(game->window.mlx, game->window.win);
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			render_texture(game, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->window.mlx, game->window.win,
		game->texture.player[3],
		game->player.x_player * 64, game->player.y_player * 64);
}

void	render_texture(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->window.mlx,
		game->window.win, game->texture.floor, x * 64, y * 64);
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->window.mlx,
			game->window.win, game->texture.wall, x * 64, y * 64);
	if (game->map[y][x] == 'C')
	{
		mlx_put_image_to_window(game->window.mlx,
			game->window.win, game->texture.coin, x * 64, y * 64);
		game->num_of_coin++;
	}
	if (game->map[y][x] == 'E')
		mlx_put_image_to_window(game->window.mlx,
			game->window.win, game->texture.exit, x * 64, y * 64);
}
