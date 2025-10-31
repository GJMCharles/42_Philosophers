/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 15:31:05 by grcharle          #+#    #+#             */
/*   Updated: 2025/10/28 16:57:40 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx/mlx.h"
# include <unistd.h>
# include <fcntl.h>
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"

typedef struct s_window
{
	void	*mlx;
	void	*win;
}	t_window;

typedef struct s_texture
{
	void	*player[4];
	void	*wall;
	void	*floor;
	void	*coin;
	void	*exit;
	int		height;
	int		width;
}	t_texture;

typedef struct s_player
{
	int	x_player;
	int	y_player;
	int	move;
	int	num_move;
}	t_player;

typedef struct s_game
{
	t_window	window;
	t_player	player;
	t_texture	texture;
	char		**map;
	int			num_of_coin;
	char		*name_map_file;
}	t_game;

int		check_rectangle(t_game *game);
int		surrounded_by_walls(t_game *game);
int		check_exit_start_collectible(t_game *game);
void	print_message(int num_of_error);
int		check_validation(t_game *game);
int		validation_map_path(t_game game);
int		flood_fill(char **map, int playery, int playerx);
int		check_validation_exit_coll_path(t_game *game);
int		num_of_lines(t_game *game);
int		fill_map(int num_line, t_game *game);
int		get_length(t_game *game, int i);
int		num_char_in_map(char **map, char c);
void	find_player_position(t_game *game);
void	player_render(t_game *game, int keycode);
void	render(t_game *game);
void	read_texture(t_game *game);
int		handle_x_button(void *game);
void	take_coin(t_game *game);
void	win_game(t_game *game);
void	handle_movement(int keycode, t_game *game);
void	handle_movement_left_right(int keycode, t_game *game);
int		handle_press(int keycode, void *param);
void	free_map(char **arr);
void	free_everything(t_game *game);
void	render_texture(t_game *game, int x, int y);
void	read_texture_player(t_game *game);

#endif
