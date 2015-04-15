#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

int getNum(char keyword[][100], const int &numkey, char *excuses);

int main()
{
    int numKey, numExcuses, numTimes = 0;
    while(cin >> numKey >> numExcuses)
    {
        cin.ignore();
        char keyword[20][100], excuses[20][200], temp[100];
        int count[20] = {0};
        for(int i = 0; i < numKey; i++)
        {

            cin.getline(*(keyword + i), 100, '\n');
        }


        for(int i = 0; i < numExcuses; i++)
        {
            int size;
            cin.getline(*(excuses+i), 200, '\n');
            memcpy(temp, (excuses+i), 200);
            count[i] = getNum(keyword, numKey, temp);
        }

        
        /*check input
        
        for(int i = 0; i < numExcuses; i++)
        {
            cout << *(excuses+i) << endl;
        }
        */

        printf("\nExcuse Set #%d\n", ++numTimes);

        int max = 0;
        for(int i = 0; i < numExcuses; i++)
        {
            if(max < count[i])
                max = count[i];
        }

        for(int i = 0; i < numExcuses; i++)
        {
            if(count[i] == max)
                printf("count = %d, %s", count[i], *(excuses+i));
        }
        
    }
    return 0;
}

int getNum(char keyword[][100], const int &numkey, char *excuses)
{
    int count = 0;
    cout << endl << excuses << endl;
    cout << "\t";
    for(size_t i = 0; i < numkey; i++)
    {
        char *sPtr = strtok(excuses, " .?\'\"!&\n\t");

        while(sPtr != NULL)
        {
            cout << " " << sPtr << endl;
            if(!strcmp(sPtr, keyword[i]))
                count++;
            
            sPtr = strtok(NULL, " .?\'\"!&\n\t");
        }

    }

    return count;
}
