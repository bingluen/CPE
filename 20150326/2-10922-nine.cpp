#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

bool isMultiple(int sum, int& degree);

int main()
{
    char digit;
    int sum = 0, degree = 0;
    while(digit = getchar())
    {
        if(digit - '0' == 0)
            break;

        

        if(digit != '\n')
        {
            printf("%c", digit);
            sum += (digit - '0');
        }

        else
        {
            if(isMultiple(sum, degree))
                printf(" is multiple of 9 and has 9-degree %d.\n", degree);
            else
                printf(" is not a multiple of 9.\n");
            sum = degree = 0;
        }

    }
    return 0;
}


bool isMultiple(int sum, int& degree)
{
    degree = 1;
    if(sum % 9 != 0)
        return false;
    else
    {

        int temp;
        while(sum > 9)
        {

            temp = sum;
            sum = 0;
            while(temp % 10)
            {
                sum += temp % 10;
                temp /= 10;
            }
            degree++;
        }
    }

    return true;
}
