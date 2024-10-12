# lib/FT_PRINTF/Makefile
NAME = libprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = src/ft_printf.c src/ft_putnbrd_base.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
