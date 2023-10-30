#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

/**
 * handle_error - Print an error message and exit with the given status code.
 * @message: The error message to print.
 * @exit_code: The exit status code.
 */
void handle_error(const char *message, int exit_code)
{
    dprintf(STDERR_FILENO, "Error: %s\n", message);
    exit(exit_code);
}

/**
 * print_elf_header - Print information from the ELF header.
 * @header: Pointer to the ELF header.
 */
void print_elf_header(Elf64_Ehdr *header)
{
    int i;
    
    printf("ELF Header:\n");
    printf("  Magic:   ");
    for (i = 0; i < EI_NIDENT; i++) {
        printf("%02x", header->e_ident[i]);
        if (i < EI_NIDENT - 1)
            printf(" ");
    }
    printf("\n");
    printf("  Class:                             %s\n", (header->e_ident[EI_CLASS] == ELFCLASS32) ? "ELF32" : "ELF64");
    printf("  Data:                              %s\n", (header->e_ident[EI_DATA] == ELFDATA2LSB) ? "2's complement, little endian" : "2's complement, big endian");
    printf("  Version:                           %d (current)\n", (int)header->e_ident[EI_VERSION]);
    printf("  OS/ABI:                            %s\n", (header->e_ident[EI_OSABI] == ELFOSABI_SYSV) ? "UNIX - System V" : "Others");
    printf("  ABI Version:                       %d\n", (int)header->e_ident[EI_ABIVERSION]);
    printf("  Type:                              %d\n", (int)header->e_type);
    printf("  Entry point address:               0x%lx\n", (unsigned long)header->e_entry);
}

int main(int argc, char *argv[])
{
    int fd;
    Elf64_Ehdr header;

    if (argc != 2)
        handle_error("Usage: elf_header elf_filename", 98);

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        handle_error("Can't read from file", 98);

    if (read(fd, &header, sizeof(header)) == -1)
        handle_error("Can't read from file", 98);

    if (lseek(fd, 0, SEEK_SET) == -1)
        handle_error("Can't read from file", 98);

    print_elf_header(&header);
    close(fd);

    return 0;
}

