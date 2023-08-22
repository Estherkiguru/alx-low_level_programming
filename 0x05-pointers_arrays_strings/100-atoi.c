#include "main.h"
#include <limits.h>

/**
 * _atoi - Converts a string to an integer.
 * @s: The input string.
 *
 * Return: The converted integer.
 */
int _atoi(char *s)
{
    int sign = 1;
    int result = 0;
    int i = 0;

    while (s[i] != '\0')
    {
        if (s[i] == '-')
        {
            sign *= -1;
        }
        else if (s[i] >= '0' && s[i] <= '9')
        {
            int digit = s[i] - '0';

            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > INT_MAX % 10))
            {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            result = result * 10 + digit;
        }
        else if (result > 0)
        {
            break;
        }
        i++;
    }

    return result * sign;
}

