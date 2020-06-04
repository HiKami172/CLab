#include "CrimeOrg.h"

CrimeOrgNode* createOrganizationList()
{
	CrimeOrgNode* tmp = (CrimeOrgNode*)malloc(sizeof(CrimeOrgNode));
	CrimeOrg* crimeOrg = (CrimeOrg*)malloc(sizeof(CrimeOrg));
	tmp->crimeOrg = crimeOrg;
	tmp->next = tmp->prev = NULL;
	return tmp;
}