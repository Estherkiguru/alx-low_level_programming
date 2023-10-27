#include "main.h"

/**
 * get_endianness - Check the endianness of the system.
 *
 * Return: 0 if it's big-endian, 1 if it's little-endian.
 */
int get_endianness(void)
{
	unsigned int num = 1;
	char *endian = (char *)&num;

/* If the first byte of the integer is non-zero, it's little-endian */
	if (*endian)
		return (1); /* Little Endian */
	else
		return (0); /* Big Endian */
}

