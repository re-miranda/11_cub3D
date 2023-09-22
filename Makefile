NAME = cub3d
# SRC = $(wildcard $(SRC_DIR)/*.c) $(wildcard $(SRC_DIR)/parse/*.c) 
SRC = $(wildcard $(SRC_DIR)/*.c) $(wildcard $(SRC_DIR)/engine/*.c) $(wildcard $(SRC_DIR)/helpers/*.c)
SRC_DIR = src
OBJ = $(SRC:%.c=%.o)
INCLUDE = $(wildcard $(INCLUDE_DIR)/*.h)
INCLUDE_DIR = include libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_DIR = libft
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all: $(NAME)

run: all
	./$(NAME)

valgrind: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) -L$(LIBFT_DIR) -lmlx -lXext -lX11 -lm

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE_DIR:%=-I%)

clean:
	$(RM) $(OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re run valgrind