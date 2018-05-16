# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alecott <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/29 09:33:30 by alecott           #+#    #+#              #
#    Updated: 2018/05/16 15:02:09 by alecott          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB_NAME = libft.a

LIB_PATH = ./libft/

LIB = $(addprefix $(LIB_PATH), $(LIB_NAME))

NAME = lem-in

CFLAGS = -Wall -Werror -Wextra -g

INC = lem_in.h

LIB_INC = $(addprefix $(LIB_PATH), libft.h)

SRCS_PATH = ./srcs/

ALL_LIB_SRCS = ft_atoi.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_memset.c \
		  ft_strcmp.c ft_strdup.c ft_strncat.c ft_strncpy.c ft_tolower.c \
		  ft_bzero.c ft_isalpha.c ft_isdigit.c ft_memcpy.c ft_strcat.c \
		  ft_strcpy.c ft_strlen.c ft_strncmp.c ft_strstr.c ft_toupper.c \
		  ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c ft_putchar_fd.c \
		  ft_putendl_fd.c ft_putstr_fd.c ft_putnbr.c ft_putnbr_fd.c ft_strclr.c \
		  ft_strdel.c ft_strnew.c ft_strsub.c ft_strjoin.c ft_strsplit.c \
		  ft_strtrim.c ft_strequ.c ft_strnequ.c ft_striter.c \
		  ft_striteri.c ft_strmap.c ft_strmapi.c ft_memalloc.c ft_memdel.c \
		  ft_strchr.c ft_strrchr.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
		  ft_memmove.c ft_strlcat.c ft_memccpy.c ft_strrev.c ft_lstdel.c \
		  ft_lstadd.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c \
		  ft_count_words.c ft_strrev.c ft_isupper.c ft_itoa.c \
		  get_next_line.c ft_strsubinv.c ft_tablen.c ft_realloc.c ft_tabjoin.c \
		  ft_tabchr.c ft_tabstr.c ft_puttab.c ft_tabdup.c ft_strndup.c ft_strnmdup.c ft_copy_tab.c \

LIB_SRCS = $(addprefix $(LIB_PATH), $(ALL_LIB_SRCS))

LIB_OBJ = $(LIB_SRCS:.c=.o)

ALL_SRCS = main.c ft_stock.c ft_names.c ft_error.c ft_verify.c \
		   ft_tubestr.c ft_room_number.c ft_fill_path.c \
		   ft_move_tubes.c ft_feel_free.c ft_rm_last_one.c \
		   ft_sort_tubes_and_repeat.c ft_get_room.c ft_find_room_intube.c \
		   ft_get_last_inpath.c ft_complete_path.c ft_check_ifexist.c \
		   ft_add_and_delete.c ft_check_path.c ft_find_nbroom.c \
		   ft_remove_ifrepeat.c ft_choose_nbofrm.c ft_find_nb_tubes.c \
		   ft_tubes_names.c ft_nbrooms_in_path.c ft_sort_paths.c ft_sub_path.c \
		   ft_algo.c ft_opti_allpaths.c ft_free_all.c ft_take_room.c ft_ultim_path.c \
		   ft_nextoffind.c ft_free_tab.c ft_nb_element.c \

SRCS = $(addprefix $(SRCS_PATH), $(ALL_SRCS))

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(INC) $(LIB_OBJ) $(LIB_INC)
	@$(MAKE) -C libft
	@gcc $(CFLAGS) $(OBJ) -L libft -lft -o $(NAME)

%.o:$(SRCS_PATH)%.c
	gcc -c $< -o $@ $(CFLAGS)

clean:
	@$(MAKE) -C libft $@
	@/bin/rm -f $(OBJ)

fclean: clean
	@$(MAKE) -C libft $@
	@/bin/rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
