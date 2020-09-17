//Problem set 2, caesar cypher problem

#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


bool checkInteger(string txt);
void encryption(string text, int key);
int searchArray(char letters[], char alpha);


int main(int argc, char *argv[])
{

    if (argc == 2 && checkInteger(argv[1]))
    {
        int k = atoi(argv[1]);
        string text;
        text = get_string("plaintext: ");
        encryption(text, k);
    }
    else
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }
    return 0;
}



bool checkInteger(string texx)
{
    for (int i = 0, n = strlen(texx); i < n; i++)
    {
        if (texx[i] != '0' && !(atoi(texx + i)))
        {
            return false;
        }
    }
    return true;
}



void encryption(string text, int key)
{
    char alphabets[26] ={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    printf("ciphertext: ");
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        int p_i = searchArray(alphabets, tolower(text[i]));
        if (p_i == 404)
        {
            printf("%c", text[i]);
        }
        else
        {
            int c = (p_i + key) % 26;
            if (text[i] > 64 && text[i] < 91)
            {
                printf("%c", toupper(alphabets[c]));
            }
            else
            {
                printf("%c", alphabets[c]);
            }
        }
    }
    printf("\n");
}

//Function returns the index of alphabet
int searchArray(char letters[], char alpha)
{
    for (int i = 0, n = 26; i < n; i++)
    {
        if (letters[i] == alpha)
        {
            return i;
        }
    }
    return 404;
}
