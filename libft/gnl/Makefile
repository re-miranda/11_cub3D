NAME = libftgnl.a

# LIBS
LIBFT = ../libftplus.a
HEADER_PATH = ./

# OTHERS
CC = cc
AR = ar -rcs
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror -fPIE

# FILES
SRC += ft_get_next_line.c
SRC += ft_get_next_line_utils.c
OBJ = $(SRC:%.c=%.o)

all: $(NAME)

%.o:	%.c
	$(CC) $(CFLAGS) -c -I$(HEADER_PATH) $< -o $(<:%.c=%.o)

$(NAME): $(OBJ)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
