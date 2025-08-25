#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool digit(string s);
char rotate(char c, int key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else if (digit(argv[1]) == false)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int key = atoi(argv[1]);
    string plain = get_string("Plaintext: ");

    int n = strlen(plain);
    char cypher[n + 1];

    for (int i = 0; i < n; i++)
    {
        cypher[i] = rotate(plain[i], key);
    }
    cypher[n] = '\0'; // null-terminate

    printf("Ciphertext: %s\n", cypher);
}

bool digit(string s)
{
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}

char rotate(char c, int key)
{
    if (isupper(c))
    {
        return (c - 'A' + key) % 26 + 'A';
    }
    else if (islower(c))
    {
        return (c - 'a' + key) % 26 + 'a';
    }
    else
    {
        return c;
    }
}
