#include <string.h>
#include <malloc.h>
#include <windows.h>

typedef char tSurname[20];
typedef char tName[20];
typedef char tAlias[20];
typedef char tHairColor[20];
typedef char tSpecial[30];
typedef char tCitizenship[20];
typedef char tLanguages[30];
typedef char tCrime[25];
typedef char tOrganization[20];
typedef unsigned int tHeight;
typedef unsigned int tWeight;

//Преступник.
struct Criminal
{
	tSurname surname;
	tName name;
	tAlias Alias;
	tHeight height;
	tWeight weight;
	tHairColor hairColor;
	tSpecial signs;
	tCitizenship nationality;
	tLanguages languages;
	tCrime crimeType;
	tOrganization crimeOrganization;

	struct Criminal *prev, *next;
};

struct CriminalList
{
	int size;
	struct Criminal *head, *tail;
};

//Функции для преступников.

//Добавление
void AddCriminal(struct CriminalList *C, char* Surname, char* Name, char* Alias, unsigned int Height,
	unsigned int Weight, char* Color, char* Signs, char* Nationality, char* Languages, char* Crimes, char* Organizations)
{
	struct Criminal* newCrime;
	newCrime = (struct Criminal*)malloc(sizeof(struct Criminal));

	newCrime->prev = C->tail;
	newCrime->next = NULL;
	strcpy_s(newCrime->surname, sizeof(newCrime->surname), Surname);
	strcpy_s(newCrime->name, sizeof(newCrime->name), Name);
	strcpy_s(newCrime->Alias, sizeof(newCrime->Alias), Alias);
	newCrime->height = Height;
	newCrime->weight = Weight;
	strcpy_s(newCrime->hairColor, sizeof(newCrime->hairColor), Color);
	strcpy_s(newCrime->signs, sizeof(newCrime->signs), Signs);
	strcpy_s(newCrime->nationality, sizeof(newCrime->nationality), Nationality);
	strcpy_s(newCrime->languages, sizeof(newCrime->languages), Languages);
	strcpy_s(newCrime->crimeType, sizeof(newCrime->crimeType), Crimes);
	strcpy_s(newCrime->crimeOrganization, sizeof(newCrime->crimeOrganization), Organizations);

	if (C->tail)
		C->tail->next = newCrime;
	else
		C->head = C->tail;
	C->size++;
}

