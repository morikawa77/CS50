#include <cs50.h>
#include <math.h>
#include <stdio.h>
int main(void)
{
    long long ccnumber = 0;
    // Ask for credit card number  
    do
    {
        printf("What is your card number? ");
        ccnumber = get_long_long();
    }
    while (ccnumber < 0);
    // Verify number of digits
    int count = 0;
    long long digits = ccnumber;
    while (digits > 0)
    {
        digits = digits / 10;
        count++;
    }
    // Verify if number is invalid
    if ((count != 13) && (count != 15) && (count != 16))
    {
        printf("INVALID\n");
    }
    int number[count];
    // count number
    for (int i = 0; i < count; i++)
    {
        number[i] = ccnumber % 10;
        ccnumber = ccnumber / 10;
    }
    int initnumber[count];
    for (int i = 1; i < count; i++)
    {
        initnumber[i] = number[i];
    }
    for (int i = 1; i < count; i += 2)
    {
        number[i] = number[i] * 2;
    }
    int v = 0;
    int temp;
    // verify if it is visa
    if (count == 13)
    {
        for (int i = 0; i < count; i++)
        {
            temp = (number[i] % 10) + (number[i] / 10 % 10);
            v = v + temp;
        }
        if (initnumber[12] == 4 && v % 10 == 0)
        {
            printf("VISA\n");
        }
        // or returns invalid
        else
        {
            printf("INVALID\n");
        }
    }
    // verify if it is amex
    if (count == 15)
    {
        for (int i = 0; i < count; i++)
        {
            temp = (number[i] % 10) + (number[i] / 10 % 10);
            v = v + temp;
        }
        // amex
        if (initnumber[14] == 3 && v % 10 == 0 && (initnumber[13] == 4 || initnumber[13] == 7))
        {
            printf("AMEX\n");
        }
        // or returns invalid
        else
        {
            printf("INVALID\n");
        }
    }
    // verify if it is visa or mastercard
    if (count == 16)
    {
        for (int i = 0; i < count; i++)
        {
            temp = (number[i] % 10) + (number[i] / 10 % 10);
            v = v + temp;
        }
        // visa
        if (initnumber[15] == 4 && v % 10 == 0)
        {
            printf("VISA\n");
        }
        // mastercard
        else if (initnumber[15] == 5 && v % 10 == 0 && (initnumber[14] == 1 || initnumber[14] == 2 || initnumber[14] == 3 
                 || initnumber[14] == 4 || initnumber[14] == 5))
        {
            printf("MASTERCARD\n");
        }
        // or returns invalid
        else
        {
            printf("INVALID\n");
        }
    }
    return 0;
}