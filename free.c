/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 17:04:28 by grcharle          #+#    #+#             */
/*   Updated: 2025/10/26 18:45:59 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_everything(t_game *game)
{
	free_map(game->map);
	if (game->texture.coin)
		mlx_destroy_image(game->window.mlx, game->texture.coin);
	if (game->texture.exit)
		mlx_destroy_image(game->window.mlx, game->texture.exit);
	if (game->texture.floor)
		mlx_destroy_image(game->window.mlx, game->texture.floor);
	if (game->texture.wall)
		mlx_destroy_image(game->window.mlx, game->texture.wall);
	if (game->texture.player[0])
		mlx_destroy_image(game->window.mlx, game->texture.player[0]);
	if (game->texture.player[1])
		mlx_destroy_image(game->window.mlx, game->texture.player[1]);
	if (game->texture.player[2])
		mlx_destroy_image(game->window.mlx, game->texture.player[2]);
	if (game->texture.player[3])
		mlx_destroy_image(game->window.mlx, game->texture.player[3]);
	if (game->window.win)
		mlx_destroy_window(game->window.mlx, game->window.win);
	if (game->window.mlx)
	{
		mlx_destroy_display(game->window.mlx);
		free(game->window.mlx);
	}
}
