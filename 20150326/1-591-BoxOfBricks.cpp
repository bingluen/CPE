#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main()
{
    int size = 0, times = 0;
    while(cin >> size)
    {
        if(size <= 0)
            break;
        int count = 0, sum = 0, avgHeigh;
        int *bricks = new int[size];
        for(int i = 0; i < size; i++)
        {

            cin >> bricks[i];
            sum += bricks[i];
        }

        avgHeigh = sum / size;

        for(int i = 0 ; i < size; i++)
        {
            if(bricks[i] > avgHeigh)
                count += bricks[i] - avgHeigh;
        }

        cout << "set #" << ++times << endl;
        cout << "The minimum number of moves is " <<count << endl;
    }
}
