NAME = suite

SRCS = test.c ../libft/libft.a

HEADERS = ../libft/includes

all: 
	gcc -o $(NAME) $(SRCS) -I $(HEADERS) -I ../includes

clean: 
	rm $(NAME)

re: clean all

tests:
	cd ../ && make re
	.././printf > file
	./suite
