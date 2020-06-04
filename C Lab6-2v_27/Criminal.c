#include "Criminal.h"


CriminalNode* createCriminalList() 
{
	CriminalNode* tmp = (CriminalNode*)malloc(sizeof(CriminalNode));
	Crime* criminal = (Crime*)malloc(sizeof(Crime));
	tmp->criminal = criminal;
	tmp->next = tmp->prev = NULL;
	return tmp;
}