#include "ft_printf.h"

void conv_hex(int n, int rev)
{
	char *base;

	base = "0123456789abcdef";
	if (rev > 1)
		conv_hex(n / 16, rev - 1);
	write(1, base + (n % 16), 1);
}
void print_hex(const unsigned char *addr, size_t size, size_t i)
{
	int n;

	n = 0;
	while (n < 16 && i < size)
	{
		conv_hex(addr[i], 2);
		if (n % 2)
			write(1, " ", 1);
		n++;
		i++;
	}
	while (n < 16)
	{
		write(1, "  ", 2);
		if (n % 2)
			write(1, " ", 1);
		n++;
	}
}

void print_letters(const unsigned char *addr, size_t size, size_t i)
{
	int n;

	n = 0;
	while (n < 16 && i < size)
	{
		if (addr[i] >= ' ' && addr[i] <= '~')
			write(1, &addr[i], 1);
		else
			write(1, ".", 1);
		n++;
		i++;
	}
}

void print_memory(const void *addr, size_t size)
{
	size_t i;

	i = 0;
	while (i < size)
	{
		print_hex(((const unsigned char*)addr), size, i);
		print_letters((const unsigned char*)addr, size, i);
		write(1, "\n", 1);
		i += 16;
	}
}