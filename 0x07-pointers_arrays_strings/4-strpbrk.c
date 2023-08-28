#include <stdio.h>
#include "main.h"
char *_strpbrk(char *s, char *accept);
int main(void)
{
    char *s = "hello, world";
    char *f = "world";
    char *t;

    t = _strpbrk(s, f);
    if (t != NULL)
    {
        printf("%s\n", t);
    }
    return (0);
}

