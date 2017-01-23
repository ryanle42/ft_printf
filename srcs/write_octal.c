#include "ft_printf.h"

intmax_t convert_octal(intmax_t n)
{
	char *base;
	intmax_t i;

	base = "01234567";
	i = 0;
	while (n > 0)
	{
		i *= 10;
		i += *(base + (n % 8)) - '0';
		n /= 8;
	}
	return (i);
}
void    put_octal_str(param *params, char *str)
{
    if (params->flags->hash)
        write(1, "0", 1);
    ft_putstr(str);
}

int     get_octal_length(param *params, char *str)
{
    int length;

    length = ft_strlen(str);
    if (params->flags->hash)
        length++;
    return (length);
}
void	write_octal(param *params, va_list args)
{
	char *tmp;
	int length;
    intmax_t n;

    remove_conflict_flags(params);
    n = va_arg(args, intmax_t);
    n = convert_unsigned(params, n);
    n = convert_octal(n);
    if (params->flags->zero)
        params->precision = params->width;
    tmp = ft_itoa(n, params->precision, params->flags->zero, 0);
    length = get_octal_length(params, tmp);
    if (!params->flags->minus && !params->flags->zero)
    	write_spaces(params, params->width - length, params->precision - length);
    if (!(n == 0 && params->precision == 0))
    	put_octal_str(params, tmp);
    if (params->flags->minus && !params->flags->zero)
        write_spaces(params, params->width - length, params->precision - length);
}