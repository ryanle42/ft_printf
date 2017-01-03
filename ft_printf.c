#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

int ft_printf(const char *fmt, ...)
{
    int d;
    char *tmp;
    va_list args;

    va_start(args, fmt);
    while (*fmt)
    {
        if (*fmt == '%')
        {
            fmt++;
            if (*fmt == 'd' || *fmt == 'i')
            {
                d = va_arg(args, int);
                tmp = ft_itoa(d);
                ft_putstr(tmp);
            }
            else if (*fmt == 's')
            {
                tmp = va_arg(args, char *);
                ft_putstr(tmp);
            }
        }
        else
            write(1, fmt, 1);
        fmt++;
    }
}

int main(void) 
{
    char *a = NULL;
    ft_printf("hell%s man%i%s\n", 20, 19, a);
    printf("hell%s man%d%s\n", 20, 19, a);
}