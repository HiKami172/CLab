#ifndef LAB7_LIST_H
#define LAB7_LIST_H

#endif LAB7_LIST_H

#define bool int
#define true 1
#define false 0
#include <string.h>
#include <malloc.h>
#include <windows.h>

//Тайпдефы для преступления.
typedef char tPlace[20];
typedef char tParticipants[40];
typedef char tConsequences[20];
typedef char tSpecialists[40];



//Преступление.
struct Crime
{
	tPlace crimePlace;
	tParticipants participants;
	tConsequences consequences;
	tSpecialists commentary;

	struct Crime *prev, *next;
};

struct CrimeList
{
	int size;
	struct Crime *head, *tail;
};


//Функции для преступлений.

//Добавление.
void AddCrime(struct CrimeList *C, char *Place, char *Participants, char *Consequences, char *Commentary)
{
	struct Crime *temp;
	temp = (struct Crime*)malloc(sizeof(struct Crime));
	temp->prev = C->tail;
	temp->next = NULL;
	strcpy_s(temp->crimePlace, sizeof(temp->crimePlace), Place);
	strcpy_s(temp->participants, sizeof(temp->participants), Participants);
	strcpy_s(temp->consequences, sizeof(temp->consequences), Consequences);
	strcpy_s(temp->commentary, sizeof(temp->commentary), Commentary);

	if (C->tail)
		C->tail->next = temp;
	else
		C->head = C->tail;
	C->size++;
}

//Удаление
bool DeleteCrime(struct CrimeList *C, int position)
{
	if (position < 0 || position > C->size)
	{
		printf("Error.");
		return false;
	}
	else
	{
		struct Crime *temp = C->head;
		while (position--)
		{
			temp = temp->next;
		}

		if (temp != NULL)
		{
			if (temp->prev)
				temp->prev->next = temp->next;
			if (temp->next)
				temp->next->prev = temp->prev;
			free(temp);
			C->size--;
		}
		return true;
	}
}

//Очистка.
void RecoveredCrime(struct CrimeList *C)
{
	while (DeleteCrime(C, C->size - 1));
}

//Загрузка из файла.
void LoadCrime(struct CrimeList *C)
{
	FILE *file;
	RecoveredCrime(C);

	fopen_s(&file, "Crimes.txt", "r");
	if (!file)
		exit(1);
	else
	{
		char Place[20], Participants[20], Consequences[20], Commentary[40];
		while (fgets(Place, 20, file))
		{
			fgets(Participants, 20, file);
			fgets(Consequences, 20, file);
			fgets(Commentary, 40, file);
			AddCrime(C, Place, Participants, Consequences, Commentary);
		}
		fclose(file);
	}
}

//Загрузка в файл.
void SaveCrime(struct CrimeList *C)
{
	FILE *file;
	fopen_s(&file, "Crimes.txt", "w");

	if (!file)
		exit(1);

	struct Crime *temp = C->head;
	if (!temp)
		return;
	else
	{
		while (temp->next)
		{
			fputs(temp->crimePlace, file);
			fputs(temp->participants, file);
			fputs(temp->consequences, file);
			fputs(temp->commentary, file);
			temp = temp->next;
		}
		fputs(temp->crimePlace, file);
		fputs(temp->participants, file);
		fputs(temp->consequences, file);
		fputs(temp->commentary, file);

		fclose(file);
	}
}

//Вывод
void ShowCrimes(struct CrimeList *C)
{
	struct Crime *temp = C->head;
	if (!temp)
		return;
	else
	{
		while (temp->next)
		{
			puts(temp->crimePlace);
			puts(temp->participants);
			puts(temp->consequences);
			puts(temp->commentary);
			puts("\n");
			temp = temp->next;
		}
		puts(temp->crimePlace);
		puts(temp->participants);
		puts(temp->consequences);
		puts(temp->commentary);
		puts("\n\n");
	}
}

void PrintCrime(struct Crime *crime)
{
	puts(crime->crimePlace);
	puts(crime->participants);
	puts(crime->consequences);
	puts(crime->commentary);
	puts("\n");
}


//Поиск по преступлениям.
void SearchCrime(struct CrimeList *C, int parameter);
void SearchCrimePlace(struct CrimeList *C, char Place[]);
void SearchCrimeParticipants(struct CrimeList *C, char Person[]);
void SearchCrimeConsequence(struct CrimeList *C, char Consequence[]);

void SearchCrime(struct CrimeList *C, int parameter)
{
	switch (parameter)
	{
	case 1:
	{
			  char Place[20];
			  puts("Enter the place of crime to search:");
			  gets_s(Place, sizeof(Place));
			  SearchCrimePlace(C, Place);
	}

	case 2:
	{
			  char Participant[20];
			  puts("Enter the participant to search:");
			  gets_s(Participant, sizeof(Participant));
			  SearchCrimeParticipants(C, Participant);
	}

	case 3:
	{
			  char Consequence[20];
			  puts("Enter the consequence to search:");
			  gets_s(Consequence, sizeof(Consequence));
			  SearchCrimeConsequence(C, Consequence);
	}
	}
}

void SearchCrimePlace(struct CrimeList *C, char Place[])
{
	struct Crime *temp = C->head;
	if (!temp)
		return;
	else
	{
		while (temp->next)
		{
			if (!strcmp(temp->crimePlace, Place))
			{
				PrintCrime(temp);
				temp = temp->next;
			}
			else
				temp = temp->next;
		}
	}
}

void SearchCrimeParticipants(struct CrimeList *C, char Person[])
{
	struct Crime *temp = C->head;
	if (!temp)
		return;
	else
	{
		while (temp->next)
		{
			if (strstr(temp->participants, Person))
			{
				PrintCrime(temp);
				temp = temp->next;
			}
			else
				temp = temp->next;
		}
	}
}

void SearchCrimeConsequence(struct CrimeList *C, char Consequence[])
{
	struct Crime *temp = C->head;
	if (!temp)
		return;
	else
	{
		while (temp->next)
		{
			if (strstr(temp->consequences, Consequence))
			{
				PrintCrime(temp);
				temp = temp->next;
			}
			else
				temp = temp->next;
		}
	}
}

