# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zel-bouz <zel-bouz@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/04 18:24:47 by zel-bouz          #+#    #+#              #
#    Updated: 2023/03/11 02:38:41 by zel-bouz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server
NAMEC = client
CC = cc -Wall -Wextra  -Werror
RM = rm -f
AR = ar rcs

FILES = print/ft_printf.c print/ft_putchar_fd.c print/ft_puthexa.c \
	print/ft_putnbr_fd.c print/ft_putptr.c print/ft_putstr_fd.c print/ft_putunbr.c

OBJ = $(FILES:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(AR) $@ $^

%.o: %.c ft_printf.h
	$(CC) -o $@ $(FLG) -c $< 

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all