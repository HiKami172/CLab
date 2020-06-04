#include <string.h>
#include <malloc.h>
#include <windows.h>

//Тайпдефы для организации.
typedef char tTitle[20];
typedef char tActivity[25];
typedef char tRating[20];


//Организация.
struct Organization
{
	tTitle name;
	tActivity occupation;
	tRating danger;

	struct Organization *prev, *next;
};

struct OrganizationList
{
	int size;
	struct Organization *head, *tail;
};

//Функции для организации.

//Добавление.
void AddOrganization(struct OrganizationList* C, char* Name, char* Activity, char* Danger)
{
	struct Organization *temp;
	temp = (struct Organization*)malloc(sizeof(struct Organization));
	temp->prev = C->tail;
	temp->next = NULL;

	strcpy_s(temp->name, sizeof(temp->name), Name);
	strcpy_s(temp->occupation, sizeof(temp->occupation), Activity);
	strcpy_s(temp->danger, sizeof(temp->danger), Danger);

	if (C->tail)
		C->tail->next = temp;
	if (!C->head)
		C->head = C->tail;
	C->size++;
}

//Удаление организации.
bool DeleteOrganization(struct OrganizationList* C, int position)
{
	if (position < 0 || position > C->size - 1)
		return false;

	struct Organization* temp = C->head;
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

//Очистка.
void RecoveredOrganization(struct OrganizationList *C)
{
	while (DeleteOrganization(C, C->size - 1));
}

//Загрузка из файла.
void LoadOrganization(struct OrganizationList *C)
{
	FILE *file;
	RecoveredOrganization(C);
	fopen_s(&file, "Organizations.txt", "r");

	if (!file)
		exit(1);
	else
	{
		char Name[20], Activity[25], Danger[20];
		while (fgets(Name, 20, file))
		{
			fgets(Activity, 25, file);
			fgets(Danger, 20, file);
			AddOrganization(C, Name, Activity, Danger);
		}
		fclose(file);
	}
}

//Загрузка в файл.
void SaveOrganization(struct OrganizationList *C)
{
	FILE *file;
	fopen_s(&file, "Organizations.txt", "w");

	if (!file)
		exit(1);
	else
	{
		struct Organization *temp = C->head;
		if (!temp)
			return;
		else
		{
			while (temp->next)
			{
				fputs(temp->name, file);
				fputs(temp->occupation, file);
				fputs(temp->danger, file);
				temp = temp->next;
			}
		}
		fputs(temp->name, file);
		fputs(temp->occupation, file);
		fputs(temp->danger, file);
		fclose(file);
	}
}

//Вывод
void ShowOrganizations(struct OrganizationList *C)
{
	struct Organization *temp = C->head;
	if (!temp)
		return;

	while (temp->next)
	{
		puts(temp->name);
		puts(temp->occupation);
		puts(temp->danger);
		temp = temp->next;
	}
	puts(temp->name);
	puts(temp->occupation);
	puts(temp->danger);
	puts("\n\n");
}

void PrintOrganization(struct Organization *org)
{
	puts(org->name);
	puts(org->occupation);
	puts(org->danger);
	puts("\n");
}

//Поиск по организациям.
void SearchOrgName(struct OrganizationList *C, char Name[]);
void SearchOrgActivity(struct OrganizationList *C, char Activity[]);
void SearchOrgRating(struct OrganizationList *C, char Rating[]);

void SearchOrganization(struct OrganizationList* C, int parameter)
{
	switch (parameter)
	{
	case 1:
	{
			  char Name[20];
			  puts("Enter the name to search for: ");
			  gets_s(Name, sizeof(Name));
			  SearchOrgName(C, Name);
			  break;
	}

	case 2:
	{
			  char Activity[20];
			  puts("Enter the activity to search for: ");
			  gets_s(Activity, sizeof(Activity));
			  SearchOrgActivity(C, Activity);
			  break;
	}

	case 3:
	{
			  char Rating[20];
			  puts("Enter the rating to search for: ");
			  gets_s(Rating, sizeof(Rating));
			  SearchOrgRating(C, Rating);
	}

	}
}

void SearchOrgName(struct OrganizationList *C, char Name[])
{
	struct Organization *temp = C->head;
	if (!temp)
		return;
	else
	{
		while (temp->next)
		{
			if (!strcmp(temp->name, Name))
			{
				PrintOrganization(temp);
				temp = temp->next;
			}
			else
				temp = temp->next;
		}
	}
}

void SearchOrgActivity(struct OrganizationList *C, char Activity[])
{
	struct Organization *temp = C->head;
	if (!temp)
		return;
	else
	{
		while (temp->next)
		{
			if (strstr(temp->occupation, Activity))
			{
				PrintOrganization(temp);
				temp = temp->next;
			}
			else
				temp = temp->next;
		}
	}
}

void SearchOrgRating(struct OrganizationList *C, char Rating[])
{
	struct Organization *temp = C->head;
	if (!temp)
		return;
	else
	{
		while (temp->next)
		{
			if (!strcmp(temp->danger, Rating))
			{
				PrintOrganization(temp);
				temp = temp->next;
			}
			else
				temp = temp->next;
		}
	}
}