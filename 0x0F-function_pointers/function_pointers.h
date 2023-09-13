#ifndef FUNCTION_PONTERS_H
#define  FUNCTION_PONTERS_H
#include <stddef.h>

/**
 * struct op - Struct op
 * @op: The operator
 * @f: The function associated
 */
typedef struct op
{
char *op;
int (*f)(int a, int b);
} op_t;

void print_name(char *name, void (*f)(char *));
void array_iterator(int *array, size_t size, void (*action)(int));
int int_index(int *array, int size, int (*cmp)(int));


#endif /* FUNCTION_PONTERS.H */
