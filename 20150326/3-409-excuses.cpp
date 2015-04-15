#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

int getNum(char keyword[][100], const int &numkey, char *excuses);

char* toupperString(char *);

int main()
{
    int numKey, numExcuses, numTimes = 0;
    while(cin >> numKey >> numExcuses)
    {
        cin.ignore();
		char keyword[20][100] = { '\0' }, excuses[20][200] = { '\0' }, temp[200] = { '\0' };
        int count[20] = {0};
        for(int i = 0; i < numKey; i++)
        {

            cin.getline(*(keyword + i), 100, '\n');
        }

        for(int i = 0; i < numExcuses; i++)
        {
            cin.getline(*(excuses+i), 200, '\n');
            memcpy(temp, (excuses+i), 200);
            count[i] = getNum(keyword, numKey, temp);
        }

        

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
                printf("%s\n", *(excuses+i));
        }
        
    }
    return 0;
}

int getNum(char keyword[][100], const int &numkey, char *excuses)
{
    int count = 0;
	char *sPtr = strtok(excuses, " .?\'\"!&\n\t");
	
	while(sPtr != NULL)
	{
		for (int i = 0; i < numkey; i++)
		{
			if (!strcmp(sPtr, keyword[i]) || !strcmp(sPtr, toupperString(keyword[i])))
			{
				count++;
				break;
			}
		}
		sPtr = strtok(NULL, " .?\'\"!&\n\t");
	}
    return count;
}

char* toupperString(char *string)
{
	char *upperString = (char *)malloc((strlen(string)+1) * sizeof(char));

	for (size_t i = 0; i < strlen(string); i++)
	{
		if (string[i] >= 'a' && string[i] <= 'z')
		{
			upperString[i] = 'A' + (string[i] - 'a');
		} 
		else
		{
			upperString[i] = string[i];
		}
	}

	upperString[strlen(string)] = '\0';

	return upperString;
}
