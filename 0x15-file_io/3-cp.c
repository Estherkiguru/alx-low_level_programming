#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdarg.h>

void handle_error(int exit_code, const char *format, ...) {
    va_list args;
    va_start(args, format);
    vdprintf(STDERR_FILENO, format, args);
    va_end(args);
    exit(exit_code);
}

int main(int argc, char *argv[]) {
    char *file_from;
    char *file_to;
    int fd_from, fd_to;
    ssize_t bytes_read, bytes_written;
    char buffer[1024];

    if (argc != 3) {
        handle_error(97, "Usage: %s file_from file_to\n", argv[0]);
    }

    file_from = argv[1];
    file_to = argv[2];

    fd_from = open(file_from, O_RDONLY);
    if (fd_from == -1) {
        handle_error(98, "Error: Can't read from file %s\n", file_from);
    }

    fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0664);
    if (fd_to == -1) {
        handle_error(99, "Error: Can't write to file %s\n", file_to);
    }

    while ((bytes_read = read(fd_from, buffer, sizeof(buffer)) > 0)) {
        if (bytes_read == -1) {
            handle_error(98, "Error: Can't read from file %s\n", file_from);
        }

        bytes_written = write(fd_to, buffer, bytes_read);
        if (bytes_written == -1) {
            handle_error(99, "Error: Can't write to file %s\n", file_to);
        }
    }

    if (close(fd_from) == -1) {
        handle_error(100, "Error: Can't close fd %d\n", fd_from);
    }
    
    if (close(fd_to) == -1) {
        handle_error(100, "Error: Can't close fd %d\n", fd_to);
    }

    return 0;
}

