#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

using namespace std;


int main()
{
	while(true)
	{
		bool array[5000001] = { 0 };
		int originalPos, toPos, num;
		cin >> num;
		if(num == 0)
			break;
		for(int i = 0; i < num; i++)
		{	
			cin >> originalPos >> toPos;
			if(array[originalPos])
				array[originalPos] = false;
			else
				array[originalPos] = true;
			if(array[toPos])
				array[toPos] = false;
			else
				array[toPos] = true;
		}
		bool flag = false;
		for(int i = 1; i < 5000001; i++)
			if(array[i])
				flag = true;
		if(flag)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
	return 0;
}

