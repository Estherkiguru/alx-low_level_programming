#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Generates random valid passwords for 101-crackme.
 *
 * Return: Always 0.
 */
int main(void)
{
    char password[84];
    int sum = 0;
    int rand_num;

    srand(time(0)); // Seed the random number generator with current time

    for (int i = 0; i < 10; i++)
    {
        rand_num = rand() % 78 + 48; // ASCII codes for valid characters
        password[i] = rand_num;
        sum += rand_num;
    }

    password[10] = 2772 - sum; // ASCII code for the last character

    password[11] = '\0'; // Null-terminate the string

    printf("%s", password);

    return (0);
}

