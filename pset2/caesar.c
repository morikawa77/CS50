#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
 {
    
    if (argc != 2) {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    
    
    int key = atoi(argv[1]);

    if (key < 0) {
        printf("Usage: ./caesar key\n");
        return 1;
    } else {
        // prompt user for a code to encrypt
        string code = get_string("plaintext: ");
        printf("ciphertext: ");
        for (int i = 0, n = strlen(code); i < n; i++) {
          if islower(code[i]) {
            printf("%c", (((code[i] + key) - 97) % 26) + 97);
          } else if isupper(code[i]) {
            printf("%c", (((code[i] + key) - 65) % 26) + 65);
          } else {
            printf("%c", code[i]);
          }
        }
        printf("\n");
        return 0;
    }
 }
