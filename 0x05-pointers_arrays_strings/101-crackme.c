#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <key>\n", argv[0]);
        return 1;
    }

    char *key = argv[1];
    char password[100];  // Adjust the array size as needed

    srand(time(NULL));

    for (int i = 0; i < strlen(key); i++)
    {
        password[i] = key[i] ^ (rand() % 256); // XOR with random value
    }

    printf("Password: %s\n", password);

    return 0;
}

