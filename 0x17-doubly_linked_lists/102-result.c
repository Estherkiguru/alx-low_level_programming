#include <stdio.h>

int is_palindrome(int number)
{
    int original = number;
    int reversed = 0;

    while (number > 0)
    {
        reversed = reversed * 10 + number % 10;
        number /= 10;
    }

    return original == reversed;
}

int main(void)
{
    int max_palindrome = 0;

    for (int i = 100; i <= 999; i++)
    {
        for (int j = 100; j <= 999; j++)
        {
            int product = i * j;
            if (is_palindrome(product) && product > max_palindrome)
            {
                max_palindrome = product;
            }
        }
    }

    // Save the result to the file
    FILE *file = fopen("102-result", "w");
    if (file != NULL)
    {
        fprintf(file, "%d", max_palindrome);
        fclose(file);
    }
    else
    {
        fprintf(stderr, "Error: Unable to open file for writing.\n");
        return 1;
    }

    return 0;
}

