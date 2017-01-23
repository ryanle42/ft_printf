#include "ft_printf.h"

intmax_t convert_signed(param *params, intmax_t n)
{
    if (params->size == 1)
        n = (short)n;
    else if (params->size == 2)
        n = (intmax_t)n;
    else if (params->size == 3)
        n = (long)n;
    else if (params->size == 4)
        n = (size_t)n;
    else if (params->size == 5)
        n = (char)n;
    else if (params->size == 6)
        n = (long long)n;
    else
        n = (int)n;
    return (n);
}

intmax_t convert_unsigned(param *params, intmax_t n)
{
    if (params->size == 1)
        n = (unsigned short)n;
    else if (params->size == 2)
        n = (uintmax_t)n;
    else if (params->size == 3)
        n = (unsigned long)n;
    else if (params->size == 4)
        n = (size_t)n;
    else if (params->size == 5)
        n = (unsigned char)n;
    else if (params->size == 6)
        n = (unsigned long long)n;
    else
        n = (unsigned int)n;
    return (n);
}