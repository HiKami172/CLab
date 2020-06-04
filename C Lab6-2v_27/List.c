#include "List.h"

void push(Node **head, T data) {
	Node *tmp = (Node*)malloc(sizeof(Node));
	tmp->value = data;
	tmp->next = (*head);
	(*head) = tmp;
}


T pop(Node **head) {
	Node* prev = NULL;
	T val;
	if (head == NULL) {
		exit(-1);
	}
	prev = (*head);
	val = prev->value;
	(*head) = (*head)->next;
	free(prev);
	return val;
}


Node* getNth(Node* head, T n) {
	int counter = 0;
	while (counter < n && head) {
		head = head->next;
		counter++;
	}
	return head;
}


Node* getLast(Node *head) {
	if (head == NULL) {
		return NULL;
	}
	while (head->next) {
		head = head->next;
	}
	return head;
}


void pushBack(Node *head, T value) {
	Node *last = getLast(head);
	Node *tmp = (Node*)malloc(sizeof(Node));
	tmp->value = value;
	tmp->next = NULL;
	last->next = tmp;
}

Node* getLastButOne(Node* head) {
	if (head == NULL) {
		exit(-2);
	}
	if (head->next == NULL) {
		return NULL;
	}
	while (head->next->next) {
		head = head->next;
	}
	return head;
}

void popBack(Node **head) {
	Node *lastbn = NULL;
	if (!head) {
		exit(-1);
	}
	if (!(*head)) {
		exit(-1);
	}
	lastbn = getLastButOne(*head);
	if (lastbn == NULL) {
		free(*head);
		*head = NULL;
	}
	else {
		free(lastbn->next);
		lastbn->next = NULL;
	}
}

void insert(Node *head, unsigned n, T val) {
	unsigned i = 0;
	Node *tmp = NULL;
	while (i < n && head->next) {
		head = head->next;
		i++;
	}
	tmp = (Node*)malloc(sizeof(Node));
	tmp->value = val;
	if (head->next) {
		tmp->next = head->next;
	}
	else {
		tmp->next = NULL;
	}
	head->next = tmp;
}

T deleteNth(Node **head, T n) {
	if (n == 0) {
		return pop(head);
	}
	else {
		Node *prev = getNth(*head, n - 1);
		Node *elm = prev->next;
		T val = elm->value;

		prev->next = elm->next;
		free(elm);
		return val;
	}
}


void deleteList(Node **head) {
	while ((*head)->next) {
		pop(head);
		*head = (*head)->next;
	}
	free(*head);
}

void printLinkedList(const Node *head) {
    while (head) {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}