#include <math.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>
#include <stdio.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string str = get_string("Text: ");

    // printf("%i letters\n", count_letters(str));
    // printf("%i words\n", count_words(str));
    // printf("%i sentences\n", count_sentences(str));

    float L = (count_letters(str) / (float) count_words(str)) * 100;
    float S = (count_sentences(str) / (float) count_words(str)) * 100;

    int index = round(0.0588 * L - 0.296 * S - 15.8);
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }

}

int count_letters(string text)
{
    int letters = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalnum(text[i]))
        {
            letters++;
        }
    }
    return letters;
}

int count_words(string text)
{
    int words = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isspace(text[i]))
        {
            words++;
        }
    }
    return words + 1;
}

int count_sentences(string text)
{
    int sentences = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }
    return sentences;
}