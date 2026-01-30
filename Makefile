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

# Project Libft (+GetNextLine/+FtPrintF)
LIBFT := libft

CPPFLAGS := \
-I ./includes \
-I ./includes/$(LIBFT)

# Specifies options for the linker:
# example: -L/usr/local/lib
LDFLAGS := \
-L./includes/$(LIBFT)

# Lists libraries to link with:
LDLIBS := \
-lft \
-lpthread

SOURCES_M := \
main.c \
data.c \
node.c \
mutex.c \
simulation.c \
action_eat.c \
action_sleep.c \
action_think.c \
action_die.c \
utils.c

OBJECTS_M := \
$(patsubst ./philo/%.c,\
	.objects/.philo/%.o, \
	$(addprefix ./philo/, $(SOURCES_M)) \
)

DEPS_M := $(OBJECTS_M:.o=.d)
-include $(DEPS_M)

OBJECTS_DIR := .objects/.philo/

$(OBJECTS_DIR):
	mkdir -p $@

$(OBJECTS_DIR)%.o: ./philo/%.c | $(OBJECTS_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJECTS_M)
	@$(MAKE) -C ./includes/$(LIBFT) all
	$(CC) $(CFLAGS) $^ -o ./philo/$@ $(LDFLAGS) $(LDLIBS)

all: $(NAME)

clean:
	@$(MAKE) -C ./includes/$(LIBFT) clean
	@$(RM) $(OBJECTS_M)
	@$(RM) $(DEPS_M)
	@if [ -d  $(OBJECTS_DIR) ]; then \
		$(RM_DIR) -p $(OBJECTS_DIR); \
	fi

fclean: clean
	@$(MAKE) -C ./includes/$(LIBFT) fclean
	@$(RM) ./philo/$(NAME)

re: fclean all

norm:
	norminette -R $(DIR_MANDATORY)

runtest: all
	-valgrind \
	--leak-check=full \
	--show-leak-kinds=all \
	--track-origins=yes \
	-s ./$(NAME)/$(NAME) 4 410 200 200 7

.PRECIOUS: $(OBJECTS_DIR)

.PHONY: all clean fclean re norm runtest
