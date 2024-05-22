# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgaratej <cgaratej@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/14 12:47:35 by cgaratej          #+#    #+#              #
#    Updated: 2024/05/22 16:57:11 by cgaratej         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = libft/libft.a
GET_NEX_LINE= libft/get_next_line/libftget_next_line.a
LIBFT_MAKE = make --no-print-directory -C libft

NAME = pipex
NAME_BONUS = pipex_bonus
CFLAGS = -Wall -Werror -Wextra
INCLUDE = Makefile includes/*
CC = gcc -g 
RM = rm -f

GREEN=\033[0;32m
LGREEN=\033[1;92m
ORANGE=\033[33m
RED = \033[1;91m
NONE=\033[0m

SRC= src/main.c src/utils.c

SRC_BONUS= src_bonus/main_bonus.c src_bonus/utils_bonus.c

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME): libft $(OBJ) $(INCLUDE)
	@$(CC) $(CFLAGS) $(LIBFT) $(GET_NEX_LINE) $(OBJ) -o $(NAME)
	@echo "\n$(LGREEN)Create $(NAME) ✔\n$(NONE)"

bonus: libft $(INCLUDE) $(OBJ_BONUS)
	@$(CC) $(CFLAGS) $(LIBFT) $(GET_NEX_LINE) $(OBJ_BONUS) -o $(NAME_BONUS)
	@echo "\n$(LGREEN)Create $(NAME_BONUS) ✔\n$(NONE)"

%.o: %.c $(INCLUDE)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(LGREEN)File $< compiled ✔$(NONE)"

libft:
	@echo "$(ORANGE)\nCompilando libft$(NONE)"
	@$(LIBFT_MAKE)

clean:
	@$(RM) $(OBJ) $(OBJ_BONUS)
	@$(LIBFT_MAKE) clean
	@echo "$(RED)Deleted .o files$(NONE)"
	
fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(NAME_BONUS)
	@$(LIBFT_MAKE) fclean
	@echo "$(RED)$(NAME) Deleted$(NONE)"

re: fclean all

.PHONY: all clean fclean re libft