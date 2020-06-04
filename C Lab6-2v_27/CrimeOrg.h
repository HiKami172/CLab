#include <stdlib.h>

typedef struct
{
	char name[20];
	char activity[100];
	int dangerLvl;
} CrimeOrg;

typedef struct CrimeOrgNode
{
	CrimeOrg* crimeOrg;
	struct CrimeOrgNode* next;
	struct CrimeOrgNode* prev;
} CrimeOrgNode;

CrimeOrgNode* createOrganizationList();