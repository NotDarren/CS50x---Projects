#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long card;
    do
    {
        card = get_long("Number: ");
    }
    while (card < 0);

    int length = 0;
    long temp = card;
    do
    {
        length++;
        temp /= 10;
    }
    while (temp > 0);

    if (length != 13 && length != 15 && length != 16)
    {
        printf("INVALID\n");
        return 0;
    }

    int position = 0;
    int digit = 0;
    temp = card;
    int sum = 0;

    while (temp > 0)
    {
        digit = temp % 10;

        if (position % 2 == 0) // 2/2=1.0, 3/2=1.5 (IF EVEN NUMBER)
        {
            sum += digit;
        }
        else
        {
            digit *= 2;

            if (digit > 9)
            {
                sum += digit / 10 + digit % 10; // sum = digit/10 + remainder of digit/10
            }
            else
            {
                sum += digit;
            }
        }
        temp /= 10;
        position++;
    }

    if (sum % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    long start = card;
    while (start > 100)
    {
        start /= 10;
    }

    if (start / 10 == 4 && (length == 13 || length == 16))
    {
        printf("VISA\n");
    }
    else if (length == 15 && (start == 34 || start == 37))
    {
        printf("AMEX\n");
    }
    else if (length == 16 &&
             (start == 51 || start == 52 || start == 53 || start == 54 || start == 55))
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
        return 0;
    }
}
