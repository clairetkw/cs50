#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

float count_letters(string text);

int main(void)
{
    string text = get_string("Text: ");
    float score = count_letters(text);
    //printf("%f\n", score);
    if (score < 1)
    {
        printf("Before Grade 1\n");
    }
    if (score >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (score >= 1 && score < 16)
    {
        printf("Grade %i\n", (int) round(score));
    }
}

float count_letters(string text)
{
    // space = 32
    float words = 0;
    for (int i = 0; i <= strlen(text); i++)
    {
        if (text[0] != 32)
        {
            if (text[i] == 32)
                //if text[i] == space
            {
                words += 1;
            }
        }
    }

    float letters = 0;
    for (int j = 0; j <= strlen(text); j++)
    {
        if (text[0] != 32)
        {
            if ((text[j] >= 65 && text[j] <= 90) || (text[j] >= 97 && text[j] <= 122))
                // A = 65; Z = 90; a = 97; z = 122
            {
                letters += 1;
            }
        }
    }

    float sentences = 0;
    for (int k = 0; k <= strlen(text); k++)
    {
        if (text[0] != 32)
        {
            if (text[k] == 33 || text[k] == 46 || text[k] == 63)
                // ! = 33; . = 46; ? = 63
            {
                sentences += 1;
            }
        }
    }

    float L = letters / (words + 1) * 100;
    float S = sentences / (words + 1) * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    return index;
    //return words + 1;
    //return letters;
    //return sentences;
}
