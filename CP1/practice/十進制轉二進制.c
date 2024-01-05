#include <stdio.h>
#pragma warning( disable : 4996 )
#include <math.h>
//#include <stdbool.h>
//#include <stdlib.h>
//#include <string.h>


long long convertDecimalToBinary(int n)
{
    long long binaryNumber = 0;
    int remainder, i = 1, step = 1;

    while (n != 0)
    {
        remainder = n % 2;
        n /= 2;
        binaryNumber += remainder * i;
        i *= 10;
    }
    return binaryNumber;
}


void convertDecimalToBinary_try(long int n)
{
    long int binaryNumber[1000];
    long int remainder, counter = 0;

    while (n != 0)
    {
        remainder = n % 2;
        binaryNumber[counter] = remainder;
        n /= 2;
        counter++;
    }

    for (long int i = counter - 1; i >= 0; i--)
    {
        printf("%li", binaryNumber[i]);
    }
    printf("\n");
}


void convertDecimalToBinary_try2(long int n)
{
    long int binaryNumber[1000];
    long int remainder, counter = 0;

    while (n != 0)
    {
        remainder = n % 2;
        binaryNumber[counter] = remainder;
        n /= 2;
        counter++;
    }

    if (counter == 0)
    {
        printf("0\n");
    }
    else
    {
        for (long int i = counter - 1; i >= 0; i--)
        {
            printf("%li", binaryNumber[i]);
        }
        printf("\n");
    }
   
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        long int decimalNum;
        //long long binaryNum;
        scanf("%li", &decimalNum);
        // printf("%lld\n", convertDecimalToBinary(decimalNum));
        convertDecimalToBinary_try2(decimalNum);
    }
    return 0;
}