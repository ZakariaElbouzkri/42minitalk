
NAME = libft.a

CC = cc -Wall -Wextra -Werror

AR = ar rc

CYAN = \033[0;36m
BLUE = \033[0;34m
PURPLE = \033[0;35m
YELLOW = \033[0;33m
GREEN = \033[0;32m
RED = \033[0;31m

FILES =	libft/ft_atoi.c libft/ft_atoi_long.c  libft/ft_bzero.c  libft/ft_calloc.c  libft/ft_isalnum.c  libft/ft_isalpha.c  libft/ft_isascii.c  libft/ft_isdigit.c  libft/ft_isprint.c  libft/ft_itoa.c  libft/ft_memchr.c  libft/ft_memcmp.c \
	libft/ft_memcpy.c libft/ft_memmove.c libft/ft_memset.c libft/ft_printf.c libft/ft_putchar.c libft/ft_putchar_fd.c libft/ft_putendl_fd.c libft/ft_puterror.c libft/ft_puthexa.c libft/ft_putnbr.c libft/ft_putnbr_fd.c libft/ft_putptr.c libft/ft_putstr.c \
	libft/ft_putstr_fd.c libft/ft_putunbr.c libft/ft_split.c libft/ft_strchr.c libft/ft_strchr_std.c libft/ft_strcmp.c libft/ft_strcpy.c libft/ft_strdup.c libft/ft_striteri.c libft/ft_strjoin.c libft/ft_strjoin_std.c libft/ft_strlcat.c libft/ft_strlcpy.c \
	libft/ft_strlen.c libft/ft_strmapi.c libft/ft_strncmp.c libft/ft_strndup.c libft/ft_strnstr.c libft/ft_strrchr.c libft/ft_strtrim.c libft/ft_substr.c \
	libft/ft_swap.c  libft/ft_tolower.c  libft/ft_toupper.c  libft/get_next_line.c libft/ft_perror.c

OBJECT = $(FILES:.c=.o)

all: $(NAME)

%.o: %.c ../includes/libft.h
	@echo "${CYAN}compiling${GREEN} ${@}" 
	@$(CC) -o $@ -c  $<

$(NAME): $(OBJECT)
	@$(AR) $@ $^
	@echo "${BLUE}libft.a${GREEN} has been created"

clean:
	@echo "${RED}Archive file removed"
	@rm -f $(OBJECT)

fclean: clean
	@echo "${RED}libft.a has been removed"
	@rm -rf $(NAME)

re: fclean all

.PHONY : clean fclean all re