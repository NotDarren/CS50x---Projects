#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int counter_alpha(string s);
int counter_word(string s);
int counter_sentence(string s);
double avL(int letter, int word);
double avS(int word, int sentence);

int main(void)
{
    string s = get_string("Input: ");
  
    int letters = counter_alpha(s);
    int words = counter_word(s);
    int sentence = counter_sentence(s);
    double L = avL(letters, words);
    double S = avS(words, sentence);

    double avg = 0.0588 * L - 0.296 * S - 15.8;
    if (avg > 1)
    {
        avg = round(avg);
    }

    // print grade level
    if (avg < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (avg >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int) avg);
    }
}

int counter_alpha(string s)
{
    int letter = 0;

    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (isalpha(s[i]))
        {
            letter++;
        }
    }
    return letter;
}

int counter_word(string s)
{
    int word = 1;

    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (isspace(s[i]))
        {
            word++;
        }
    }
    return word;
}

int counter_sentence(string s)
{
    int sentence = 0;
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] == '.' || s[i] == '?' || s[i] == '!')
        {
            sentence++;
        }
    }
    return sentence;
}

double avL(int letter, int word)
{
    double L = ((double) letter / (double) word) * 100.0;
    return L;
}

double avS(int word, int sentence)
{
    double S = ((double) sentence / (double) word) * 100.0;
    return S;
}
