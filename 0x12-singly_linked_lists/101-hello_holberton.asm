section .data
    format db "Hello, Holberton",10,0

section .text
    extern printf
    global main

main:
    push rbp
    mov rdi, format
    call printf
    pop rbp
    ret

