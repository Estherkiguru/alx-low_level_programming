#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define EI_NIDENT 16

/* ELF Header structure */
typedef struct
{
	uint8_t e_ident[EI_NIDENT]; /* ELF identification */
	uint16_t e_type;            /* Object file type */
	uint16_t e_machine;         /* Machine architecture */
	uint32_t e_version;         /* Object file version */
    uint64_t e_entry;           /* Entry point address */
    uint64_t e_phoff;           /* Program header table file offset */
    uint64_t e_shoff;           /* Section header table file offset */
    uint32_t e_flags;           /* Processor-specific flags */
    uint16_t e_ehsize;          /* ELF header size in bytes */
    uint16_t e_phentsize;       /* Program header table entry size */
    uint16_t e_phnum;           /* Program header table entry count */
    uint16_t e_shentsize;       /* Section header table entry size */
    uint16_t e_shnum;           /* Section header table entry count */
    uint16_t e_shstrndx;        /* Section header string table index */
} Elf64_Ehdr;

/**
 * handle_error - Print an error message to standard error and exit
 * @exit_code: The exit code to use when exiting the program
 * @message: The error message to display
 */
void handle_error(int exit_code, const char *message, const char *arg)
{
	dprintf(STDERR_FILENO, message, arg);
	exit(exit_code);
}

int main(int argc, char *argv[])
{
	char *filename;
	Elf64_Ehdr header;
	ssize_t bytes_read;
	int fd;

	if (argc != 2)
	{
		handle_error(98, "Usage: %s elf_filename\n", argv[0]);
	}

	filename = argv[1];
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		handle_error(98, "Error: Can't open file %s\n", filename);
	}

	bytes_read = read(fd, &header, sizeof(header));
	if (bytes_read != sizeof(header) || memcmp(header.e_ident, "\x7F""ELF", 4) != 0)
	{
		handle_error(98, "Error: Not an ELF file: %s\n", filename);
	}

	printf("ELF Header:\n");
	printf("  Magic:   %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x\n",
			header.e_ident[0], header.e_ident[1], header.e_ident[2], header.e_ident[3],
			header.e_ident[4], header.e_ident[5], header.e_ident[6], header.e_ident[7],
			header.e_ident[8], header.e_ident[9], header.e_ident[10], header.e_ident[11],
			header.e_ident[12], header.e_ident[13], header.e_ident[14], header.e_ident[15]);
	printf("  Class:                             ELF%d\n", (header.e_ident[4] == 1) ? 32 : 64);
	printf("  Data:                              2's complement, %s endian\n",
			(header.e_ident[5] == 1) ? "little" : "big");
	printf("  Version:                           %d (current)\n", header.e_ident[6]);
	printf("  OS/ABI:                            ");
	switch (header.e_ident[7]) {
		case 0: printf("UNIX - System V\n"); break;
		case 2: printf("UNIX - NetBSD\n"); break;
		case 6: printf("UNIX - Solaris\n"); break;
		default: printf("<unknown: %d>\n", header.e_ident[7]); break;
    }
	printf("  ABI Version:                       %d\n", header.e_ident[8]);
	printf("  Type:                              ");
	switch (header.e_type)
	{
		case 1: printf("REL (Relocatable file)\n"); break;
		case 2: printf("EXEC (Executable file)\n"); break;
		case 3: printf("DYN (Shared object file)\n"); break;
		default: printf("<unknown: %d>\n", header.e_type); break;
	}
	printf("  Entry point address:               0x%lx\n", (unsigned long)header.e_entry);

	close(fd);
	return 0;
}

