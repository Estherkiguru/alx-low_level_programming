#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s username\n", argv[0]);
        return 1;
    }

    char *username = argv[1];
    int key = 0;

    for (int i = 0; i < strlen(username); i++)
    {
        key += username[i];
    }

    printf("%d\n", key);

    return 0;
}

