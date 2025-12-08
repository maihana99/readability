#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Prompt the user for some text
    string text = get_string("Text: ");
    // Count the number of letters, words, and sentences in the text
    int letters = 0, sentences = 0, words = 1;

    // iteration to go through each character in the text given
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        // if there is a space we can assume word count goes up by 1
        if (text[i] == ' ')
        {
            words++;
        }
        // if there is punctuation we can assume sentences goes up by 1
        else if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentences++;
        }
        // if there is a alpha character we can assume letters goes up by 1
        else if (isalpha(text[i]))
        {
            letters++;
        }
    }

    // compute the Coleman-Liau index
    int index = round(0.0588 * letters / words * 100 - 0.296 * sentences / words * 100 - 15.8);

    // print the grade level
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
        // using %d as a placeholder for the index number calculated
        printf("Grade %d\n", index);
    }
}
