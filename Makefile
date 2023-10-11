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
TEST_MAP = map/gabriels_map.cub
CRITERION_INCLUDE = -I/opt/homebrew/Cellar/criterion/2.4.1_3/include
CRITERION_LIB = -L/opt/homebrew/Cellar/criterion/2.4.1_3/lib/ -lcriterion
TEST_SRC = test/normalize_map.c

all: $(NAME) test
	@echo "\n\nCOMPILED AND TESTED SUCCESSFULLY"
	@echo "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n"
	@echo "well done!"

run: all
	./$(NAME) $(TEST_MAP)

valgrind: $(NAME)
	$(VALGRING) ./$(NAME) $(TEST_MAP)

test: $(OBJ)
	$(CC) $(CRITERION_INCLUDE) -Iinclude -I$(LIBFT_DIR) $(TEST_SRC) /Users/rmiranda/42_rmiranda/11_cub3D/src/parse/parse_validation.o -L$(LIBFT_DIR) $(LIBFT:$(LIBFT_DIR)/lib%.a=-l%) $(CRITERION_LIB)
	./a.out
	$(RM) a.out

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) -L$(LIBFT_DIR) $(LIBFT:$(LIBFT_DIR)/lib%.a=-l%) -L/opt/homebrew/Cellar/libxext/1.3.5/lib/ -lmlx -lXext -L/opt/homebrew/Cellar/libx11/1.8.6/lib/ -lX11 -lm

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

.PHONY: all clean fclean re run valgrind test
