#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * strtow - Splits a string into words.
 * @str: The input string.
 *
 * Return: A pointer to an array of strings containing the words, or NULL if it fails.
 */
char **strtow(char *str)
{
char **words;
int i, j, k, len, word_count;

if (str == NULL || *str == '\0')
return (NULL);
len = 0;
word_count = 0;
for (i = 0; str[i]; i++)
{
if (str[i] != ' ')
{
word_count++;
while (str[i] && str[i] != ' ')
{
len++;
i++;
}
}
}
if (word_count == 0)
return (NULL);
words = malloc(sizeof(char *) * (word_count + 1));
if (words == NULL)
return (NULL);
i = 0;
while (*str)
{
if (*str != ' ')
{
len = 0;
while (str[len] && str[len] != ' ')
len++;
words[i] = malloc(sizeof(char) * (len + 1));
if (words[i] == NULL)
{
free(words);
for (j = 0; j < i; j++)
free(words[j]);
return (NULL);
}
for (k = 0; k < len; k++)
words[i][k] = str[k];
words[i][k] = '\0';
i++;
str += len;
}
else
str++;
}
words[i] = NULL;
return (words);
}
