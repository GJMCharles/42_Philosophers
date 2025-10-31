/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_press.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 15:45:50 by grcharle          #+#    #+#             */
/*   Updated: 2025/10/28 15:56:41 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_x_button(void *game)
{
	(void) game;
	free_everything(game);
	exit(0);
	return (0);
}

int	handle_press(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keycode == 0xff1b)
	{
		free_everything(game);
		exit(0);
	}
	handle_movement(keycode, game);
	if (game->player.move == 1)
		ft_printf("Number of move: %d\n", game->player.num_move);
	game->player.move = 0;
	take_coin(game);
	win_game(game);
	render(game);
	player_render(game, keycode);
	return (0);
}
