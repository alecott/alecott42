# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alecott <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/29 09:33:30 by alecott           #+#    #+#              #
#    Updated: 2018/01/18 18:13:54 by alecott          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB_NAME = libft.a

LIB_DIR = libft

LIB = $(addprefix $(LIB_DIR)/, $(LIB_NAME))

NAME = alecott.filler

CFLAGS = -Wall -Werror -Wextra

LIB_OBJ = $(LIB_SRC:.c=.o)

INC = filler.h

all: $(NAME)

$(NAME): $(LIB_OBJ) $(INC)
	@(cd libft && $(MAKE))
	@gcc $(CFLAGS) main.c $(LIB) -o $(NAME)

%.o:$(LIB_PRE)/%.c
	gcc -c $< -o $@ $(CFLAGS)

clean:
	@(cd $(LIB_DIR) && $(MAKE) $@)
	@/bin/rm -f $(LIB_OBJ)

fclean: clean
	@(cd $(LIB_DIR) && $(MAKE) $@)
	@/bin/rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
