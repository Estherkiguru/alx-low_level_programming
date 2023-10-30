#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 1024

void handle_error(char *message, int exit_code) {
    dprintf(STDERR_FILENO, "%s\n", message);
    exit(exit_code);
}

int main(int argc, char *argv[]) {
    int file_from, file_to, n_read, n_written;
    char buffer[BUFFER_SIZE];

    if (argc != 3) {
        handle_error("Usage: cp file_from file_to", 97);
    }

    file_from = open(argv[1], O_RDONLY);
    if (file_from == -1) {
        handle_error("Error: Can't read from file", 98);
    }

    file_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
    if (file_to == -1) {
        handle_error("Error: Can't write to file", 99);
    }

    while ((n_read = read(file_from, buffer, BUFFER_SIZE)) > 0) {
        n_written = write(file_to, buffer, n_read);
        if (n_written == -1 || n_written != n_read) {
            handle_error("Error: Can't write to file", 99);
        }
    }

    if (n_read == -1) {
        handle_error("Error: Can't read from file", 98);
    }

    if (close(file_from) == -1) {
        handle_error("Error: Can't close fd", 100);
    }

    if (close(file_to) == -1) {
        handle_error("Error: Can't close fd", 100);
    }

    return 0;
}

