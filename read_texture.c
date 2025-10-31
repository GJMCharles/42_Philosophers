/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 19:24:11 by grcharle          #+#    #+#             */
/*   Updated: 2025/10/30 16:13:22 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_texture(t_game *game)
{
	read_texture_player(game);
	game->texture.wall = mlx_xpm_file_to_image(game->window.mlx,
			"texture/wall.xpm",
			&game->texture.width, &game->texture.height);
	game->texture.floor = mlx_xpm_file_to_image(game->window.mlx,
			"texture/floor.xpm",
			&game->texture.width, &game->texture.height);
	game->texture.coin = mlx_xpm_file_to_image(game->window.mlx,
			"texture/coin.xpm",
			&game->texture.width, &game->texture.height);
	game->texture.exit = mlx_xpm_file_to_image(game->window.mlx,
			"texture/exit.xpm",
			&game->texture.width, &game->texture.height);
	if (!game->texture.player[0] || !game->texture.player[1]
		|| !game->texture.player[2] || !game->texture.player[3]
		|| !game->texture.wall || !game->texture.floor
		|| !game->texture.coin || !game->texture.exit)
	{
		free_everything(game);
		exit(0);
	}
}

void	read_texture_player(t_game *game)
{
	game->texture.player[0] = mlx_xpm_file_to_image(game->window.mlx,
			"texture/player_up.xpm",
			&game->texture.width, &game->texture.height);
	game->texture.player[1] = mlx_xpm_file_to_image(game->window.mlx,
			"texture/player_down.xpm",
			&game->texture.width, &game->texture.height);
	game->texture.player[2] = mlx_xpm_file_to_image(game->window.mlx,
			"texture/player_left.xpm",
			&game->texture.width, &game->texture.height);
	game->texture.player[3] = mlx_xpm_file_to_image(game->window.mlx,
			"texture/player_right.xpm",
			&game->texture.width, &game->texture.height);
}
