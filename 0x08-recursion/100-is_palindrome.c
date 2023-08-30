#include "main.h"

int length(char *s);
int check_palindrome(char *s, int start, int end);

/**
 * is_palindrome - Check if a string is a palindrome
 * @s: The string to check
 *
 * Return: 1 if palindrome, 0 if not
 */
int is_palindrome(char *s)
{
int len = length(s);
return (check_palindrome(s, 0, len - 1));
}

/**
 * length - Calculate the length of a string
 * @s: The string
 *
 * Return: Length of the string
 */
int length(char *s)
{
if (*s == '\0')
return (0);
return (1 + length(s + 1));
}

/**
 * check_palindrome - Helper function to check if a string is a palindrome
 * @s: The string to check
 * @start: The starting index
 * @end: The ending index
 *
 * Return: 1 if palindrome, 0 if not
 */
int check_palindrome(char *s, int start, int end)
{
if (start >= end)
return (1);

if (s[start] != s[end])
return (0);

return (check_palindrome(s, start + 1, end - 1));
}

