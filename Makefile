# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/13 14:13:30 by crenaudi          #+#    #+#              #
#    Updated: 2019/01/21 17:10:15 by crenaudi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = cc
LIB = -L./libft/ -lft
LIBFT_FOLDER = libft
LIBFT = $(LIBFT_FOLDER)/libft.a
RM = rm -f
SRC = fdf.c		\
	  bresenham.c
OBJ = $(SRC:.c=.o)

.PHONY: all fclean re

all: $(NAME)

$(LIBFT):
	make -sC $(LIBFT_FOLDER)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) -o $(NAME) $(LIB) $(OBJ)
	@echo ".........."
	@echo "| all ok |"
	@echo ".........."

clean:
	@$(RM) $(OBJ)
	make -sC $(LIBFT_FOLDER) clean
	@echo "............."
	@echo "| clean  ok |"
	@echo "............."

fclean: clean
	@$(RM) $(NAME)
	make -sC $(LIBFT_FOLDER) fclean
	@echo "............."
	@echo "| fclean ok |"
	@echo "............."

re: fclean all











