section .data
    format db "Hello, Holberton",10,0  ; The format string with newline and null terminator

section .text
    global main

main:
    ; Load the address of the format string into rdi (1st argument for printf)
    mov rdi, format

    ; Call printf using syscall
    mov rax, 1          ; syscall number for write (1)
    mov rsi, rdi        ; 2nd argument: pointer to the format string
    mov rdx, 17         ; 3rd argument: length of the string
    syscall

    ; Exit the program
    mov rax, 60         ; syscall number for exit (60)
    xor rdi, rdi        ; 1st argument: exit code (0)
    syscall

