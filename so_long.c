/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 19:07:31 by grcharle          #+#    #+#             */
/*   Updated: 2025/10/30 16:12:19 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init(t_game *game)
{
	game->player.move = 0;
	game->player.num_move = 0;
	game->window.mlx = mlx_init();
	if (!game->window.mlx)
	{
		free_everything(game);
		return (0);
	}
	game->window.win = mlx_new_window(game->window.mlx,
			get_length(game, 0) * 64, num_of_lines(game) * 64, "so_long");
	if (!game->window.win)
	{
		free_everything(game);
		return (0);
	}
	mlx_hook(game->window.win, 2, 1L << 0, handle_press, game);
	mlx_hook(game->window.win, 17, 0, handle_x_button, game);
	read_texture(game);
	render(game);
	mlx_loop(game->window.mlx);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	ft_memset(&game, 0, sizeof(t_game));
	if (argc != 2)
		return (0);
	game.name_map_file = argv[1];
	if (!validation_map_path(game))
	{
		ft_printf("Error\nThe extention of the file name Invalid");
		return (1);
	}
	if (!fill_map(num_of_lines(&game), &game))
	{
		ft_printf("Error\nInvalid map.");
		return (1);
	}
	find_player_position(&game);
	if (!check_validation(&game))
	{
		free_map(game.map);
		return (1);
	}
	if (!init(&game))
		return (1);
	return (0);
}
