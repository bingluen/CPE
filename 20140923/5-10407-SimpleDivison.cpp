#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace::std;

int getMin(int *squence, int length);

int getAns(int *squence, int numSquenceNumber);

int main()
{
	int squences[1000][1000];
	int numSquence = 0;
	int numSquenceNumber[1000];
	while(true)
	{
		while(true)
		{
			cin >> squences[numSquence][numSquenceNumber[numSquence]];
			if(!squences[numSquence][numSquenceNumber[numSquence]])
				break;
			numSquenceNumber[numSquence]++;
		}
		if(!squences[numSquence][0])
			break;
		numSquence++;
	}
	//cout << "numSquence = " <<  numSquence << endl;
	for(int i = 0; i < numSquence; i++)
	{
		/* for(int j = 0; j < numSquenceNumber[i]; j++)
			cout << ","  << squences[i][j];
		cout << endl; */
		cout << getAns(squences[i], numSquenceNumber[i]) << endl;
	}
}

int getMin(int *squence, int length)
{
	int min = squence[0];
	for(int i = 1; i < length; i++)
		if(squence[i] > 0 && squence[i] < min)
			min = squence[i];
		else if(squence[i] < 0 && squence[i]*-1 < min)
			min = squence[i]*-1;


	return min;
}

int getAns(int *squence, int numSquenceNumber)
{
	int min = getMin(squence, numSquenceNumber);
	//cout << "min = " <<  min << endl;
	int ans = 0;
	for(int d = 0; d < min/2; d++)
	{
		for(int r = 2; r < d; r++)
		{
			int i;
			for(i = 0; i < numSquenceNumber; i++)
			{
				//if(d == 179) getchar();

				//cout << "r = " << r << ", d = " << d << ", number = "<< squence[i] << endl;
				//cout << "("<<  squence[i] << " - "<< r << " ) \%" << d <<  "= " << (squence[i] - r) % d << endl;
				//cout << "("<<  squence[i] << " + "<< r << " ) \%" << d <<  "= " << (squence[i] + r) % d << endl;

				if( (squence[i] - r) % d != 0  && (squence[i] + r) % d != 0 ) break;

			}
			if( i == numSquenceNumber )
				ans = d;
		}
	}
	return ans;
}
