#include <stdlib.h>

typedef struct
{
	char place[200];
	char involved[300];
	char consequences[300];
	char expertOpinion[500];
} Crime;

typedef struct CrimedNode
{
	Crime* crime;
	struct CrimeNode* next;
	struct CrimeNode* prev;
} CrimeNode;

CrimeNode* createCrimeList()