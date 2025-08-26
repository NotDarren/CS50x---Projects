#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (strlen(argv[1]) != 26)
    {
        printf("Key should be 26 alphabets\n");
        return 1;
    }

    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (isalpha(argv[1][i]) == 0)
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }

        for (int j = i + 1; j < n; j++)
        {
            if (tolower(argv[1][i]) == tolower(argv[1][j]))
            {
                printf("No duplicates\n");
                return 1;
            }
        }
    }

    string key = argv[1];
    string plain = get_string("plaintext: ");

    printf("ciphertext: ");
    for (int i = 0, n = strlen(plain); i < n; i++)
    {
        if (isalpha(plain[i]))
        {
            if (isupper(plain[i]))
            {
                printf("%c", toupper(key[plain[i] - 65]));
            }
            else
            {
                printf("%c", tolower(key[plain[i] - 97]));
            }
        }
        else
        {
            printf("%c", plain[i]);
        }
    }
    printf("\n");
    return 0;
}
