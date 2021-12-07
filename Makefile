SRC = ft_printf.c ft_putchar.c ft_putnbr.c ft_putstr.c\
	  ft_putusd.c ft_puthexa.c

OBJ = $(SRC:.c=.o)

NAME = libftprintf.a

CFLAGS = -Werror -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	ar cr $(NAME) $(OBJ)

$(NAME)(%.o): %.o
	ar rcs $(NAME) $<
	
%.o: %.c ft_printf.h
	gcc $(CFLAGS) $< -c

clean:
	rm -f $(OBJ)


fclean: clean
	rm -f $(NAME)

re: fclean all
