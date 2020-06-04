#include "Crime.h"

CrimeNode* createCrimeList() 
{
	CrimeNode* tmp = (CrimeNode*)malloc(sizeof(CrimeNode));
	Crime* crime = (Crime*)malloc(sizeof(Crime));
	tmp->crime = crime;
	tmp->next = tmp->prev = NULL;
	return tmp;
}

