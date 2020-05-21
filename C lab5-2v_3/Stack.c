#include "Stack.h"
#include <stdio.h>

void push(Node_t **head, T i, T d)
{
	Node_t *tmp = (Node_t*)malloc(sizeof(Node_t));
	if (tmp == NULL) {
		exit(STACK_OVERFLOW);
	}
	tmp->next = *head;
	tmp->i = i;
	tmp->d = d;
	*head = tmp;
}
void pop(Node_t **head)
{
	Node_t *out;
	if ((*head) == NULL) {
		exit(STACK_UNDERFLOW);
	}
	out = *head;
	*head = (*head)->next;
	free(out);
}
void printStack(const Node_t* head)
{
	printf("stack >\n");
	while (head) {
		printf("Дерево:%d\tЗначение: %d\n", head->i, head->d);
		head = head->next;
	}
}
size_t getSize(const Node_t *head)
{
	size_t size = 0;
	while (head) {
		size++;
		head = head->next;
	}
	return size;
}
Node_t* createStack(T i, T d) {
	Node_t* tmp = (Node_t*)malloc(sizeof(Node_t));
	if (tmp == NULL) {
		exit(STACK_OVERFLOW);
	}
	tmp->next = NULL;
	tmp->d = d;
	tmp->i = i;
	return tmp;
}