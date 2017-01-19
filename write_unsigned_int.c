#include "ft_printf.h"

// get_int function just in case write_int needs line count
int    get_int_length(char *tmp, param *params, intmax_t n, int negative)
{
    int length;

    length = ft_strlen(tmp);
    if (params->flags->space || (params->flags->plus && n > 0) || negative)
        length++;
    return (length);
}

void write_unsigned_int(param *params, va_list args)
{
    char *tmp;
    int length;
    intmax_t n;

    remove_conflict_flags(params);
    n = va_arg(args, intmax_t);
    n = convert_unsigned(params, n);
    if (params->flags->zero)
        params->precision = params->width;
    tmp = ft_itoa(n, params->precision, params->flags->zero, 1);
    length = ft_strlen(tmp);
    if (!params->flags->minus && !params->flags->zero)
        write_spaces(params, params->width - length, params->precision - length);
    if (!(n == 0 && params->precision == 0))
        ft_putstr(tmp);
    if (params->flags->minus && !params->flags->zero)
        write_spaces(params, params->width - length, params->precision - length);
}