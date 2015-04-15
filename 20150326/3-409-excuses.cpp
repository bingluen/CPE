#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

int getNum(char keyword[][100], const int &numkey, char *excuses);

int main()
{
    int numKey, numExcuses, numTimes = 0;
    while(scanf("%d %d", &numKey, &numExcuses))
    {
        char keyword[20][100], excuses[20][200], temp[100];
        int count[20] = {0};
        for(size_t i = 0; i < numKey; i++)
        {
            scanf("%s", *(keyword+i));
        }

        for(size_t i = 0; i < numExcuses; i++)
        {
            int size;
            cin.getline(*(excuses+i), 200);
            memcpy(temp, (excuses+i), 200);
            count[i] = getNum(keyword, numKey, temp);
        }

        printf("\nExcuse Set #%d\n", ++numTimes);

        int max = 0;
        for(size_t i = 0; i < numExcuses; i++)
        {
            if(max < count[i])
                max = count[i];
        }

        for(size_t i = 0; i < numExcuses; i++)
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
    //cout << endl << excuses << endl;
    for(size_t i = 0; i < numkey; i++)
    {
        cout << "Now key word is " << keyword[i] << endl;
        char *sPtr = strtok(excuses, " .?\'\"!&");

        while(sPtr != NULL)
        {
            if(!strcmp(sPtr, keyword[i]))
                count++;
            
            cout << sPtr << endl;
            sPtr = strtok(NULL, " .?\'\"!&");
        }

        cout << "=======================" << endl;
    }

    return count;
}