//Удаление
bool DeleteCriminal(struct CriminalList *C, int position)
{
	if (position < 0 || position > C->size)
	{
		printf("Error.");
		return false;
	}
	else
	{
		struct Criminal *temp = C->head;
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
void RecoveredCriminal(struct CriminalList *C)
{
	while (DeleteCriminal(C, C->size - 1));
}

//Загрузка из файла.
void LoadCriminal(struct CriminalList *C)
{
	FILE *file;
	RecoveredCriminal(C);

	fopen_s(&file, "Criminals.txt", "r");
	if (!file)
		exit(1);
	else
	{
		char Name[20], Surname[20], Alias[20], height[4], weight[4], Color[20], Signs[30], Nationality[20],
			Languages[30], Crimes[25], Organization[20];
		while (fgets(Surname, 20, file))
		{
			fgets(Name, 20, file);
			fgets(Alias, 20, file);
			fgets(height, 4, file);
			fgets(weight, 4, file);
			fgets(Color, 20, file);
			fgets(Signs, 30, file);
			fgets(Nationality, 20, file);
			fgets(Languages, 30, file);
			fgets(Crimes, 25, file);
			fgets(Organization, 20, file);
			fclose(file);
			AddCriminal(C, Name, Surname, Alias, atoi(height), atoi(weight), Color, Signs, Nationality, Languages, Crimes, Organization);
		}
	}
}

//Загрузка в файл
void SaveCriminal(struct CriminalList * C)
{
	FILE *file;
	fopen_s(&file, "Crime.txt", "w");
	struct Criminal *temp = C->head;

	if (!file || !(temp->next))
		exit(1);
	else
	{
		while (temp->next)
		{
			char weight[4], height[4];
			_itoa_s(temp->weight, weight, sizeof(weight), 10);
			_itoa_s(temp->height, height, sizeof(height), 10);

			fputs(temp->surname, file);
			fputs(temp->name, file);
			fputs(temp->Alias, file);
			fputs(height, file);
			fputs(weight, file);
			fputs(temp->hairColor, file);
			fputs(temp->signs, file);
			fputs(temp->nationality, file);
			fputs(temp->languages, file);
			fputs(temp->crimeType, file);
			fputs(temp->crimeOrganization, file);
			temp = temp->next;
		}
		fclose(file);
	}
}

//Вывод.
void ShowCriminals(struct CriminalList *C)
{
	struct Criminal *temp = C->head;
	char weight[4], height[4];
	while (temp->next)
	{
		_itoa_s(temp->weight, weight, sizeof(weight), 10);
		_itoa_s(temp->weight, weight, sizeof(weight), 10);
		puts(temp->name);
		puts(temp->surname);
		puts(temp->Alias);
		puts(height);
		puts(weight);
		puts(temp->hairColor);
		puts(temp->signs);
		puts(temp->nationality);
		puts(temp->languages);
		puts(temp->crimeType);
		puts(temp->crimeOrganization);
		temp = temp->next;
	}

	_itoa_s(temp->weight, weight, sizeof(weight), 10);
	_itoa_s(temp->weight, weight, sizeof(weight), 10);
	puts(temp->name);
	puts(temp->surname);
	puts(temp->Alias);
	puts(height);
	puts(weight);
	puts(temp->hairColor);
	puts(temp->signs);
	puts(temp->nationality);
	puts(temp->languages);
	puts(temp->crimeType);
	puts(temp->crimeOrganization);
	puts("\n\n");
}

void PrintCriminal(struct Criminal *person)
{
	char weight[4], height[4];
	_itoa_s(person->height, height, sizeof(height), 10);
	_itoa_s(person->weight, weight, sizeof(weight), 10);
	puts(person->name);
	puts(person->surname);
	puts(person->Alias);
	puts(height);
	puts(weight);
	puts(person->hairColor);
	puts(person->signs);
	puts(person->nationality);
	puts(person->languages);
	puts(person->crimeType);
	puts(person->crimeOrganization);
	puts("\n");
}


//Поиск по данным преступника.
void SearchCriminalSurname(struct CriminalList *C, char Surname[]);
void SearchCriminalName(struct CriminalList *C, char Name[]);
void SearchCriminalAlias(struct CriminalList *C, char Alias[]);
void SearchCriminalWeight(struct CriminalList *C, int Weight);
void SearchCriminalHeight(struct CriminalList *C, int Height);
void SearchCriminalColor(struct CriminalList *C, char Color[]);
void SearchCriminalFeature(struct CriminalList *C, char Feature[]);
void SearchCriminalNationality(struct CriminalList *C, char Nationality[]);
void SearchCriminalLanguages(struct CriminalList *C, char Language[]);
void SearchCriminalCrimes(struct CriminalList *C, char Crime[]);
void SearchCriminalOrganization(struct CriminalList *C, char Organization[]);



void SearchCriminal(struct CriminalList *C, int parameter)
{
	switch (parameter)
	{
	case 1:
	{
			  char Surname[20];
			  puts("Enter the surname to search for: ");
			  gets_s(Surname, sizeof(Surname));
			  SearchCriminalSurname(C, Surname);
			  break;
	}

	case 2:
	{
			  char Name[20];
			  puts("Enter the name to search for: ");
			  gets_s(Name, sizeof(Name));
			  SearchCriminalName(C, Name);
			  break;
	}

	case 3:
	{
			  char Alias[20];
			  puts("Enter the Alias to search for: ");
			  gets_s(Alias, sizeof(Alias));
			  SearchCriminalAlias(C, Alias);
			  break;
	}

	case 4:
	{
			  char Height[4];
			  puts("Enter the height to search for: ");
			  gets_s(Height, sizeof(Height));
			  SearchCriminalHeight(C, atoi(Height));
			  break;
	}

	case 5:
	{
			  char Weight[4];
			  puts("Enter the weight to search for: ");
			  gets_s(Weight, sizeof(Weight));
			  SearchCriminalWeight(C, atoi(Weight));
			  break;
	}

	case 6:
	{
			  char HairColor[20];
			  puts("Enter the hair color to search for: ");
			  gets_s(HairColor, sizeof(HairColor));
			  SearchCriminalColor(C, HairColor);
			  break;
	}

	case 7:
	{
			  char Feature[30];
			  puts("Enter the special sign to search for: ");
			  gets_s(Feature, sizeof(Feature));
			  SearchCriminalFeature(C, Feature);
			  break;
	}

	case 8:
	{
			  char Nationality[20];
			  puts("Enter the nationality to search for: ");
			  gets_s(Nationality, sizeof(Nationality));
			  SearchCriminalNationality(C, Nationality);
			  break;
	}

	case 9:
	{
			  char Language[30];
			  puts("Enter the language to search for: ");
			  gets_s(Language, sizeof(Language));
			  SearchCriminalLanguages(C, Language);
			  break;
	}

	case 10:
	{
			   char Crime[25];
			   puts("Enter the crime to search for: ");
			   gets_s(Crime, sizeof(Crime));
			   SearchCriminalCrimes(C, Crime);
			   break;
	}

	case 11:
	{
			   char Organization[20];
			   puts("Enter the organization to search for: ");
			   gets_s(Organization, sizeof(Organization));
			   SearchCriminalOrganization(C, Organization);
			   break;
	}

	default:
	{
			   break;
	}
	}
}

void SearchCriminalSurname(struct CriminalList *C, char Surname[])
{
	struct Criminal *temp = C->head;
	if (!temp)
		return;
	else
	{
		while (temp->next)
		{
			if (!strcmp(temp->surname, Surname))
			{
				PrintCriminal(temp);
				temp = temp->next;
			}
			else
				temp = temp->next;
		}
	}
}

void SearchCriminalName(struct CriminalList *C, char Name[])
{
	struct Criminal *temp = C->head;
	if (!temp)
		return;
	else
	{
		while (temp->next)
		{
			if (!strcmp(temp->name, Name))
			{
				PrintCriminal(temp);
				temp = temp->next;
			}
			else
				temp = temp->next;
		}
	}
}

void SearchCriminalAlias(struct CriminalList *C, char Alias[])
{
	struct Criminal *temp = C->head;
	if (!temp)
		return;
	else
	{
		while (temp->next)
		{
			if (!strcmp(temp->name, Alias))
			{
				PrintCriminal(temp);
				temp = temp->next;
			}
			else
				temp = temp->next;
		}
	}
}

void SearchCriminalWeight(struct CriminalList *C, int Weight)
{
	struct Criminal *temp = C->head;
	if (!temp)
		return;
	else
	{
		while (temp->next)
		{
			if ((temp->weight) == Weight)
			{
				PrintCriminal(temp);
				temp = temp->next;
			}
			else
				temp = temp->next;
		}
	}
}

void SearchCriminalHeight(struct CriminalList *C, int Height)
{
	struct Criminal *temp = C->head;
	if (!temp)
		return;
	else
	{
		while (temp->next)
		{
			if ((temp->height) == Height)
			{
				PrintCriminal(temp);
				temp = temp->next;
			}
			else
				temp = temp->next;
		}
	}
}

void SearchCriminalColor(struct CriminalList *C, char Color[])
{
	struct Criminal *temp = C->head;
	if (!temp)
		return;
	else
	{
		while (temp->next)
		{
			if (!strcmp(temp->hairColor, Color))
			{
				PrintCriminal(temp);
				temp = temp->next;
			}
			else
				temp = temp->next;
		}
	}
}

void SearchCriminalFeature(struct CriminalList *C, char Feature[])
{
	struct Criminal *temp = C->head;
	if (!temp)
		return;
	else
	{
		while (temp->next)
		{
			if (strstr(temp->signs, Feature))
			{
				PrintCriminal(temp);
				temp = temp->next;
			}
			else
				temp = temp->next;
		}
	}
}

void SearchCriminalNationality(struct CriminalList *C, char Nationality[])
{
	struct Criminal *temp = C->head;
	if (!temp)
		return;
	else
	{
		while (temp->next)
		{
			if (!strcmp(temp->nationality, Nationality))
			{
				PrintCriminal(temp);
				temp = temp->next;
			}
			else
				temp = temp->next;
		}
	}
}

void SearchCriminalLanguages(struct CriminalList *C, char Language[])
{
	struct Criminal *temp = C->head;
	if (!temp)
		return;
	else
	{
		while (temp->next)
		{
			if (strstr(temp->languages, Language))
			{
				PrintCriminal(temp);
				temp = temp->next;
			}
			else
				temp = temp->next;
		}
	}
}

void SearchCriminalCrimes(struct CriminalList *C, char Crime[])
{
	struct Criminal *temp = C->head;
	if (!temp)
		return;
	else
	{
		while (temp->next)
		{
			if (strstr(temp->crimeType, Crime))
			{
				PrintCriminal(temp);
				temp = temp->next;
			}
			else
				temp = temp->next;
		}
	}
}

void SearchCriminalOrganization(struct CriminalList *C, char Organization[])
{
	struct Criminal *temp = C->head;
	if (!temp)
		return;
	else
	{
		while (temp->next)
		{
			if (!strcmp(temp->crimeOrganization, Organization))
			{
				PrintCriminal(temp);
				temp = temp->next;
			}
			else
				temp = temp->next;
		}
	}
}