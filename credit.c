#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // Determine the length of the credit card
    long long ccNumber = get_long_long("Please enter your credit card number.\n");

    int ccLength = 0;
    long long tempNumber = ccNumber;

    while (tempNumber >= 1)
    {
        tempNumber = tempNumber / 10;
        ccLength++;
    }
    tempNumber = ccNumber;

    //Check to see if the card has valid digits
    if (ccLength != 13 && ccLength != 15 && ccLength != 16)
    {
        printf("INVALID\n");
        return 0;
    }

    //Find the first two digits
    int first_digits;
    while (tempNumber >= 100)
    {
        tempNumber = tempNumber / 10;
    }
    first_digits = tempNumber;
    tempNumber = ccNumber;

    //Luhn's Algorithm
    int sum;
    long long lldigit;
    int idigit;
    for (int i = 0; i < ccLength; i++)
    {
        //Isolate the digits from right to left
        lldigit = tempNumber / pow(10, i);
        idigit = lldigit % 10;
        //Double every other digit
        if (i % 2 != 0)
        {
            idigit = idigit * 2;
        }
        //Add tens place digits together
        if (idigit > 9)
        {
            idigit = idigit - 9;
        }
        //Sum the numbers
        sum = sum + idigit;
    }
    // Check the card company
    if (sum % 10 == 0 && (first_digits == 34 || first_digits == 37))
    {
        printf("AMEX\n");
        return 0;
    }
    if (sum % 10 == 0 && first_digits >= 51 && first_digits <= 55)
    {
        printf("MASTERCARD\n");
        return 0;
    }
    if (sum % 10 == 0 && first_digits >= 40 && first_digits <= 49)
    {
        printf("VISA\n");
        return 0;
    }
    if (sum % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }
    else
    {
        printf("INVALID\n");
        return 0;
    }
}

