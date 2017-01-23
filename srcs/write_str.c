#include "ft_printf.h"

void	write_string(param *params, va_list args)
{
	char *tmp
	int length;
	int i;

	i = 0;
	tmp = va_arg(args, char *);
	length = ft_strlen(tmp);
	if (!params->flags->minus)
        write_spaces(params, params->width - length, params->precision - length);
    while (params->precision > 0)
    {
    	if (tmp[i])
        	write(1, tmp[i++], 1);
    	params->precision--;
    }
    if (params->flags->minus)
        write_spaces(params, params->width - length, params->precision - length);
}