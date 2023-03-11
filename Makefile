# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zel-bouz <zel-bouz@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/04 18:24:47 by zel-bouz          #+#    #+#              #
#    Updated: 2023/03/11 02:58:13 by zel-bouz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server
NAMEC = client

CC = cc -Wall -Wextra  -Werror
RM = rm -f
AR = ar rcs

INC = includes/client.h \
	includes/ft_printf.h \
	includes/server.h

FILES = print/ft_printf.c print/ft_putchar_fd.c print/ft_puthexa.c print/ft_perror.c \
	print/ft_putnbr_fd.c print/ft_putptr.c print/ft_putstr_fd.c print/ft_putunbr.c print/ft_atoi.c

C_FILES = srcs/client.c 
S_FILES = srcs/server.c

OBJ = $(FILES:.c=.o)
C_OBJ = $(C_FILES:.c=.o)
S_OBJ = $(S_FILES:.c=.o)

all : $(NAME) $(NAMEC)

$(NAME) : $(OBJ) $(S_OBJ)
	@$(CC) $^ -o $@
	@echo "$@ created"

$(NAMEC) : $(OBJ) $(C_OBJ)
	@$(CC) $^ -o $@
	@echo "$@ created"

%.o: %.c $(INC)
	@$(CC) -o $@ $(FLG) -c $< 

clean :
	@$(RM) $(OBJ) $(S_OBJ) $(C_OBJ)

fclean : clean
	@$(RM) $(NAME) $(NAMEC)

re : fclean all