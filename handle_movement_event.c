/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_movement_event.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 19:14:14 by grcharle          #+#    #+#             */
/*   Updated: 2025/10/28 16:41:34 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	take_coin(t_game *game)
{
	if (game->map[game->player.y_player][game->player.x_player] == 'C')
	{
		game->map[game->player.y_player][game->player.x_player] = '0';
		game->num_of_coin--;
	}
}

void	win_game(t_game *game)
{
	if (game->map[game->player.y_player][game->player.x_player] == 'E'
			&& game->num_of_coin == 0)
	{
		free_everything(game);
		exit(0);
	}
}

void	handle_movement(int keycode, t_game *game)
{
	if (keycode == 0x77
		&& game->map[game->player.y_player - 1][game->player.x_player] != '1')
	{
		game->player.y_player -= 1;
		game->player.num_move++;
		game->player.move = 1;
	}
	else if (keycode == 0x73
		&& game->map[game->player.y_player + 1][game->player.x_player] != '1')
	{
		game->player.y_player += 1;
		game->player.num_move++;
		game->player.move = 1;
	}
	else
		handle_movement_left_right(keycode, game);
}

void	handle_movement_left_right(int keycode, t_game *game)
{
	if (keycode == 0x64
		&& game->map[game->player.y_player][game->player.x_player + 1] != '1')
	{
		game->player.x_player += 1;
		game->player.num_move++;
		game->player.move = 1;
	}
	else if (keycode == 0x61
		&& game->map[game->player.y_player][game->player.x_player - 1] != '1')
	{
		game->player.x_player -= 1;
		game->player.num_move++;
		game->player.move = 1;
	}
}
