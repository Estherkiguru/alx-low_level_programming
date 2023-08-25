#include "main.h"
/**
 * infinite_add - Adds two numbers
 * @n1: First input number as a string
 * @n2: Second input number as a string
 * @r: Buffer to store the result
 * @size_r: Size of the buffer
 *
 * Return: Pointer to the result
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
int carry = 0;
int i = 0, j = 0, k = 0;
int len1 = 0, len2 = 0, max_len = 0;
while (n1[len1] != '\0')
len1++;
while (n2[len2] != '\0')
len2++;
if (len1 >= len2)
max_len = len1;
else
max_len = len2;
if (max_len + 1 >= size_r)
return (0);
r[max_len + 1] = '\0';
i = len1 - 1;
j = len2 - 1;
k = max_len;
while (i >= 0 || j >= 0 || carry)
{
int num1 = 0, num2 = 0, sum = 0;
if (i >= 0)
num1 = n1[i] - '0';
if (j >= 0)
num2 = n2[j] - '0';
sum = num1 + num2 + carry;
carry = sum / 10;
r[k] = (sum % 10) + '0';
i--;
j--;
k--;
}
if (k == -1)
return (r);
else
{
for (i = max_len; i >= 0; i--)
r[i + 1] = r[i];
r[0] = carry + '0';
return (r);
}
}

