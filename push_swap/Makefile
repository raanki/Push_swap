# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ranki <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/16 16:58:29 by ranki             #+#    #+#              #
#    Updated: 2023/03/16 16:58:30 by ranki            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC =  ft_checksorted.c ft_lstadd_front.c ft_simply.c ft_utils.c push_swap.c \
 ft_chunk.c ft_lstclear.c ft_push.c ft_sort_3.c main.c \
 ft_init_check.c ft_lstlast.c ft_putnumber.c ft_sort_5.c \
 ft_insertion_sort.c ft_lstnew.c ft_rotate.c ft_strcmp.c\
 ft_lstadd_back.c ft_lstsize.c ft_rrotate.c ft_swap.c \
 ft_printf/ft_flags.c ft_printf/ft_printf.c ft_printf/ft_putnbr_fd.c\
 ft_printf/ft_putstr.c ft_printf/ft_sizechar.c \
 ft_printf/ft_sizehexa.c ft_printf/ft_sizeint.c ft_printf/ft_sizep.c ft_printf/ft_sizestr.c \
 ft_printf/ft_size_unsignedint.c ft_printf/ft_sizeptr.c ft_utils2.c\


OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	gcc  -Wall -Werror -Wextra -no-pie $(FLAG) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY : all clean fclean re
