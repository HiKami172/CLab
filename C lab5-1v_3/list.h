#pragma once
#include "stdio.h"
#include "stdlib.h"
#include "conio.h"

typedef struct _node
{
	char ch;
	struct _node* prevNode;
	struct _node* nextNode;
}Node;

typedef struct _list
{
	struct _node* head;
	struct _node* tail;
	int size;
}List;

void Initializate(List* list);
void push_front(List* list, char ch);
void push_back(List* list, char ch);
void pop_front(List* list);
void pop_back(List* list);
void insert(List* list, int it, char ch);
Node at(List* list, int it);
void ListDestroy(List* list);