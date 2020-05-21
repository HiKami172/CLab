#include <stdlib.h>
#define CMP_EQ(a, b) ((a) == (b))
#define CMP_LT(a, b) ((a) < (b))
#define CMP_GT(a, b) ((a) > (b))

typedef int T;

typedef struct Node {
	T data;
	struct Node *left;
	struct Node *right;
	struct Node *parent;
} Node;

Node* getFreeNode(T value, Node *parent);
void printTree(Node *root, const char *dir, int level);
void insert(Node **head, T value);
T sumBT(Node* root);
void clearTree(Node *root);