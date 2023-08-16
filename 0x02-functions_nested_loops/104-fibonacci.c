#include <stdio.h>

int main(void)
{
    unsigned long int a = 1, b = 2, next;
    int i = 3;

    printf("%lu, %lu", a, b);

    while (i <= 98)
    {
        next = a + b;

        if (i % 5 == 0) {
            printf(",\n%lu", next);
        } else {
            printf(", %lu", next);
        }

        a = b;
        b = next;
        i++;
    }

    printf("\n");
    return 0;
}

