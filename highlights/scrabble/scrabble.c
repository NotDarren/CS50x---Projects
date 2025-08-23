#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int score(string s);

int main(void)
{
    string p1 = get_string("Player 1: ");
    string p2 = get_string("Player 2: ");

    if (score(p1) < score(p2))
    {
        printf("Player 2 wins!\n");
    }
    else if (score(p1) > score(p2))
    {
        printf("Player 1 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int score(string s)
{
    // initial score
    int score = 0;

    for (int i = 0, len = strlen(s); i < len; i++)
    {
        if (isalpha(s[i])) // Only score alphabetic chars
        {
            int index = tolower(s[i]) - 'a'; // Convert char to index 0-25
            score += points[index];
        }
    }
    return score;
}
