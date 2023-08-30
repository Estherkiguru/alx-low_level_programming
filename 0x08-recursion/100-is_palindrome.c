#include "main.h"

int is_palindrome_recursive(char *s, int start, int end);
/**
 * is_palindrome - Check if a string is a palindrome
 * @s: The string to check
 *
 * Return: 1 if palindrome, 0 if not
 */
int is_palindrome(char *s)
{

int len = 0;
while (s[len] != '\0')
len++;

 return (is_palindrome_recursive(s, 0, len - 1));
}

/**
 * check_palindrome - Helper function to check if a string is a palindrome
 * @s: The string to check
 * @start: The starting index
 * @end: The ending index
 *
 * Return: 1 if palindrome, 0 if not
 */
int is_palindrome_recursive(char *s, int start, int end)
{
if (start >= end)
return (1);

if (s[start] != s[end])
return (0);

return (is_palindrome_recursive(s, start + 1, end - 1));

}

