#include "ft_printf.h"

void    write_spaces(param *params, int n, int j)
{
    int i;

    i = 0;
    if (j < 0)
        j = 0;
    while (i < n - j)
    {
        write(1, " ", 1);
        i++;
    }
}