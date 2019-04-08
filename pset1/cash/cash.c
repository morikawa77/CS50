#include <stdio.h>
#include <cs50.h>
#include <math.h>

// declare functions
int tenCents(void);
int fiveCents(void);
int oneCent(void);
float cash;
int cents, coins, coins25, coins10, coins5, coins1 = 0;

int main(void)
{
    // get value greater than 0
    do
    {
        cash = get_float("Change owed: ");
    } 
    while (cash < 0);
    
    // trasnform value in cents
    cents = (int)round(cash * 100);
    
    // calculate how many 25c coins
    // if cents are divisible by 25
    if (cents / 25 > 0)
    {
        // coins = cents / coin value
        coins25 = (int)round(cents / 25);
        coins = coins + coins25;
        
        // if coins of 25 cents pay
        if ((cents % 25) == 0) 
        {
            printf("%d\n", coins);
        } 
        // else pay with coins of 10 cents
        else 
        {
            cents = cents - (coins25 * 25);
            tenCents();
        }
    } 
    // cents are not divisible by 25
    else 
    {
        tenCents();
    }
}

// calculate how many 10c coins
int tenCents(void)
{
    // if cents are divisible to 10
    if (cents / 10 > 0) 
    {
        coins10 = (int)round(cents / 10);
        coins = coins + coins10;
        // if coins 10 cents pay   
        if ((cents % 10) == 0)
        {
            printf("%d\n", coins);
        } 
        // else pay with coins of 5 cents
        else 
        {
            cents = cents - (coins10 * 10);
            fiveCents();
        }
    } 
    // cents are not divisible by 10
    else 
    {
        fiveCents();
    }
    
    return 0;
}
    
// calculate how many 5c coins
int fiveCents(void)
{
    // if cents are divisible to 5
    if (cents / 5 > 0)
    {
        coins5 = (int)round(cents / 5);
        coins = coins + coins5;
        
        // if coins of 5 cents pay
        if ((cents % 5) == 0)
        {
            printf("%d\n", coins);
        } 
        // else pay with coins of 1 cent
        else 
        {
            cents = cents - (coins5 * 5);
            oneCent();
        } 
    } 
    // cents are not divisible by 5
    else 
    {
        oneCent();
    }
    
    return 0;
}
    
// calculate how many 1c coins
int oneCent(void) 
{
    coins = coins + cents;
    printf("%d\n", coins);
    
    return 0;
}