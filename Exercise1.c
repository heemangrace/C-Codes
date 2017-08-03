#include <stdio.h>

#define ADD 1
#define MIN 0

int main(void)
{
    int num1, num2;
    printf("Enter two integers: "); scanf("%d %d", &num1, &num2);

#ifndef ADD
    printf("Fuck you!\n");
#endif

#ifdef MIN
    printf("Sex!\n"); 
#endif

    return 0;
}