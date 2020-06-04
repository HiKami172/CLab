#include <stdlib.h>
#include <conio.h>
#include "Crime.h"
#include "CrimeOrg.h"
#include "Criminal.h"

#define true 1
#define false 0

int main(void)
{
	Crime* crimes = createCrimeList();
	CrimeOrg* organizations = createOrganizationList();
	Criminal* criminals = createCriminalList();

	/*while (true)
	{
		clrscr();

		printf("Find your worker or job\n1 - Add\n2 - Remove\n3 - View\n4 - Help\n5 - Search\n6 - Exit");
		switch (getch())
		{
		case '1': clrscr(); ChooseAdd(wrks, vcns); getch(); break;
		case '2': clrscr(); Remove(wrks, vcns); break;
		case '3': clrscr(); ChoosePrint(wrks, vcns); getch(); break;
		case '4': clrscr(); Help(); getch(); break;
		case '5': clrscr(); SearchFor(wrks, vcns); getch(); break;
		case '6': return;
		}

	}*/
	_gecth();
	return 0;
}