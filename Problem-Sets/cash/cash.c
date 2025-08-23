#include <cs50.h>
#include <stdio.h>

int get_quarters(int cents);
int get_dime(int cents);
int get_nickel(int cents);
int get_pennies(int cents);

int main(void)
{
    int cents;
    do
    {
        cents = get_int("Change: ");
    }
    while(cents < 0);

    int quarters = get_quarters(cents);
    cents = cents - (quarters * 25);

    int dime = get_dime(cents);
    cents = cents - (dime * 10);

    int nickel = get_nickel(cents);
    cents = cents - (nickel * 5);

    int pennies = get_pennies(cents);
    cents = cents - (pennies * 1);

    printf("%i\n", quarters + dime + nickel + pennies);
}


int get_quarters(int cents)
{
    int quarters = 0;
    while(cents >= 25)
    {
        quarters++;
        cents -= 25;
    }
    return quarters;
}

int get_dime(int cents)
{
    int dime = 0;
    while(cents >= 10)
    {
        dime++;
        cents -= 10;
    }
    return dime;
}

int get_nickel(int cents)
{
    int nickel = 0;
    while(cents >= 5)
    {
        nickel++;
        cents -= 5;
    }
    return nickel;
}

int get_pennies(int cents)
{
    int pennies = 0;
    while(cents >= 1)
    {
        pennies++;
        cents -= 1;
    }
    return pennies;
}
