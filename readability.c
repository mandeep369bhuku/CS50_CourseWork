
#include<stdio.h>
#include"cs50.h"
#include<stdlib.h>
#include<math.h>

double calculate_CLI(string);

int main()
{

    string text = get_string("Text: ");

    double clIndex = calculate_CLI(text);

    if (clIndex > 15)
    {
        printf("Grade 16+\n");
    }

    else if (clIndex < 1)
    {
        printf("Before Grade 1\n");
    }

    else
    {
        printf("Grade %.0f\n", clIndex);
    }

    return 0;
}




double calculate_CLI(string text)
{
    char split = ' ';
    int i = 0;
    int noLines = 0;
    // to account for the NULL character i.e '\0', we initialized no. of letters = -1
    int noLetters = -1;
    // no. of words is initialized as 1 to add last word, since it won't be added due to '.'
    // insted of ' ' at the end.
    int noWords = 1;

    while (split != '\0')
    {
        split = text[i];
        if (split == ' ')
        {
            noWords++;
        }
        else if (split == '.' || split == '!' || split == '?')
        {
            noLines++;
        }
        else
        {
            if (!((int)split > 33 && (int)split < 48))
            {
                noLetters++;
            }
        }
        i++;
    }

    if (noLines == 0)
    {
        noLines = 1;

    }

    double L = ((double)noLetters / (double)noWords) * 100;
    double S = ((double)noLines / (double)(noWords)) * 100;
    double CLIndex = 0.0588 * L - 0.296 * S - 15.8;


    return CLIndex;
}

