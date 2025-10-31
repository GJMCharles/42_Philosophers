# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/21 15:37:15 by grcharle          #+#    #+#              #
#    Updated: 2025/10/28 15:48:18 by grcharle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -lmlx -lX11 -lXext -lm
NAME = so_long
NAME_SO_LONG_LIB = libsolong.a
LIBFT_DIR = libft
GET_NEXT_LINE_DIR = get_next_line
MINILIBX_DIR = minilibx
SRC = so_long.c \
		handle_movement_event.c \
		read_texture.c \
		rendering.c \
		utils.c \
		validation_of_map.c \
		validation.c \
		free.c \
		handle_press.c
	
NAMELIB = $(LIBFT_DIR)/libft.a
NAME_GET_NEXT_LINE_LIB = $(GET_NEXT_LINE_DIR)/libgetnextline.a
MINILIBX = $(MINILIBX_DIR)/libmlx.a
OBJ	= $(SRC:.c=.o)

all: $(NAME_SO_LONG_LIB)

$(NAME_SO_LONG_LIB): $(NAMELIB) $(NAME_GET_NEXT_LINE_LIB) $(MINILIBX) $(OBJ)
	ar rcs $(NAME_SO_LONG_LIB) $(OBJ)
	$(CC) $(NAME_SO_LONG_LIB) $(NAME_GET_NEXT_LINE_LIB) $(NAMELIB) -Lminilibx $(MLXFLAGS) -o $(NAME)

$(NAMELIB):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME_GET_NEXT_LINE_LIB):
	$(MAKE) -C $(GET_NEXT_LINE_DIR)
	
$(MINILIBX):
	$(MAKE) -C $(MINILIBX_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(GET_NEXT_LINE_DIR) clean
	$(MAKE) -C $(MINILIBX_DIR) clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(GET_NEXT_LINE_DIR) fclean
	rm -f $(NAME) $(NAME_SO_LONG_LIB)

re: fclean all

runtest: all
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) maps/empty_map_2.ber
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) maps/empty_map.ber
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) maps/false_map.ber
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) maps/map.txt
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) maps/no_collectible.ber
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) maps/no_player.ber
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) maps/no_exit.ber
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) maps/not_rect_map.ber
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) maps/open_map_2.ber
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) maps/open_map.ber
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) maps/two_exit.ber
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) maps/two_player.ber
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) maps/unreachable_ex.ber
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) maps/unreachable_col.ber
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) maps/small_map.ber
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) maps/map.ber

.PHONY: all clean fclean re
