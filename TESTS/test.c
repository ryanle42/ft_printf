#include <fcntl.h>
#include "ft_printf.h"

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

int main()
{
	char *line1;
    char *line2;
    int fd;
    fd = open("file", O_RDONLY);
    int i = 0, j = 0;
    while (get_next_line(fd, &line1) > 0)
    {
    	get_next_line(fd, &line2);
    	if (ft_strcmp(line1, line2) != 0)
    	{
            i = 0;
    		printf(RED "\nDOES NOT MATCH\n" RESET);
            printf("ft_printf:");
            while (line1[i] && line2[i])
            {
                if (line1[i] != line2[i])
                    printf(YEL "%c" RESET, line1[i]);
                else
                    printf("%c", line1[i]);
                i++;
            }
            while (line1[i])
            {
                printf(YEL "%c" RESET, line1[i]);
                i++;
            }
            i = 0;
        	printf("\nprintf:   ");
            while (line1[i] && line2[i])
            {
                if (line1[i] != line2[i])
                    printf(YEL "%c" RESET, line2[i]);
                else
                    printf("%c", line2[i]);
                i++;
            }
            while (line2[i])
            {
                printf(YEL "%c" RESET, line2[i]);
                i++;
            }
            printf("\n");
            j++;
    	}
    }
    if (j == 0)
        printf(GRN "ALL PASSED :)\n" RESET);
    else if (j == 1)
        printf(RED "\n%i ERROR\n" RESET, j);
    else
        printf(RED "\n%i ERRORS\n" RESET, j);
}