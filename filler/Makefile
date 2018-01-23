# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alecott <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/29 09:33:30 by alecott           #+#    #+#              #
#    Updated: 2018/01/23 13:25:22 by alecott          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB_NAME = libft.a

LIB_PATH = ./libft/

LIB = $(addprefix $(LIB_PATH), $(LIB_NAME))

NAME = alecott.filler

CFLAGS = -Wall -Werror -Wextra

INC = filler.h

SRCS_PATH = ./srcs/

ALL_SRCS = main.c ft_map.c ft_piece.c

SRCS = $(addprefix $(SRCS_PATH), $(ALL_SRCS))

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(INC)
	@$(MAKE) -C libft
	@gcc $(CFLAGS) $(OBJ) -L libft -lft -o $(NAME)

%.o:$(SRCS_PATH)%.c
	gcc -c $< -o $@ $(CFLAGS)

clean:
	@$(MAKE) -C libft $@
	@/bin/rm -f $(LIB_OBJ)

fclean: clean
	@$(MAKE) -C libft $@
	@/bin/rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
