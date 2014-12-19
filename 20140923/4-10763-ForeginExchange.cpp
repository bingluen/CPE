#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

using namespace std;

struct List
{
	struct Node *front;
	struct Node *end;
	int size;
};

struct Node
{
	int data;
	struct Node* next;
};

int isInList(struct List* list, int key);
void addNode(struct List* list, int data);
void deleteNode(struct List* list, int index);


void printList(struct List* list);


int main()
{
	clock_t start, finish;
	double duration;
	start = clock();
	while(true)
	{
		int originalPos, toPos, num, index;
		struct List *list = (struct List *) malloc(sizeof(struct List));
		list->size = 0;
		list->front = 0;
		list->end = 0;
		cin >> num;
		if(num == 0)
			break;
		for(int i = 0; i < num; i++)
		{	
			cin >> originalPos >> toPos;
			if(index = isInList(list, originalPos))
				deleteNode(list, index);
			else
				addNode(list, originalPos);
			
			/* printList(list); */

			if(index = isInList(list, toPos))
				deleteNode(list, index);
			else
				addNode(list, toPos);

			/* printList(list); */
		}
		if(list->size > 0)
			cout << "NO" << endl;
		if(list->size == 0)
			cout << "YES" << endl;
	}
	finish = clock();
	duration = (double) (finish - start) / CLOCKS_PER_SEC;
	cout << "time = " << duration << endl;
	return 0;
}

int isInList(struct List* list, int key)
{
	if(list->size == 0)
		return 0;

	int index = 0;
	struct Node *ptr;
	int i;
	for(i = 0, ptr = list->front; i < list->size; ptr = ptr->next, i++)
	{
		if(( ptr->data ) == key)
		{
			index = i + 1;
			break;
		}
	}
	return index;
}

void addNode(struct List* list, int data)
{

	if(list->size <= 0)
	{
		list->front = (struct Node *) malloc(sizeof(struct Node));
		list->end = list->front;
	}
	else
	{
		list->end->next = (struct Node *) malloc(sizeof(struct Node));
		list->end = list->end->next;
	}

	list->end->next = 0;
	list->end->data = data;
	list->size++;
}

void deleteNode(struct List* list, int index)
{
	/*printList(list);*/
	index--;
	struct Node *ptr, *pre;
	int i;
	for(i = 0, ptr = list->front;
		 i < index; 
		 ptr = ptr->next, i++)
		pre = ptr;
	if(index == 0)
		list->front = ptr->next;
	else if(index == list->size - 1)
		list->end = pre;
	else
		pre->next = ptr->next;

	list->size--;
	free(ptr);
	/* printList(list); */
}


/* for debug */
void printList(struct List* list)
{
	cout << "Size = " << list->size << ", front = " << list->front << " end = " << list->end << endl;
	struct Node* ptr = 0;
	int i = 0;
	for(i = 0, ptr = list->front;
		i < list->size;
		ptr = ptr->next, i++)
	{
		cout << ptr->data;
		if(i < list->size - 1)
			cout << " -> ";
	}
	cout << endl;
}
