
#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float owed = get_float("Change owed: ");
    while (owed < 0)
    {
        owed = get_float("Change owed: ");
    }
    int change = round(owed * 100);
    int count = 0;
    while (change > 0)
    {
        if (change % 25 != 0)
        {
            count++;
            change -= 25;
        }
        else if (change % 10 != 0)
        {
            count++;
            change -= 10;
        }
        else if (change % 5 != 0)
        {
            count++;
            change -= 5;
        }
        else
        {
            count++;
            change -= 1;
        }
    }
    printf("%i\n", count);
    return 0;
}
