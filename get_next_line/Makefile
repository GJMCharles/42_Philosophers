# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/24 22:03:50 by grcharle          #+#    #+#              #
#    Updated: 2025/08/25 20:24:27 by grcharle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= cc
CFLAGS	= -Wall -Wextra -Werror -D BUFFER_SIZE=42
NAME	= libgetnextline.a
SRC	= get_next_line.c \
	get_next_line_utils.c

OBJ	= $(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean 
	rm -f $(NAME)

re:	fclean $(NAME)

.PHONY: clean all fclean re
