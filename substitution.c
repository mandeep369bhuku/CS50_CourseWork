// Problem set 2, substitution problem

#include<cs50.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

bool checkKey(string text, char x[]);
void encryption(string text, char k[]);
int searchKey(char k[], char letter);
bool isDublicate(char key[], char letter, int n);

int main(int argc, char *argv[])
{
    char key[26];


    if (argc == 2 && checkKey(argv[1], key))
    {
        string userText = get_string("plaintext: ");
        encryption(userText, key);
    }
    else if (argc == 1 || argc > 2)
    {
        printf("%s key\n", argv[0]);
        return 1;
    }
    else
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    return 0;
}


// Encryption function
void encryption(string Utext, char key[])
{
    printf("ciphertext: ");
    char alphabets[26] ={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    int converted[strlen(Utext)];
    for (int i = 0, n = strlen(Utext); i < n; i++)
    {
        //Searches the encription key and stores the indices of letters in an integer array.
        converted[i] = searchKey(alphabets, tolower(Utext[i]));
        if (converted[i] == 404)
        {
            printf("%c", Utext[i]);
        }
        else if (Utext[i] > 64 && Utext[i] < 91)
        {
            printf("%c", toupper(key[converted[i]]));
        }
        else
        {
            printf("%c", key[converted[i]]);
        }
    }
    printf("\n");
}


int searchKey(char alpha[], char letter)
{
    for (int i = 0; i < 26; i++)
    {
        if (alpha[i] == letter)
        {
            return i;
        }
    }
    // Synonyms to error:404 not found
    return 404;
}


// Checks key and returns "True" if key contains all characters and "False" is key contains integer or symbols.
bool checkKey(string Ktext, char key[])
{
    if (strlen(Ktext) != 26)
    {
        return false;
    }
    else
    {
        for (int i = 0, n = strlen(Ktext); i < n; i++)
        {
            // Check if key contains any other character other than alphabets
            if (!((Ktext[i] > 64 && Ktext[i] < 91) || (Ktext[i] > 96 && Ktext[i] < 123)))
            {
                return false;
            }
            else
            {
                key[i] = tolower(Ktext[i]);
            }
        }
    }
    for (int i = 0; i < 26; i++)
    {
        if (isDublicate(key, key[i], i))
        {
            return false;
        }
    }
    return true;
}


// Returns true if key contains dublicate character else returns false
bool isDublicate(char key[], char letter, int n)
{
    for (int i = n + 1; i < 26; i++)
    {
        if (letter == key[i])
        {
            return true;
        }
    }
    return false;
}
