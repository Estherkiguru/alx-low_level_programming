#ifndef FUNCTION_PONTERS_H
#define  FUNCTION_PONTERS_H

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

#endif /* FUNCTION_PONTERS.H */
