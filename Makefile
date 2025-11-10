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

# .DEFAULT_GOAL := all

# CC := cc
# CFLAGS := -Wall -Wextra -Werror -pedantic
# CPPFLAGS := -I.

# # Specifies options for the linker:
# # example: -L/usr/local/lib
# LDFLAGS :=

# # Lists libraries to link with:
# # example: -lm -lpthread
# LDLIBS :=

# NAME := philo
# NAME_BONUS := philo_bonus

# OBJECTS_DIR := .objects

# RM := rm -f

# SOURCES_MANDATORY := main.c

# SOURCES_BONUS :=

# OBJECTS_MANDATORY := $(patsubst %.c,\
# 	$(OBJECTS_DIR)/%.o,\
# 	$(addprefix philo/, $(SOURCES_MANDATORY))\
# )
# OBJECTS_BONUS := $(patsubst %.c,\
# 	$(OBJECTS_DIR)/%.o,\
# 	$(SOURCES_BONUS)\
# )

# DEPS_MANDATORY := $(OBJECTS_MANDATORY:.o=.d)
# DEPS_BONUS := $(OBJECTS_BONUS:.o=.d)

# -include $(DEPS_MANDATORY) $(DEPS_BONUS)

# $(OBJECTS_DIR): mkdir -p $@/$(NAME)

# $(OBJECTS_DIR)/%.o: %.c | $(OBJECTS_DIR)
# 	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@ $(LDLIBS)

# $(NAME): $(OBJECTS_MANDATORY)

# $(NAME_BONUS): $(OBJECTS_BONUS)

# all: $(NAME)

# bonus: $(NAME_BONUS)

# clean:
# 	$(RM) $(OBJECTS_MANDATORY) $(OBJECTS_BONUS)
# 	$(RM) $(DEPS_MANDATORY) $(DEPS_BONUS)
# 	$(RM) -r $(OBJECTS_DIR)

# fclean: clean
# # 	$(RM) -v $(NAME)
# # 	$(RM) -v $(NAME_BONUS)

# re: fclean all

# info:
# 	echo -e "Mandatory objects: $(OBJECTS_MANDATORY)"
# 	echo -e "Bonus objects: $(OBJECTS_BONUS)"
# 	echo -e "Mandatory dependencies: $(DEPS_MANDATORY)"
# 	echo -e "Bonus dependencies: $(DEPS_BONUS)"
#  	echo -e "CFLAGS: $(CFLAGS)"
# 	echo -e "CPPFLAGS: $(CPPFLAGS)"

# norm:
# 	norminette -R .

# .SECONDARY: $(OBJECTS_MANDATORY) $(OBJECTS_BONUS)

# .PRECIOUS: $(OBJECTS_DIR)

# # .SILENT:

# # .PHONY: all clean fclean re bonus
