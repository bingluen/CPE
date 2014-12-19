#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

float getAngle(int hh, int mm);

int main()
{
	while(true)
	{
		int hh, mm;
		char input[6];
		char *ptr;
		cin >> input;
		ptr = strtok( input, ":");
		hh = atoi( ptr );
		ptr = strtok( NULL, ":");
		mm = atoi( ptr );
		if(hh  >= 1 && hh <= 12 && mm >=0 && mm <= 60)
		printf("%.3f\n", getAngle(hh, mm));
	}
	return 0;
}

float getAngle(int hh, int mm)
{
	float mmPos, hhPos;
	mmPos = 360 / 60 * mm;
	hhPos = 360 / 12 * hh + 360 / 12 / 60.0 * mm;
	if(hhPos - mmPos > 180)
		return 360 - (hhPos - mmPos);
	if(hhPos - mmPos < 0)
		return 180 + (hhPos - mmPos);
	return hhPos - mmPos;
}
