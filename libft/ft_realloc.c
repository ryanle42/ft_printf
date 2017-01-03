#include "libft.h"

char    *ft_realloc(char *str, int n)
{
    int length;
    char *out;
    int i;
    
    i = 0;
    length = (ft_strlen(str) + n);
    out = (char *)malloc(sizeof(char) * length + 1);
    while (str[i])
    {
        out[i] = str[i];
        i++;
    }
    out[i] = '\0';
    free(str);
    return (out);
}