#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

void getAns(char (*word)[100], int numWord, char (*testWord)[100], int numTestWord);
void getAnagrams(char (*word)[100], int numWord, char *testWord);

int main()
{
	int timeExec;
	//char whitespace[2];
	char word[1000][100];
	char testWord[1000][100];
	int numWord = 0, numTestWord = 0;
	cin >> timeExec;
	//cin >> whitespace;
	for(int z = 0; z < timeExec; z++)
	{
		cin >> numWord;
		//printf("%d", numWord);
		for(int i = 0; i < numWord; i++)
		{
			cin >> word[i];
		}
		while(true)
		{
		
			cin >> testWord[numTestWord];
			if(strcmp(testWord[numTestWord], "END") == 0)
				break;
			numTestWord++;		
		}
		getAns(word, numWord, testWord, numTestWord);
	}	
	return 0;
}

void getAns(char (*word)[100], int numWord, char (*testWord)[100], int numTestWord)
{
	for(int i = 0; i < numTestWord; i++)
	{
		cout << "Anagrams for: " << testWord[i] << endl;
		getAnagrams(word, numWord, testWord[i]);
	}
}

void getAnagrams(char (*word)[100], int numWord, char *testWord)
{
	int counter = 0;
	for(int j = 0; j < numWord; j++)
	{
		int timeAlphabet[26] = {0};
		for(int i = 0; i < strlen(testWord); i++)
			timeAlphabet[testWord[i] - 'a']++;

		/* for debug
		for(int i = 0; i < 26; i++)
			printf("%c = %d, ", (char)(i+'a'), timeAlphabet[i]);
		cout << endl;
		*/

		for(int i = 0; i < strlen(word[j]); i++)
		{
			timeAlphabet[word[j][i] - 'a']--;
		}

		/* for debug
		for(int i = 0; i < 26; i++)
			printf("%c = %d, ", (char)(i+'a'), timeAlphabet[i]);
		cout << endl;
		*/

		int flag = 0;
		for(int i = 0; i < 26; i++)
			if(timeAlphabet[i] > 0)
				flag = 1;
		
		/* for debug 
		cout << "flag = " << flag << endl;
		*/
		if(flag == 0)
			printf("  %d) %s\n", ++counter, word[j]);

		/*getchar();*/
	}
	if(counter == 0)
		cout << "No anagrams for: " << testWord << endl;
}
