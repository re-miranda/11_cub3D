# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/12 13:01:11 by gasouza           #+#    #+#              #
#    Updated: 2023/10/18 19:47:42 by gasouza          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= cub3d
RUN_MAP 	= map/big_maze.cub

SRC_DIR 	= src
MAIN_SRC	= $(SRC_DIR)/main.c
MAIN_OBJ	= $(MAIN_SRC:%.c=%.o)
SRC 		+= $(wildcard $(SRC_DIR)/engine/*.c)
SRC 		+= $(wildcard $(SRC_DIR)/helpers/*.c)
SRC 		+= $(wildcard $(SRC_DIR)/parse/*.c)

OBJS 		= $(SRC:%.c=%.o)

INCLUDE_DIR	= include
INCLUDE 	= $(wildcard $(INCLUDE_DIR)/*.h)

LIBS_DIR 	= libs

LIBFT_DIR 	= $(LIBS_DIR)/libft
LIBFT_ARCH 	= $(LIBFT_DIR)/libft.a

GNL_DIR 	= $(LIBS_DIR)/gnl
GNL_ARCH 	= $(GNL_DIR)/libgnl.a

MLX_DIR 	= $(LIBS_DIR)/minilibx
MLX_ARCH 	= $(MLX_DIR)/libmlx.a

LFLAGS 		= -L$(LIBFT_DIR) -lft -L$(GNL_DIR) -lgnl -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
HFLAGS		= -I$(INCLUDE_DIR) -I$(LIBFT_DIR) -I$(GNL_DIR) -I$(MLX_DIR) 
CFLAGS		= -Wall -Wextra -Werror -g

CC			= gcc
RM 			= rm -rf

VALGRIND	= valgrind --leak-check=full --show-leak-kinds=all

CRITERION_DIR = $(LIBS_DIR)/criterion

TESTS_NAME  = tests.run
TESTS_DIR	= test
TESTS_SRC	= $(wildcard $(TESTS_DIR)/*.c)
TESTS_OBJS	= $(TESTS_SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS) $(MAIN_OBJ) | $(LIBFT_ARCH) $(GNL_ARCH) $(MLX_ARCH)
	@echo builded: objects
	@$(CC) $(CFLAGS) $(OBJS) $(MAIN_OBJ) -o $@ $(LFLAGS) && echo builded: project
	
%.o: %.c $(INCLUDE)
	@$(CC) $(CFLAGS) $(HFLAGS) -c $< -o $@ 

$(LIBFT_ARCH):
	@make -C $(LIBFT_DIR) --quiet && echo builded: libft

$(GNL_ARCH):
	@make -C $(GNL_DIR) --quiet && echo builded: gnl

$(MLX_ARCH):
	@make -C $(MLX_DIR) --quiet && echo builded: mlx

run: all
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
	@make -C $(MLX_DIR) clean --quiet && echo cleaned: mlx
	@$(RM) $(OBJS) $(MAIN_OBJ) && echo cleaned: objects

tclean: clean
	@$(RM) $(TESTS_OBJS) && echo test cleaned: objects
	
fclean: clean
	@$(RM) $(NAME)
	@make -C $(LIBFT_DIR) fclean --quiet 
	@make -C $(GNL_DIR) fclean --quiet 
	@make -C $(MLX_DIR) fclean --quiet 

re: fclean all

.PHONY: all clean fclean re run valgrind test
