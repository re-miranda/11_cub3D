NAME = cub3d
# SRC = $(wildcard $(SRC_DIR)/*.c) $(wildcard $(SRC_DIR)/parse/*.c) 
SRC = $(wildcard $(SRC_DIR)/*.c) $(wildcard $(SRC_DIR)/engine/*.c) $(wildcard $(SRC_DIR)/helpers/*.c) $(wildcard $(SRC_DIR)/parse/*.c)
SRC_DIR = src
OBJ = $(SRC:%.c=%.o)
INCLUDE = $(wildcard $(INCLUDE_DIR)/*.h)
INCLUDE_DIR = include libft
LIBFT_DIR = libft
LIBFT += $(LIBFT_DIR)/libft/libft.a
LIBFT += $(LIBFT_DIR)/libftplus.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf
VALGRING = valgrind --leak-check=full --show-leak-kinds=all
TEST_MAP = map/subjects_map.cub

all: $(NAME)

run: all
	./$(NAME) $(TEST_MAP)

valgrind: $(NAME)
	$(VALGRING) ./$(NAME) $(TEST_MAP)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) -L$(LIBFT_DIR) $(LIBFT:$(LIBFT_DIR)/lib%.a=-l%) -lmlx -lXext -lX11 -lm 

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
