#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    // Check if correct number of arguments
    if (argc != 2)
    {
        printf("Usage: ./vigenere keyword\n");
        return 1;
    }
    else
    {
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (!isalpha(argv[1][i]))
            {
                printf("Usage: ./vigenere keyword\n");
                return 1;
            }
        }
    }

    // Store key as string and get length
    string k = argv[1];
    int kLen = strlen(k);

    // Get text to encode
    string p = get_string("plaintext: ");

    // print ciphertext
    printf("ciphertext: ");
    
    // Loop through text
    for (int i = 0, j = 0, n = strlen(p); i < n; i++)
    {
        // Get key for this letter
        int letterKey = tolower(k[j % kLen]) - 'a';

        // Keep case of letter
        if (isupper(p[i]))
        {
            // Get modulo number and add to appropriate case
            printf("%c", 'A' + (p[i] - 'A' + letterKey) % 26);

            // Only increment j when used
            j++;
        }
        else if (islower(p[i]))
        {
            printf("%c", 'a' + (p[i] - 'a' + letterKey) % 26);
            j++;
        }
        else
        {
            // return unchanged
            printf("%c", p[i]);
        }
    }

    printf("\n");

    return 0;
}
