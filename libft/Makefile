NAME = libftplus.a

# LIBS PATH
LIBFT_PATH = libft
GNL_PATH = gnl
PRINTF_PATH = printf

# LIBS
LIBFT = $(LIBFT_PATH)/libft.a
GNL = $(GNL_PATH)/libftgnl.a
PRINTF = $(PRINTF_PATH)/libftprintf.a

# OTHERS
RM = rm -rf

all: $(NAME)

$(NAME): $(LIBFT) $(GNL) $(PRINTF)
	cp $(PRINTF) $(NAME)

$(LIBFT):
	make all -C $(LIBFT_PATH)
	$(RM) $(NAME)
	cp $(LIBFT) $(NAME)

$(GNL):
	make all -C $(GNL_PATH)
	$(RM) $(NAME)
	cp $(GNL) $(NAME)

$(PRINTF):
	make all -C $(PRINTF_PATH)
	$(RM) $(NAME)

clean:
	make clean -C $(PRINTF_PATH)
	make clean -C $(GNL_PATH)
	make clean -C $(LIBFT_PATH)

fclean: clean
	make fclean -C $(PRINTF_PATH)
	make fclean -C $(GNL_PATH)
	make fclean -C $(LIBFT_PATH)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re