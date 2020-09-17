#include <cs50.h>
#include <stdio.h>

int main(void){
    //prompts the user for his name
    string text = get_string("What is your name?\n");

    //print out the text
    printf("Hello, %s\n",text);
    return 0;
}
