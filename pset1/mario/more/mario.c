#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n;
    
    // gets user input
    do
    {
        n = get_int("Height: ");
    } 
    while (n < 0 || n > 23);
    
    for (int i = 0; i < n; i++)
    {
        // prints spaces
        for (int j = i + 1 ; j < n; j++)
        {
            printf(" ");
        }
        // prints #s
        for (int k = 0; k < i + 1; k++)
        {
            printf("#");
        }
        
        // print central spaces
        printf("  ");
        
        // prints #s
        for (int k = 0; k < i + 1; k++)
        {
            printf("#");
        }

        // prints new line
        printf("\n");
    }
}