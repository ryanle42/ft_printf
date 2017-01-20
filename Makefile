NAME = printf

SRCS = ft_printf.c get_flags.c write_int.c write_unsigned_int.c write_char.c write_string.c write_spaces.c write_octal.c size_converters.c write_hex.c write_ptr.c

HEADERS = . libft/includes

CC = gcc -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	gcc -o $(NAME) $(SRCS) ./libft/libft.a -I . -I ./libft/includes

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all

bin: re
	make clean
