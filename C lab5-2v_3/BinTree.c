#include "BinTree.h"
#include <stdio.h>

Node* getFreeNode(T value, Node *parent) {
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->left = tmp->right = NULL;
	tmp->data = value;
	tmp->parent = parent;
	return tmp;
}
void insert(Node **head, T value) {
	Node *tmp = NULL;
	Node *ins = NULL;

	if (*head == NULL) {
		*head = getFreeNode(value, NULL);
		return;
	}

	tmp = *head;
	while (tmp) {
		if (CMP_GT(value, tmp->data)) {
			if (tmp->right) {
				tmp = tmp->right;
				continue;
			}
			else {
				tmp->right = getFreeNode(value, tmp);
				return;
			}
		}
		else if (CMP_LT(value, tmp->data)) {
			if (tmp->left) {
				tmp = tmp->left;
				continue;
			}
			else {
				tmp->left = getFreeNode(value, tmp);
				return;
			}
		}
		else {
			exit(2);
		}
	}
}
void printTree(Node *root, const char *dir, int level) {
	if (root) {
		printf("lvl %d %s = %d\n", level, dir, root->data);
		printTree(root->left, "left", level + 1);
		printTree(root->right, "right", level + 1);
	}
}
T sumBT(Node* root)
{
	if (root == NULL)
		return 0;
	return (root->data + sumBT(root->left) + sumBT(root->right));
}
void clearTree(Node *root)
{
	if (root != NULL)
	{
		clearTree(root->left);
		clearTree(root->right);
		free(root);
	}
}