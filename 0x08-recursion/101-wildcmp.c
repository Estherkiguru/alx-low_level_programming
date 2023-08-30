#include "main.h"

/**
 * wildcmp - Compare two strings with wildcards
 * @s1: The first string
 * @s2: The second string with wildcards
 *
 * Return: 1 if strings can be considered identical, 0 otherwise
 */
#include "main.h"

int wildcmp(char *s1, char *s2)
{
    if (*s2 == '\0')
        return (*s1 == '\0');

    if (*s2 == '*')
    {
        if (*(s2 + 1) == '*')
            return wildcmp(s1, s2 + 1);

        if (*s1 == '\0')
            return wildcmp(s1, s2 + 1);
        else
            return wildcmp(s1, s2 + 1) || wildcmp(s1 + 1, s2);
    }

    if (*s1 == *s2 || *s2 == '?')
        return wildcmp(s1 + 1, s2 + 1);

    return 0;
}

