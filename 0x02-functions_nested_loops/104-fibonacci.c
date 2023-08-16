#include <stdio.h>

int main(void)
{
    unsigned long int a = 1, b = 2, next;
    int i;

    printf("%lu, %lu, ", a, b);

    i = 3;
    while (i <= 98)
    {
        next = a + b;
        printf("%lu", next);

        if (i != 98)
            printf(", ");

        a = b;
        b = next;
        i++;
    }

    printf("\n");
    return 0;
}

