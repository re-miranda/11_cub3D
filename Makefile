# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/12 13:01:11 by gasouza           #+#    #+#              #
#    Updated: 2023/10/12 14:05:36 by gasouza          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= cub3d
RUN_MAP 	= map/surprising_map.cub

SRC_DIR 	= src
SRC 		+= $(wildcard $(SRC_DIR)/*.c)
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
GNL_ARCH 	= $(GNL_DIR)/gnl.a

LFLAGS 		= -L$(LIBFT_DIR) -lft -L$(GNL_DIR) -lgnl -lmlx -lXext -lX11 -lm
HFLAGS		= -I$(INCLUDE_DIR) -I$(LIBFT_DIR) -I$(GNL_DIR)
CFLAGS		= -Wall -Wextra -Werror -g

CC			= gcc
RM 			= rm -rf

VALGRIND	= valgrind --leak-check=full --show-leak-kinds=all

CRITERION_INCLUDE = -I/opt/homebrew/Cellar/criterion/2.4.1_3/include
CRITERION_LIB = -L/opt/homebrew/Cellar/criterion/2.4.1_3/lib/ -lcriterion
TEST_SRC	= test/normalize_map.c

all: $(NAME)

$(NAME): $(LIBFT_ARCH) $(GNL_ARCH) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $@ $(LFLAGS) && echo builded objects
	@printf "\n\nCOMPILED AND TESTED SUCCESSFULLY"
	@printf "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n"
	@echo "well done!"

%.o: %.c $(INCLUDE)
	@$(CC) $(CFLAGS) $(HFLAGS) -c $< -o $@ 

$(LIBFT_ARCH):
	make -C $(LIBFT_DIR) --quiet && echo builded libft

$(GNL_ARCH):
	make -C $(GNL_DIR) --quiet && echo builded gnl


run: all
	@./$(NAME) $(RUN_MAP)

valgrind: $(NAME)
	$(VALGRIND) ./$(NAME) $(RUN_MAP)

test: $(OBJS)
	$(CC) $(CRITERION_INCLUDE) -Iinclude -I$(LIBFT_DIR) $(TEST_SRC) /Users/rmiranda/42_rmiranda/11_cub3D/src/parse/parse_validation.o -L$(LIBFT_DIR) $(LIBFT:$(LIBFT_DIR)/lib%.a=-l%) $(CRITERION_LIB)
	./a.out
	$(RM) a.out

clean:
	@make -C $(LIBFT_DIR) clean --quiet 
	@echo libft cleaned
	@make -C $(GNL_DIR) clean --quiet && echo gnl cleaned
	@$(RM) $(OBJS) && echo objects cleaned
	
fclean: clean
	@$(RM) $(NAME)
	@make -C $(LIBFT_DIR) fclean --quiet 
	@make -C $(GNL_DIR) fclean --quiet 

re: fclean all

.PHONY: all clean fclean re run valgrind test
