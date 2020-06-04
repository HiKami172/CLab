#include "Nationality.h"
#include "Language.h"
#include "Crime.h"
#include "CrimeOrg.h"
#include <stdlib.h>

typedef enum
{
	auburn,
	blonde,
	black,
	brown,
	red,
	gray,
	white,
	bald
} Hair;

typedef struct
{
	char fullName[50];
	char alias[20];
	float height;
	unsigned age;
	float weight;
	Hair hair;
	char specialSigns[150];
	Nationality nationality;
	Language speakLanguages[20];
	char crimeType[200];
	CrimeOrg* involvedInto[10];
	Crime* committeCrimes[100];
} Criminal;

typedef struct CriminalNode
{
	Criminal* criminal;
	struct CriminalNode* next;
	struct CriminalNode* prev;
} CriminalNode;

CriminalNode* createCriminalList();