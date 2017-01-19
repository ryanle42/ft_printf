#include "ft_printf.h"

void	write_char(param *params, va_list args)
{
	char *tmp;
    int length;
    char n;

    remove_conflict_flags(params);
    n = ((unsigned char)convert_unsigned(params, va_arg(args, int)));
    if (!params->flags->minus)
        while (params->width > 1)
        {
        	write(1, " ", 1);
        	params->width--;
        }
    write(1, &n, 1);
    while (params->width > 1)
    {
        write(1, " ", 1);
        params->width--;
    }
}