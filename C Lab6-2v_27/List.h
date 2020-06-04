#include <stdlib.h>

typedef int T;

typedef struct Node {
	T value;
	struct Node *next;
} Node;


void push(Node **head, T data);
T pop(Node **head);
Node* getNth(Node* head, T n);
Node* getLast(Node *head);
void pushBack(Node *head, T value);
Node* getLastButOne(Node* head);
void popBack(Node **head);
void insert(Node *head, unsigned n, T val);
T deleteNth(Node **head, T n);
void deleteList(Node **head);
void printLinkedList(const Node *head);