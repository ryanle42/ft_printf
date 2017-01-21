#include "ft_printf.h"

//%[parameter][flags][width][.precision][length]type

void    get_wid_prec(const char **fmt, param *params)
{
    while (get_flag(**fmt, params->flags) != 0)
        (*fmt)++;
    while (ft_isdigit(**fmt))
    {
        params->width *= 10;
        params->width += (**fmt - '0');
        (*fmt)++;
    }
    if (**fmt == '.')
    {
        (*fmt)++;
        params->is_precision = 1;
        params->precision = 0;
        while (ft_isdigit(**fmt))
        {
            params->precision *= 10;
            params->precision += (**fmt - '0');
            (*fmt)++;
        }
    }
    params->size = get_size(*fmt);
    if (params->size > 4)
        (*fmt) += 2;
    else if (params->size > 0)
        (*fmt)++;
}
int ft_printf(const char *fmt, ...)
{
    param *params;
    va_list args;
    char *tmp;
    va_start(args, fmt);
    while (*fmt)
    {
        if (*fmt == '%')
        {
            params = reset_params();
            fmt++;
            get_wid_prec(&fmt, params);
            if (*fmt == 'd' || *fmt == 'i')
                write_int(params, args);
            else if (*fmt == 'u' || *fmt == 'D' || *fmt == 'U')
                write_unsigned_int(params, args);
            else if (*fmt == 'o' || *fmt == 'O')
                write_octal(params, args);
            else if (*fmt == 'c')
                write_char(params, args);
            else if (*fmt == 'x')
                write_hex(params, args, 0);
            else if (*fmt == 'X')
                write_hex(params, args, 1);
            else if (*fmt == 'p')
                write_ptr(params, args);
            else if (*fmt == 's')
                write_string(params, args);
            else if (*fmt == '%')
                ft_putchar('%');
        }
        else
            write(1, fmt, 1);
        fmt++;
    }
    return (1);
}

int main(void) 
{
    char *a = "higfhgh";
    ft_printf("hell%-.0D man%.10i%.10s%10c%%%%\nx:%#o\nX:%#X\n\n", -12, -18433, a, 'd', 2312321, 0);
    printf("hell%-.0U man%.10i%.10s%10c%%%%\nx:%#O\nX:%#X\n\n", -12, -18433, a, 'd', 2312321, 0);
}
