# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgaratej <cgaratej@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/14 12:47:35 by cgaratej          #+#    #+#              #
#    Updated: 2024/06/03 21:15:40 by cgaratej         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = libft/libft.a
GET_NEX_LINE= libft/get_next_line/libftget_next_line.a
LIBFT_MAKE = make --no-print-directory -C libft

NAME = pipex
NAME_BONUS = pipex_bonus
CFLAGS = -Wall -Werror -Wextra
CC = gcc -g 
RM = rm -f

GREEN=\033[0;32m
LGREEN=\033[1;92m
ORANGE=\033[33m
RED = \033[1;91m
NONE=\033[0m

SRC= src/main.c src/utils.c
DPES= src/main.c src/utils.c 

SRC_BONUS= src_bonus/main_bonus.c src_bonus/utils_bonus.c
DPES_BONUS= src_bonus/main_bonus.c src_bonus/utils_bonus.c

OBJ = $(SRC:.c=.o)
DEPS = $(SRC:.c=.d)

OBJ_BONUS = $(SRC_BONUS:.c=.o)
DEPS_BONUS = $(SRC_BONUS:.c=.d)

all: $(NAME)

$(NAME): libft $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(GET_NEX_LINE) -o $(NAME)
	@echo "\n$(LGREEN)Create $(NAME) ✔\n$(NONE)"

bonus: libft $(OBJ_BONUS) 
	@$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT) $(GET_NEX_LINE) -o $(NAME_BONUS)
	@echo "\n$(LGREEN)Create $(NAME_BONUS) ✔\n$(NONE)"

%.o: %.c Makefile
	@$(CC) $(CFLAGS) -c $< -MMD -o $@
	@echo "$(LGREEN)File $< compiled ✔$(NONE)"

libft:
	@echo "$(ORANGE)\nCompilando libft$(NONE)"
	@$(LIBFT_MAKE)

clean:
	@$(RM) $(OBJ) $(OBJ_BONUS) $(DEPS) $(DEPS_BONUS)
	@$(LIBFT_MAKE) clean
	@echo "$(RED)Deleted .o files$(NONE)"
	@echo "$(RED)Deleted .d files$(NONE)"
	
fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(NAME_BONUS)
	@$(LIBFT_MAKE) fclean
	@echo "$(RED)$(NAME) Deleted$(NONE)"

re: fclean all

-include $(DEPS) $(DEPS_BONUS)

.PHONY: all clean fclean re libft