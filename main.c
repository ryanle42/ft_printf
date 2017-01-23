#include "ft_printf.h"

int main(void) 
{
    /*wchar_t *c = L"applepie";
    char a[4]={103, 0xc3, 0xa9, 0};
    //wchar_t b[3]={0x0061, 0x8161, 0};
    int length = 0;
    while (c[length])
        length++;
    print_memory(c, length * 4);
    ft_printf("sizeof c: %lu\n", length * 4);
    printf("sizeof c: %lu\n", sizeof(char));
    */

    // String Compare
    char *string = "hellowurld";
    printf("%s\n", string);
    ft_printf("%s\n", string);
    fflush(stdout);
    printf("qwefqwef%10s\n", string);
    ft_printf("qwefqwef%10s\n", string);
    fflush(stdout);
    printf("%-10s\n", string);
    ft_printf("%-10s\n", string);

    //int Compare
    fflush(stdout);
    printf("%020i\n", 1234);
    ft_printf("%020i\n", 1234);
    fflush(stdout);
    printf("%12i\n", 1234);
    ft_printf("%12i\n", 1234);
    fflush(stdout);
    printf("%-3.2li\n", 121212312312334);
    ft_printf("%-3.2li\n", 121212312312334);
    fflush(stdout);    
    printf("%0u\n", 1234);
    ft_printf("%0u\n", 1234);
    fflush(stdout);
    printf("%x\n", 1223434);
    ft_printf("%x\n", 1223434);

    //X Compare
    fflush(stdout);
    printf("%-X\n", 121212334);
    ft_printf("%-X\n", 121212334);
    fflush(stdout);  
    printf("%-.10lx\n", 121212312312334);
    ft_printf("%-.10lx\n", 121212312312334);
    fflush(stdout);  
    printf("%-3.2li\n", 121212312312334);
    ft_printf("%-3.2li\n", 121212312312334);
    fflush(stdout);  
    printf("%-3.2li\n", 121212312312334);
    ft_printf("%-3.2li\n", 121212312312334);
    fflush(stdout);  
    printf("%022x\n", 12334);
    ft_printf("%022x\n", 12334);
    fflush(stdout);
    printf("%022x\n", 12334);
    ft_printf("%022x\n", 12334);
    fflush(stdout);  
    printf("%-30lX\n", 121212312312334);
    ft_printf("%-30lX\n", 121212312312334);
    fflush(stdout);  
    printf("%-3.22li\n", 121212312312334);
    ft_printf("%-3.22li\n", 121212312312334);
    fflush(stdout);  
    //multi input
    ft_printf("hell%.0d man%.10i%s%10c%%%%x:%#oX:%#X\n", -12, -18433, string, 'd', 2312321, 0);
    printf("hell%.0d man%.10i%s%10c%%%%x:%#oX:%#X\n", -12, -18433, string, 'd', 2312321, 0);
    fflush(stdout);
}
