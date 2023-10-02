#!/bin/bash

gcc -Wall -pedantic -Werror -Wextra -std=gnu89 2-main.c 2-append_text_to_file.c -o c

if [ $? -eq 0 ]; then
        ./c hello "Appended text."
else
        echo "Compilation failed. Please fix the code."fi
