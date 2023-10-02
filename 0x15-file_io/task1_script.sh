#!/bin/bash

gcc -Wall -Werror -pedantic -Wextra -std=gnu89 1-create_file.c 1-main.c -o b

if [ $? -eq 0 ]; then
	./b hello "Hello, this is the content of the file."
else
	echo "Compilation failed. Please fix the code."
fi

