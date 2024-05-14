# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgaratej <cgaratej@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/14 12:47:35 by cgaratej          #+#    #+#              #
#    Updated: 2024/05/14 12:59:04 by cgaratej         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

IBFT = utils/libft/libft.a
GET_NEX_LINE= utils/libft/get_next_line/libftget_next_line.a
PRINTF= utils/libft/ft_printf/libftprintf.a
LIBFT_MAKE = make --no-print-directory -C utils/libft

NAME = pipex
CFLAGS = -Wall -Werror -Wextra
INCLUDE = Makefile includes/*
CC = gcc
RM = rm -f

GREEN=\033[0;32m
LGREEN=\033[1;92m
ORANGE=\033[33m
RED = \033[1;91m
NONE=\033[0m

SRC=

SRC_BONUS= 

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME): libft $(OBJ) $(INCLUDE)
	@$(CC) $(CFLAGS) $(LIBFT) $(GET_NEX_LINE) $(PRINTF) $(OBJ) -o $(NAME)
	@echo "\n$(LGREEN)Create $(NAME) ✔\n$(NONE)"

bonus: libft minilib $(INCLUDE) $(OBJ_BONUS)
	@$(CC) $(CFLAGS) $(LIBFT) $(GET_NEX_LINE) $(PRINTF) $(OBJ_BONUS) -o $(NAME)
	@echo "\n$(LGREEN)Create $(NAME) bonus ✔\n$(NONE)"

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
	@$(LIBFT_MAKE) fclean
	@echo "$(RED)$(NAME) Deleted$(NONE)"

re: fclean all

.PHONY: all clean fclean re libft bonus