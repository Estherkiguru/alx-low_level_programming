#include "function_pointers.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int op_add(int a, int b)
{
    return a + b;
}

int op_sub(int a, int b)
{
    return a - b;
}

int op_mul(int a, int b)
{
    return a * b;
}

int op_div(int a, int b)
{
    if (b == 0)
    {
        printf("Error: Cannot divide by zero\n");
        exit(100);
    }
    return a / b;
}

int op_mod(int a, int b)
{
    if (b == 0)
    {
        printf("Error: Cannot divide by zero\n");
        exit(100);
    }
    return a % b;
}

