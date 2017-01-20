#include "ft_printf.h"

int get_flag(int fmt, flag *flags)
{
    if (fmt == '#')
        flags->hash++;
    if (fmt == '0')
        flags->zero++;
    if (fmt == ' ')
        flags->space++;
    if (fmt == '-')
        flags->minus++;
    if (fmt == '+')
        flags->plus++;
    if (fmt == '#' || fmt == '0' || fmt == ' ' || fmt == '-' || fmt == '+')
        return (1);
    return (0);
}

param *reset_params()
{
    param *params;

    params = (param *)malloc(sizeof(param));
    params->flags = (flag *)malloc(sizeof(flag));
    params->flags->hash = 0;
    params->flags->minus = 0;
    params->flags->plus = 0;
    params->flags->space = 0;
    params->flags->zero = 0;
    params->precision = 1;
    params->is_precision = 0;
    params->width = 0;
    return (params);
}

void    remove_conflict_flags(param *params)
{
    if (params->flags->zero && params->flags->minus)
        params->flags->zero = 0;
    if (params->flags->plus && params->flags->space)
        params->flags->space = 0;
    if (params->flags->zero && (params->precision > 0))
       params->flags->zero = 0;
}
int is_conversion(char fmt)
{
    if (fmt == 'c' || fmt == 's' || \
        fmt == 'd' || fmt == 'i' || \
        fmt == 'x' || fmt == 'X' || \
        fmt == '%')
        return (1);
    return (0);
}

int get_size(const char *fmt)
{
    int ret;
    int i;
    char *size;

    i = 0;
    size = (char *)malloc(sizeof(char) * 3);
    while (!(is_conversion(*fmt)))
    {
        size[i] = *fmt;
        i++;
        fmt++;
    }
    size[i] = '\0';
    if (ft_strcmp(size, "h") == 0)
        return (1);
    if (ft_strcmp(size, "j") == 0)
        return (2);
    if (ft_strcmp(size, "l") == 0)
        return (3);
    if (ft_strcmp(size, "z") == 0)
        return (4);
    if (ft_strcmp(size, "hh") == 0)
        return (5);
    if (ft_strcmp(size, "ll") == 0)
        return (6);
    return (0);
}