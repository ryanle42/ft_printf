# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rle <rle@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/07 22:01:59 by rle               #+#    #+#              #
#    Updated: 2017/05/07 22:06:33 by rle              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

OBJS = $(addprefix ./srcs/, \
	   		$(addsuffix .o, \
				ft_printf \
				flags \
				params \
				size_converters \
				write_hex \
				hex_helpers \
				write_int \
				int_helpers \
				write_octal \
				octal_helpers \
				write_unsigned_int \
				unsigned_helpers \
				write_ptr \
				write_char \
				write_string \
			) \
		)

CC = @gcc

CFLAGS = -Wall -Werror -Wextra

INCLUDES = -I ./includes -I ./libft/includes

LIB = libft

all: $(NAME)

$(NAME): $(LIB) $(OBJS)
	@ar rc $(NAME) $(OBJS) $(LIB)/libft.a
	@echo "\x1B[31mlibftprintf.a made"

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

$(LIB): force
	@make -C libft

clean:
	@rm -rf $(OBJS)
	@make clean -C $(LIB)
	@echo "\x1B[34mCleaned"

fclean: clean
	@rm -f $(NAME)

re: fclean all

force: 
	@true
