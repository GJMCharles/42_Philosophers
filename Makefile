# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/29 11:55:25 by grcharle          #+#    #+#              #
#    Updated: 2025/11/06 19:47:15 by grcharle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL := all

CC := cc
CFLAGS := -Wall -Wextra -Werror -pedantic
CPPFLAGS :=
RM := rm -f

LIBFT := libft

# Specifies options for the linker:
# example: -L/usr/local/lib
LDFLAGS :=

# Lists libraries to link with:
# example: -lm -lpthread
LDLIBS := \
	-I ./philo \
	-I ./philo/$(LIBFT)

NAME := philo
# NAME_BONUS := philo_bonus

DIR_MANDATORY := $(NAME)
# DIR_BONUS := $(NAME_BONUS)

OBJECTS_DIR := .objects

RM := rm -f -v
RM_DIR := rmdir -v

SOURCES_MANDATORY := \
main.c

# SOURCES_BONUS := \
# main.c

OBJECTS_MANDATORY := $(patsubst \
	$(DIR_MANDATORY)/%.c,$(OBJECTS_DIR)/.$(DIR_MANDATORY)/%.o,\
	$(addprefix $(DIR_MANDATORY)/, $(SOURCES_MANDATORY))\
)
# OBJECTS_BONUS := $(patsubst \
# 	$(DIR_BONUS)/%.c,$(OBJECTS_DIR)/.$(DIR_BONUS)/%.o,\
# 	$(addprefix $(DIR_BONUS)/, $(SOURCES_BONUS))\
# )

DEPS_MANDATORY := $(OBJECTS_MANDATORY:.o=.d)
# DEPS_BONUS := $(OBJECTS_BONUS:.o=.d)

-include $(DEPS_MANDATORY) # $(DEPS_BONUS)

$(LIBS):
	$(MAKE) -C ./philo/$(LIBFT)

$(OBJECTS_DIR):
	mkdir -p $@/.$(DIR_MANDATORY)
# 	mkdir -p $@/.$(DIR_BONUS)

$(OBJECTS_DIR)/.$(DIR_MANDATORY)/%.o: $(DIR_MANDATORY)/%.c | $(OBJECTS_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDLIBS) -c $< -o $@

# $(OBJECTS_DIR)/.$(DIR_BONUS)/%.o: $(DIR_BONUS)/%.c | $(OBJECTS_DIR)
# 	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(NAME): $(LIBS) $(OBJECTS_MANDATORY)
	$(CC) $(CFLAGS) $< -o $(OBJECTS_DIR)/$@ $(LDFLAGS) $(LDLIBS)

# $(NAME_BONUS): $(OBJECTS_BONUS)
# 	$(CC) $(CFLAGS) $< -o $(OBJECTS_DIR)/$@ $(LDFLAGS) $(LDLIBS)

all: $(NAME)

# bonus: $(NAME_BONUS)

clean:
	$(MAKE) -C ./philo/$(LIBFT) clean
	@$(RM) $(OBJECTS_MANDATORY)
	@$(RM) $(DEPS_MANDATORY)
# 	@$(RM) $(OBJECTS_BONUS)
# 	@$(RM) $(DEPS_BONUS)

fclean: clean
	$(MAKE) -C ./philo/$(LIBFT) fclean
	@$(RM) -r $(OBJECTS_DIR)/$(NAME)
# 	@$(RM) $(OBJECTS_DIR)/$(NAME_BONUS)
# 	@if [ -d $(OBJECTS_DIR)/.$(DIR_MANDATORY) ]; then \
# 		$(RM_DIR) $(OBJECTS_DIR)/.$(DIR_MANDATORY); \
# 	fi
# 	@if [ -d $(OBJECTS_DIR)/.$(DIR_BONUS) ]; then \
# 		$(RM_DIR) $(OBJECTS_DIR)/.$(DIR_BONUS); \
# 	fi

re: fclean all

norm:
	norminette -R $(DIR_MANDATORY)
	norminette -R $(DIR_BONUS)

# .SECONDARY: $(OBJECTS_MANDATORY) $(OBJECTS_BONUS)

# .PRECIOUS: $(OBJECTS_DIR)

# .SILENT:

.PHONY: all clean fclean re bonus
