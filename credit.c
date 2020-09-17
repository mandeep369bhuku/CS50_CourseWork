//Problem set 1 vredit problem

#include<stdio.h>
#include<cs50.h>
#include <stdlib.h>

int *getDigits(int long number, int);
int totalDigits(int long number);
int allConditions(int *arrayCardNo, int noDigits);


int main(void)
{
    int long cardNo;

    cardNo = get_long("Number: ");

    // Total no of digits in the card Number
    int noDigits = totalDigits(cardNo);
    //An array of all digits from end to first
    int *arrCardNo = getDigits(cardNo, noDigits);

    //Calculates the sum as per condition
    int sumFinal = allConditions(arrCardNo, noDigits);

    if (sumFinal % 10 != 0)
    {
        printf("INVALID\n");
    }
    else if (*(arrCardNo + noDigits - 1) == 3)
    {
        if (*(arrCardNo + noDigits - 2) == 4 || *(arrCardNo + noDigits - 2) == 7)
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }

    else if (*(arrCardNo + noDigits - 1) == 4)
    {
        printf("VISA\n");
    }

    else if (*(arrCardNo + noDigits - 1) == 5)
    {
        if (*(arrCardNo + noDigits - 2) > 0 && *(arrCardNo + noDigits - 2) < 6)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }

    free(arrCardNo);
    return 0;
}



int totalDigits(int long number)
{
    int noDigit = 1;
    while (number / 10 > 0)
    {
        number /= 10;
        noDigit += 1;
    }
    return noDigit;
}


int *getDigits(int long number, int noDigit)
{

    int *allDigits = malloc(noDigit * sizeof(int));

    for (int i = 0; i < noDigit; i++)
    {
        int mod = number % 10;
        number /= 10;
        allDigits[i] = mod;
    }
    return allDigits;
}


int allConditions(int *arrayCNo, int noDigits)
{

    int sumAllcondition = 0;

    for (int i = 0; i < noDigits; i++)
    {
        int countOdd = (2 * i) + 1;
        int countEven = 2 * i;
        if (countOdd <= noDigits || countEven <= noDigits)
        {
            int digitOdd = 2 * arrayCNo[countOdd];
            if (digitOdd < 10)
            {
                sumAllcondition += digitOdd;
            }
            else
            {
                sumAllcondition += digitOdd / 10;
                sumAllcondition += digitOdd - 10;
            }
            int digitEven = arrayCNo[countEven];
            sumAllcondition += digitEven;
        }
        else
        {
            break;
        }
    }
    return sumAllcondition;
}
