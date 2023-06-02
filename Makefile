# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchaaibi <mchaaibi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/20 18:51:08 by mchaaibi          #+#    #+#              #
#    Updated: 2023/06/02 19:59:33 by mchaaibi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SOURCES =  function.c\
		functio.c \
		ft_printf.c 

OBJECTS = $(SOURCES:.c=.o)

all : $(NAME)

$(NAME) : $(OBJECTS) 
		@ ar rcs $(NAME) $(OBJECTS)

%.o: %.c ft_printf.h
	${CC} $(CFLAGS) -c $< -o $@ 

clean : 
		 rm -rf $(OBJECTS)

fclean : clean
		 rm -rf $(NAME)

re : fclean all