#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

long long unsigned int getAttackingPositionNum(int m, int n);

int main()
{
	long int number[2];
	while (cin >> number[0] >> number[1])
	{
		cout << getAttackingPositionNum(number[0], number[1]) << endl;
	}
}

unsigned long long int getAttackingPositionNum(int m, int n)
{

	unsigned long long int ans;
	if (m < n)
		swap(m, n);

	ans = m*(m - 1)*n + n*(n - 1)*m + (n*(n - 1)*(2 * n - 1) / 6 - (n - 1)*n / 2) * 4 + 2 * n*(n - 1)*(m - n + 1);

	
	return ans;
}