# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/24 08:25:35 by gasouza           #+#    #+#              #
#    Updated: 2023/10/12 12:52:16 by gasouza          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libgnl.a

SRCS_D		=	src
INCS_D		=	inc

SRCS_F		=	get_next_line.c get_next_line_utils.c
SRCS		=	$(addprefix $(SRCS_D)/, $(SRCS_F))

OBJS		=	$(SRCS:.c=.o)

CFLAGS		=	-Wall -Werror -Wextra
COMPILER	=	gcc $(CFLAGS) -I $(INCS_D) -c
ARCHIVE		=	ar -rc
CLEANUP		=	rm -f

.PHONY: 		all
all: 			$(NAME)

$(NAME): 		$(OBJS)
				$(ARCHIVE) $@ $^

%.o: 			%.c
				$(COMPILER) $< -o $@

.PHONY: 		clean
clean:
				$(CLEANUP) $(OBJS)

.PHONY: 		fclean
fclean: 		clean
				$(CLEANUP) $(NAME)

.PHONY: 		re
re: 			fclean all
