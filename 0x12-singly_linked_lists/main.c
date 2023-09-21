#include <stdio.h>
#include "main.h"

void hello_holberton(void) {
    printf("Hello, Holberton\n");
}

int main(void) {
    hello_holberton();
    return 0;
}
nasm -f elf64 101-hello_holberton.asm && gcc -no-pie -std=gnu89 101-hello_holberton.o -o hello
