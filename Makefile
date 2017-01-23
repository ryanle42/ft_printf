NAME = printf

SRCS = ./srcs/print_memory.c ./srcs/ft_printf.c ./srcs/get_flags.c ./srcs/write_int.c ./srcs/write_unsigned_int.c ./srcs/write_char.c \
	./srcs/write_string.c ./srcs/write_spaces.c ./srcs/write_octal.c ./srcs/size_converters.c ./srcs/write_hex.c ./srcs/write_ptr.c main.c

HEADERS = libft/includes

CC = gcc -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	gcc -o $(NAME) $(SRCS) ./libft/libft.a -I ./includes -I $(HEADERS)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all

bin: re
	make clean
