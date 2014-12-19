#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

int getDiePoint(int* die, int *commands, int numCommand, int step);

int getDirection(char* directionWord);

int main()
{	
	int timeToExec = 0;
	int numCommand[100] = { 0 };
	int commands[100][1024];
	while(true)
	{
		cin >> numCommand[timeToExec];
		if(numCommand[timeToExec] <= 0)
			break;
		for(int i = 0; i < numCommand[timeToExec]; i++)
		{
			char input[10];
			cin >> input;
			commands[timeToExec][i] = getDirection(input);
		}
		timeToExec++;
	}

	for(int i = 0; i < timeToExec; i++)
	{
		int die[] = { 1, 2, 4, 5, 3, 6 };
		printf("%d\n", getDiePoint(die, commands[i], numCommand[i], 0));
	}

	return 0;	
}

int getDirection(char* directionWord)
{
	if(strcmp("north", directionWord) == 0)
		return 1;
	if(strcmp("east", directionWord) == 0)
		return 2;
	if(strcmp("south", directionWord) == 0)
		return 3;
	if(strcmp("west", directionWord) == 0)
		return 4;
	
	return -1;
}

int getDiePoint(int* die, int *commands, int numCommand, int step)
{
	if(step >= numCommand)
		return die[0];
	
	int tempDie[6];
	for(int i = 0; i < 6; i++)
		tempDie[i] = die[i];
//	cout << "command is " << commands[step] << endl;
	
//	printf ("before roll:top = %d, north = %d, east = %d, south = %d, west = %d, bottom = %d\n ", die[0], die[1], die[2], die[3], die[4], die[5]);
	switch(commands[step])
	{
	case 1:
		die[0] = tempDie[3];
		die[1] = tempDie[0];
		die[2] = tempDie[2];
		die[3] = tempDie[5];
		die[4] = tempDie[4];
		die[5] = tempDie[1];
		break;
	case 2:
		die[0] = tempDie[4];
		die[1] = tempDie[1];
		die[2] = tempDie[0];
		die[3] = tempDie[3];
		die[4] = tempDie[5];
		die[5] = tempDie[2];
		break;
	case 3:
		die[0] = tempDie[1];
		die[1] = tempDie[5];
		die[2] = tempDie[2];
		die[3] = tempDie[0];
		die[4] = tempDie[4];
		die[5] = tempDie[3];
		break;
	case 4:
		die[0] = tempDie[2];
		die[1] = tempDie[1];
		die[2] = tempDie[5];
		die[3] = tempDie[3];
		die[4] = tempDie[0];
		die[5] = tempDie[4];	
		break;
	}
	getDiePoint(die, commands, numCommand, step + 1);	
}
