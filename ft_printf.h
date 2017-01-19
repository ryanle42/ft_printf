#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include <stdio.h>
# include <stdint.h>

typedef struct aflags{
	int plus;
	int minus;
	int zero;
	int hash;
	int space;
}flag;

typedef struct aflag_len{
    flag *flags;
    int size;
    int width;
    int precision;
}param;

int get_flag(int fmt, flag *flags);
param *reset_params();
void    remove_conflict_flags(param *params);
int is_conversion(char fmt);
intmax_t convert_signed(param *params, intmax_t n);
intmax_t convert_unsigned(param *params, intmax_t n);
int 	get_size(const char *fmt);
void 	write_int(param *params, va_list args);
void 	write_unsigned_int(param *params, va_list args);
void	write_char(param *params, va_list args);
void	write_octal(param *params, va_list args);
void 	write_hex(param *params, va_list args, int letters);
void    write_spaces(param *params, int n, int j);

#endif