#include <stdlib.h>
#define STACK_OVERFLOW  -100
#define STACK_UNDERFLOW -101
#define OUT_OF_MEMORY   -102

typedef int T;

typedef struct Node_tag {
	T d;
	T i;
	struct Node_tag *next;
} Node_t;

void push(Node_t **head, T i, T d);
void pop(Node_t **head);
void printStack(const Node_t* head);
size_t getSize(const Node_t *head);   
Node_t* createStack(T i, T d);