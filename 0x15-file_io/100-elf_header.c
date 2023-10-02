#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <elf.h>

#define BUF_SIZE 128

void print_elf_header_info(Elf64_Ehdr elf_header);

int main(int argc, char *argv[]) {
    const char *elf_filename;
    Elf64_Ehdr elf_header;
    int fd;
    int read_result;

    if (argc != 2) {
        dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
        return 98;
    }

    elf_filename = argv[1];

    fd = open(elf_filename, O_RDONLY);
    if (fd == -1) {
        dprintf(STDERR_FILENO, "Error: Cannot open file %s\n", elf_filename);
        return 98;
    }

    read_result = read(fd, &elf_header, sizeof(elf_header));
    if (read_result != sizeof(elf_header)) {
        dprintf(STDERR_FILENO, "Error: Cannot read from file %s\n", elf_filename);
        close(fd);
        return 98;
    }

    if (memcmp(elf_header.e_ident, ELFMAG, SELFMAG) != 0) {
        dprintf(STDERR_FILENO, "Error: %s is not an ELF file\n", elf_filename);
        close(fd);
        return 98;
    }

    print_elf_header_info(elf_header);
    close(fd);
    return 0;
}

void print_elf_header_info(Elf64_Ehdr elf_header) {
    int i;
    printf("ELF Header:\n");
    printf("  Magic:   ");
    for (i = 0; i < EI_NIDENT; i++) {
        printf("%02x%c", elf_header.e_ident[i], (i == EI_NIDENT - 1) ? '\n' : ' ');
    }
    printf("  Class:                             ELF64\n");
    printf("  Data:                              2's complement, little endian\n");
    printf("  Version:                           1 (current)\n");
    printf("  OS/ABI:                            UNIX - System V\n");
    printf("  ABI Version:                       0\n");
    printf("  Type:                              EXEC (Executable file)\n");
    printf("  Entry point address:               0x%lx\n", (unsigned long)elf_header.e_entry);
}

