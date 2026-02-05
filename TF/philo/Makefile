# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/12 00:18:47 by grcharle          #+#    #+#              #
#    Updated: 2025/12/12 00:18:49 by grcharle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Force default rule as : 'all'
.DEFAULT_GOAL := all

# Hide message 'Entering directory' & 'Leaving directory'
MAKEFLAGS += --no-print-directory

CC := cc
CFLAGS := -Wall -Wextra -Werror -pedantic

# Delete files & empty directories
RM := rm -f -v
RM_DIR := rmdir -v

NAME := philo

CPPFLAGS := \
-I ./includes

# Specifies options for the linker:
# example: -L/usr/local/lib
LDFLAGS := \
-L./includes

# Lists libraries to link with:
LDLIBS := \
-lpthread

SOURCES_DIR := sources

SOURCES_FILES := \
main.c \
utils.c \
data.c \
threads.c \
simulation.c \
actions.c \
validation.c

SOURCES := $(addprefix $(SOURCES_DIR)/, $(SOURCES_FILES))

OBJECTS_DIR := .objects

$(OBJECTS_DIR):
	mkdir -p $@

OBJECTS_FILES := \
$(patsubst \
	$(SOURCES_DIR)/%.c,\
	$(OBJECTS_DIR)/%.o,\
	$(SOURCES)\
)

DEPENDANCIES := $(OBJECTS_FILES:.o=.d)
-include $(DEPENDANCIES)

$(OBJECTS_DIR)/%.o: $(SOURCES_DIR)/%.c | $(OBJECTS_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJECTS_FILES)
	$(CC) $(CFLAGS) $^ -o ./$@ $(LDFLAGS) $(LDLIBS)

all: $(NAME)

clean:
	@$(RM) $(OBJECTS_FILES)
	@$(RM) $(DEPENDANCIES)
	@if [ -d  $(OBJECTS_DIR) ]; then \
		$(RM_DIR) -p $(OBJECTS_DIR); \
	fi

fclean: clean
	@$(RM) ./$(NAME)

re: fclean all

norm:
	norminette -R .

runtest: all
	-valgrind \
	--leak-check=full \
	--show-leak-kinds=all \
	--track-origins=yes \
	-s ./$(NAME) 5 599 200 200 7

.PRECIOUS: $(OBJECTS_DIR)

.PHONY: all clean fclean re norm runtest

.DELETE_ON_ERROR:
