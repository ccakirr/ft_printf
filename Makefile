NAME = libftprintf.a

SOURCES = ft_printf.c\
ft_putchar_fd.c\
ft_putendl_fd.c\
ft_putnbr_fd.c\
ft_putstr_fd.c

OBJ = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME) $(OBJ)

re: fclean all

o: re
	@cc main.c libftprintf.a -o output
	@./output | cat -e
	@rm -rf output
	@rm -rf $(NAME) $(OBJ)
