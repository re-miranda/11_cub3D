NAME = cub3d
SRC = main.c
OBJ = main.o
LIB = libft.a
PATH_LIB = libft/
HEADER = cub3d.h
PATH_HEADER = header/
CC = gcc
C_FLAGS = -Wall -Werror -Wextra -g3
RM = rm -rf

%.o:	%.c $(LIB) $(HEADER)
	$(CC) $(C_FLAGS) -c $< -o $@ $(PATH_LIB:%=-I%) $(PATH_HEADER:%=-I%)

$(NAME): $(OBJ)
	$(CC) $(C_FLAGS) -o $(NAME) $(OBJ)

all:	$(NAME)

clean:
	$(RM) $(NAME)

fclean:	clean
	$(RM) $(OBJ)

re:	fclean all

.PHONY:	all clean fclean re test_minilibx