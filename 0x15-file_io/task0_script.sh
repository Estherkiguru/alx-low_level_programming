#!/bin/bash

gcc -Wall -Werror -pedantic -Wextra -std=gnu89 0-read_textfile.c 0-main.c -o a

if [ $? -eq 0 ]; then
	./a Requiescat
else
	echo "Compilation failed. Please fix the code."
fi

