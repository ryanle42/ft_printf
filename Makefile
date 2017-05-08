NAME = libftprintf.a

OBJS = $(addsuffix .o,ft_printf flags params size_converters write_hex hex_helpers \
		write_int int_helpers write_octal octal_helpers write_unsigned_int \
		unsigned_helpers write_ptr write_char write_string)

CC = gcc

CFLAGS = -Wall -Werror -Wextra

INCLUDES = -I ./includes -I ./libft/includes

LIB = libft/libft.a

all: $(NAME)

$(NAME): $(LIB) $(OBJS)
	cp $(LIB) $(NAME)
	ar rc $(NAME) $(OBJS) $(LIB)

%.o: srcs/%.c
	$(CC) -c $< $(CFLAGS) $(INCLUDES)

$(LIB):
	$(MAKE) -C libft

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
