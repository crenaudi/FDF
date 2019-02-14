# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/13 14:13:30 by crenaudi          #+#    #+#              #
#    Updated: 2019/02/14 15:36:23 by crenaudi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = cc
LIB = -L./libft/ -lft
LIB_MATH = -lm
MINILIBX = -I /usr/local/include/mlx.h -L /usr/local/lib/ -lmlx
FRAMEWORK = -framework OpenGl -framework AppKit
LIBFT_FOLDER = libft
LIBFT = $(LIBFT_FOLDER)/libft.a
RM = rm -f
SRC = fdf.c				\
	  fdf_data.c		\
	  bresenham.c		\
		projection.c	\
	  event.c				\
	  affichage.c		\
	  fail.c
OBJ = $(SRC:.c=.o)

.PHONY: all fclean re

all: $(NAME)

$(LIBFT):
	make -sC $(LIBFT_FOLDER)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) -fsanitize=address -g3 $(MINILIBX) $(FRAMEWORK) -o $(NAME) $(LIB_MATH) $(LIB) $(OBJ)
	@echo "/// all fdf ok ///"

clean:
	@$(RM) $(OBJ)
	make -sC $(LIBFT_FOLDER) clean
	@echo "/// clean fdf ok ///"

fclean: clean
	@$(RM) $(NAME)
	make -sC $(LIBFT_FOLDER) fclean
	@echo "/// fclean fdf ok ///"

re: fclean all
