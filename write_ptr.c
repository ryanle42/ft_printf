#include "ft_printf.h"

static int hex_length(intmax_t n)
{
    int i;

    i = 0;
    while (n > 0)
    {
        n /= 16;
        i++;
    }
    return (i);
}

static char    *convert_hex(intmax_t n)
{
    char *base;
    char *str;
    int length;
    int i;

    i = 0;
    length = hex_length(n);
    str = (char *)malloc(sizeof(char) * length + 1);
        base = "0123456789abcdef";
    while (n > 0)
    {
        str[i++] = *(base + (n % 16));
        n /= 16;
    }
    str[i] = '\0';
    str = ft_strrev(str, i);
    return (str);
}

static char *add_zeros(char *str, int precision)
{
    int i;
    char *tmp;
    int zeros;

    i = 0;
    zeros = precision - ft_strlen(str);
    if (zeros < 0)
        zeros = 0;
    tmp = (char *)malloc(sizeof(char) * zeros + 1);
    while (i < zeros)
        tmp[i++] = '0';
    tmp[i] = '\0';
    return (ft_strjoin(tmp, str));
}

void    put_ptr(char *str, intmax_t n)
{
    if (n != 0)
        write(1, "0x", 2);
    ft_putstr(str);
}

static int     hex_str_length(param *params, char *str, intmax_t n)
{
    int length;

    length = ft_strlen(str);
    if (params->flags->hash && n != 0)
        length += 2;
    return (length);
}

void write_ptr(param *params, va_list args)
{	
    char *tmp;
    int length;
    long int n;

    remove_conflict_flags(params);
    n = (long int)(va_arg(args, void*));
    tmp = convert_hex(n);
    length = hex_str_length(params, tmp, n);
    if (n != 0)
    	length += 2;
    if (!params->flags->minus)
        write_spaces(params, params->width - length, params->precision - length);
    if (n != 0)
        put_ptr(tmp, n);
    if (params->flags->minus)
        write_spaces(params, params->width - length, params->precision - length);
}