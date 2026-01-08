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

NAME := philo

DIR_MANDATORY := $(NAME)

OBJECTS_DIR := .objects

SOURCES_MANDATORY := \
main.c \
initialisation.c \
utils.c \
thread.c

OBJECTS_MANDATORY := \
$(patsubst \
	$(DIR_MANDATORY)/%.c,\
	$(OBJECTS_DIR)/.$(DIR_MANDATORY)/%.o,\
	$(addprefix $(DIR_MANDATORY)/, $(SOURCES_MANDATORY))\
)

DEPS_MANDATORY := $(OBJECTS_MANDATORY:.o=.d)

-include $(DEPS_MANDATORY)

$(OBJECTS_DIR):
	mkdir -p $@/.$(DIR_MANDATORY)

$(OBJECTS_DIR)/.$(DIR_MANDATORY)/%.o: $(DIR_MANDATORY)/%.c | $(OBJECTS_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(NAME): LIBS $(OBJECTS_MANDATORY)

LIBS:
	$(MAKE) -C ./includes/$(LIBFT)

all: $(NAME)
	$(CC) $(CFLAGS) $(OBJECTS_MANDATORY) -o ./$^/$^ $(LDFLAGS) $(LDLIBS)
	echo -n "Generated executable: ./$^/$^\n"

clean:
	@$(MAKE) -C ./includes/$(LIBFT) clean
	@$(RM) $(OBJECTS_MANDATORY)
	@$(RM) $(DEPS_MANDATORY)
	@if [ -d  $(OBJECTS_DIR)/.$(DIR_MANDATORY) ]; then \
		$(RM_DIR) -p $(OBJECTS_DIR)/.$(DIR_MANDATORY); \
	fi

fclean: clean
	@$(MAKE) -C ./includes/$(LIBFT) fclean
	@$(RM) ./$(NAME)/$(NAME)

re: fclean all

norm:
	norminette -R $(DIR_MANDATORY)

runtest: all
	-valgrind \
	--leak-check=full \
	--show-leak-kinds=all \
	--track-origins=yes \
	-s ./$(NAME)/$(NAME) 5 3 3 3

.SECONDARY: $(OBJECTS_MANDATORY)

.PRECIOUS: $(OBJECTS_DIR)

.SILENT:

.PHONY: all clean fclean re
