# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/12 13:01:11 by gasouza           #+#    #+#              #
#    Updated: 2023/10/25 20:59:07 by rmiranda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= cub3D
RUN_MAP 	= map/big_maze.cub

SRC_DIR 	= src
MAIN_SRC	= $(SRC_DIR)/main.c
MAIN_OBJ	= $(MAIN_SRC:%.c=%.o)

SRC			+= $(SRC_DIR)/engine/display_direction.c
SRC			+= $(SRC_DIR)/engine/game_destroy.c
SRC			+= $(SRC_DIR)/engine/game_loop.c
SRC			+= $(SRC_DIR)/engine/game_setup.c
SRC			+= $(SRC_DIR)/engine/game_textures.c
SRC			+= $(SRC_DIR)/engine/key_press_listener.c
SRC			+= $(SRC_DIR)/engine/minimap.c
SRC			+= $(SRC_DIR)/engine/mouse_drag_listener.c
SRC			+= $(SRC_DIR)/engine/mouse_listener.c
SRC			+= $(SRC_DIR)/engine/player_movement.c
SRC			+= $(SRC_DIR)/engine/player_rotation.c
SRC			+= $(SRC_DIR)/engine/raycasting.c
SRC			+= $(SRC_DIR)/engine/raycasting_calculations.c
SRC			+= $(SRC_DIR)/engine/raycasting_dda.c
SRC			+= $(SRC_DIR)/engine/raycasting_draw.c
SRC			+= $(SRC_DIR)/engine/render_the_screen.c
SRC			+= $(SRC_DIR)/helpers/config_helper.c
SRC			+= $(SRC_DIR)/helpers/direction_helper.c
SRC			+= $(SRC_DIR)/helpers/fov_helper.c
SRC			+= $(SRC_DIR)/helpers/image_helper.c
SRC			+= $(SRC_DIR)/helpers/map_helper.c
SRC			+= $(SRC_DIR)/helpers/positon_helper.c
SRC			+= $(SRC_DIR)/parse/color_syntax_check.c
SRC			+= $(SRC_DIR)/parse/normalize_map.c
SRC			+= $(SRC_DIR)/parse/parse.c
SRC			+= $(SRC_DIR)/parse/parse_helper.c
SRC			+= $(SRC_DIR)/parse/parse_validation.c

OBJS 		= $(SRC:%.c=%.o)

INCLUDE_DIR	= include
INCLUDE 	+= $(INCLUDE_DIR)/cub3d.h
INCLUDE 	+= $(INCLUDE_DIR)/define.h
INCLUDE 	+= $(INCLUDE_DIR)/engine.h
INCLUDE 	+= $(INCLUDE_DIR)/helpers.h
INCLUDE 	+= $(INCLUDE_DIR)/parse.h

LIBS_DIR 	= libs

LIBFT_DIR 	= $(LIBS_DIR)/libft
LIBFT_ARCH 	= $(LIBFT_DIR)/libft.a

GNL_DIR 	= $(LIBS_DIR)/gnl
GNL_ARCH 	= $(GNL_DIR)/libgnl.a

LFLAGS 		= -L$(LIBFT_DIR) -lft -L$(GNL_DIR) -lgnl -lmlx -lXext -lX11 -lm
HFLAGS		= -I$(INCLUDE_DIR) -I$(LIBFT_DIR) -I$(GNL_DIR)
CFLAGS		= -Wall -Wextra -Werror -g

CC			= cc
RM 			= rm -rf

VALGRIND	= valgrind --leak-check=full --show-leak-kinds=all

CRITERION_DIR = $(LIBS_DIR)/criterion

TESTS_NAME  = tests.run
TESTS_DIR	= test
TESTS_SRC	= $(wildcard $(TESTS_DIR)/*.c)
TESTS_OBJS	= $(TESTS_SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS) $(MAIN_OBJ) | $(LIBFT_ARCH) $(GNL_ARCH)
	@echo builded: objects
	@$(CC) $(CFLAGS) $(OBJS) $(MAIN_OBJ) -o $@ $(LFLAGS) && echo builded: project
	
%.o: %.c $(INCLUDE)
	@$(CC) $(CFLAGS) $(HFLAGS) -c $< -o $@ 

$(LIBFT_ARCH):
	@make -C $(LIBFT_DIR) --quiet && echo builded: libft

$(GNL_ARCH):
	@make -C $(GNL_DIR) --quiet && echo builded: gnl

run: $(NAME)
	@./$(NAME) $(RUN_MAP)

valgrind: $(NAME)
	$(VALGRIND) ./$(NAME) $(RUN_MAP)

$(TESTS_DIR)/%.o: $(TESTS_DIR)/%.c
	@$(CC) $(CFLAGS) $(HFLAGS) -I$(CRITERION_DIR) -c $< -o $@ 

test: $(OBJS) $(TESTS_OBJS) | $(LIBFT_ARCH) $(GNL_ARCH) 
	@$(CC) $(OBJS) $(TESTS_OBJS) $(LFLAGS) -L$(CRITERION_DIR) -lcriterion -o $(TESTS_NAME)
	@./$(TESTS_NAME)
	@echo
	@$(RM) $(TESTS_NAME)

clean:
	@make -C $(LIBFT_DIR) clean --quiet && echo cleaned: libft 
	@make -C $(GNL_DIR) clean --quiet && echo cleaned: gnl
	@$(RM) $(OBJS) $(MAIN_OBJ) && echo cleaned: objects

tclean: clean
	@$(RM) $(TESTS_OBJS) && echo test cleaned: objects
	
fclean: clean
	@$(RM) $(NAME)
	@make -C $(LIBFT_DIR) fclean --quiet 
	@make -C $(GNL_DIR) fclean --quiet 

re: fclean all

.PHONY: all clean fclean re run valgrind test
