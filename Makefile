# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alecott <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/29 09:33:30 by alecott           #+#    #+#              #
#    Updated: 2018/01/17 15:43:17 by alecott          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CFLAGS = -Wall -Werror -Wextra

LIB_PRE = srcs

LIB_SRC = ft_putchar.c ft_putnbr.c ft_putstr.c ft_newbloc.c ft_isspec.c \
		  ft_strlen.c ft_lstalloc.c ft_memalloc.c ft_bzero.c ft_memset.c \
		  ft_working.c ft_uitoa_base.c ft_strjoin.c ft_memdel.c ft_strequ.c \
		  ft_conv_int.c ft_conv_octal.c ft_conv_string.c ft_conv_char.c \
		  ft_strchr.c ft_strupper.c ft_putwchar.c ft_llitoa_base.c ft_width.c \
		  ft_atoi.c ft_putwstr.c ft_precision.c ft_printf.c ft_strdel.c \
		  ft_memdel.c ft_strdup.c ft_memalloc.c

SRCS = $(addprefix $(LIB_PRE)/, $(LIB_SRC))

LIB_OBJ = $(LIB_SRC:.c=.o)

INC = printf.h

all: $(NAME)

$(NAME): $(LIB_OBJ) $(INC)
	@ar rc $(NAME) $(LIB_OBJ)
	@ranlib $(NAME)

%.o:$(LIB_PRE)/%.c
	gcc -c $< -o $@ $(CFLAGS)

clean:
	@/bin/rm -f $(LIB_OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
