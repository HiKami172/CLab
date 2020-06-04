#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Crimes.h"
#include "Criminals.h"
#include "Organizations.h"

void menu();
void cleanCrimes(struct CrimeList);
void cleanCriminals(struct CriminalList C);
void cleanOrganizations(struct OrganizationList C);

int main()
{
	struct CrimeList *crimeBase;
	crimeBase = (struct CrimeList*)malloc(sizeof(struct CrimeList));
	crimeBase->size = 0;
	crimeBase->head = crimeBase->tail = NULL;

	struct OrganizationList *orgBase;
	orgBase = (struct OrganizationList*)malloc(sizeof(struct OrganizationList));
	orgBase->size = 0;
	orgBase->head = orgBase->tail = NULL;

	struct CriminalList *criminalBase;
	criminalBase = (struct CriminalList*)malloc(sizeof(struct CriminalList));
	criminalBase->size = 0;
	criminalBase->tail = criminalBase->head = NULL;

	int decision = 0;
	while (decision != 6)
	{
		system("cls");
		menu();
		scanf_s("%d", &decision);
		switch (decision)
		{
			//Добавление.
		case 1:
		{
				  int choice = 0;
				  puts("Enter 1 to add criminal, 2 to add crime and 3 to add organization.");
				  scanf_s("%d", &choice);
				  switch (choice)
				  {
				  case 1:
				  {
							char Name[20], Surname[20], Alias[20], height[4], weight[4], Color[20], Signs[30], Nationality[20],
								Languages[30], Crimes[25], Organization[20];
							puts("Enter name: ");
							gets_s(Name, sizeof(Name));
							puts("Enter surname: ");
							gets_s(Surname, sizeof(Surname));
							puts("Enter alias: ");
							gets_s(Alias, sizeof(Alias));
							puts("Enter height: ");
							gets_s(height, sizeof(height));
							puts("Enter weight: ");
							gets_s(weight, sizeof(weight));
							puts("Enter hair color: ");
							gets_s(Color, sizeof(Color));
							puts("Enter special signs: ");
							gets_s(Signs, sizeof(Signs));
							puts("Enter nationality: ");
							gets_s(Nationality, sizeof(Nationality));
							puts("Enter languages: ");
							gets_s(Languages, sizeof(Languages));
							puts("Enter commited crimes: ");
							gets_s(Crimes, sizeof(Crimes));
							puts("Enter organizations: ");
							gets_s(Organization, sizeof(Organization));

							AddCriminal(criminalBase, Name, Surname, Alias, atoi(height), atoi(weight), Color, Signs, Nationality, Languages, Crimes, Organization);
							SaveCrime(crimeBase);
							break;
				  }
				  case 2:
				  {
							char Place[20], Participants[40], Consequences[20], Commentary[40];

							puts("Enter crime place: ");
							gets_s(Place, sizeof(Place));
							puts("Enter crime paticipants: ");
							gets_s(Participants, sizeof(Participants));
							puts("Enter crime consequences: ");
							gets_s(Consequences, sizeof(Consequences));
							puts("Enter specialists commentaries: ");
							gets_s(Commentary, sizeof(Commentary));

							AddCrime(crimeBase, Place, Participants, Consequences, Commentary);
							SaveCriminal(criminalBase);
							break;
				  }
				  case 3:
				  {
							char Name[20], Activity[25], Danger[20];

							puts("Enter organization name: ");
							gets_s(Name, sizeof(Name));
							puts("Enter type of activity: ");
							gets_s(Activity, sizeof(Activity));
							puts("Enter danger lvl: ");
							gets_s(Danger, sizeof(Danger));

							AddOrganization(orgBase, Name, Activity, Danger);
							SaveOrganization(orgBase);
							break;
				  }
				  default:
				  {
							 puts("Error!");
							 break;
				  }
				  }
		}
			break;
			//Удаление.
		case 2:
		{
				  puts(" Enter 1 to delete criminal, 2 to delete crime and 3 to delete organization.");
				  int deleter = 0;
				  scanf_s("%d", &deleter);
				  switch (deleter)
				  {
				  case 1:
				  {
							puts("Enter the position: ");
							int position = 0;
							scanf_s("%d", &position);
							DeleteCriminal(criminalBase, position);
							break;
				  }

				  case 2:
				  {
							puts("Enter the position: ");
							int position = 0;
							scanf_s("%d", &position);
							DeleteCrime(crimeBase, position);
							break;
				  }

				  case 3:
				  {
							puts("Enter the position: ");
							int position = 0;
							scanf_s("%d", &position);
							DeleteOrganization(orgBase, position);
							break;
				  }

				  default:
				  {
							 puts("Error!");
							 break;
				  }
				  }
		}
			break;
			//Вывод любой категории.
		case 3:
		{
				  puts("Enter 1 to see criminal list, 2 to see crime list and 3 to see organization list.");
				  int toShow = 0;
				  scanf("%d", &toShow);
				  switch (toShow)
				  {
				  case 1:
				  {
							LoadCriminal(criminalBase);
							ShowCriminals(criminalBase);
							break;
				  }

				  case 2:
				  {
							LoadCrime(crimeBase);
							ShowCrimes(crimeBase);
							break;
				  }

				  case 3:
				  {
							LoadOrganization(orgBase);
							ShowOrganizations(orgBase);
							break;
				  }

				  default:
				  {
							 puts("Error!");
							 break;
				  }
				  }
		}
			break;
			//Поиск с анализом.
		case 4:
		{
				  puts("Enter 1 to search for specified criminal, 2 to search for specified crime and 3 to search for specified organization.");
				  int search = 0;
				  scanf_s("%d", &search);
				  switch (search)
				  {
				  case 1:
				  {
							puts("Choose the category: ");
							int category = 0;
							scanf_s("%d", &category);
							SearchCriminal(criminalBase, category);
							break;
				  }

				  case 2:
				  {
							puts("Choose the category: ");
							int category = 0;
							scanf_s("%d", &category);
							SearchCrime(crimeBase, category);
							break;
				  }

				  case 3:
				  {
							puts("Choose the category: ");
							int category = 0;
							scanf_s("%d", &category);
							SearchOrganization(orgBase, category);
							break;
				  }

				  default:
				  {
							 puts("Error.");
							 break;
				  }
				  }
		}
			break;
		case 5:
		{
				  puts("Enter 1 to clear criminal list, 2 to clear crime list and 3 to clear organization list.");
				  int clean = 0;
				  scanf_s("%d", &clean);
				  switch (clean)
				  {
				  case 1:
				  {
							RecoveredCriminal(criminalBase);
							break;
				  }

				  case 2:
				  {
							RecoveredCrime(crimeBase);
							break;
				  }

				  case 3:
				  {
							RecoveredOrganization(orgBase);
							break;
				  }

				  default:
				  {
							 puts("Error.");
							 break;
				  }
				  }
				  break;
		case 6:
			break;

		default:
		{
				   puts("Error.");
				   break;
		}
		}
		}
	}
	free(crimeBase);
	free(criminalBase);
	free(orgBase);
}

void menu()
{
	puts("You can do the following: ");
	puts("1. Add another crime, criminal, organization.");
	puts("2. Delete crime, criminal or organization.");
	puts("3. Show all crimes, criminals or organizations.");
	puts("4. Search for some specific crime, criminal or organization.");
	puts("5. Clear the specific branch.");
	puts("6. Exit");
}

void cleanCrimes(struct CrimeList *C)
{
	struct Crime *temp = C->tail;
	while (temp->prev)
	{
		temp = temp->prev;
		free(temp->next);
	}
	free(temp);
}

void cleanCriminals(struct CriminalList *C)
{
	struct Criminal *temp = C->tail;
	while (temp->prev)
	{
		temp = temp->prev;
		free(temp->next);
	}
	free(temp);
}

void cleanOrganizations(struct OrganizationList *C)
{
	struct Organization *temp = C->tail;
	while (temp->prev)
	{
		temp = temp->prev;
		free(temp->next);
	}
	free(temp);
}