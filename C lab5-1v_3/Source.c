#include "list.h"

const char* l_alp = "abcdefghijklmnopqrstyvwxyz";
const char* u_alp = "ABCDEFGHIJKLMNOPQRASUVWXYZ";

typedef struct _string
{
	char* str;
	int size;
}String;

void input(String* string)
{
	char flag = 1;
	char* str = NULL; size_t size = 32;
	if ((str = (char*)malloc(size)) == NULL)
		printf("Unable to allocate 256 bytes of memory for character buffer\n");

	int n = 0;

	while (flag)
	{
		char ch = 'o';
		while (n < size && flag)
		{
			if (ch == 13)
			{
				flag = 0;
				str[n] = '\0';
				++n;
				break;
			}
			else
			{
				ch = _getch();
				str[n] = ch;
				printf("%c", str[n++]);
			}
		}

		if ((str = (char*)realloc(str, size + 32)) == NULL)
			printf("Unable to reallocate memory for character buffer\n");

		size += 32;
	}

	string->size = n - 2;
	string->str = str;
}

int main()
{
	int i;
	char isPalendrom = 1;
	List* list = malloc(sizeof(list));
	String* temp = malloc(sizeof(String));
	Initializate(list);
	input(temp);
	for (i = 0; i < temp->size; ++i)
	{
		if (temp->str[i] >= 'A' && temp->str[i] <= 'Z')
			push_back(list, temp->str[i] - 'A' + 'a');
		else if (temp->str[i] >= 'a' && temp->str[i] <= 'z')
			push_back(list, temp->str[i]);
	}
	for (i = 0; i < list->size / 2; ++i)
	{
		if (at(list, i).ch != at(list, list->size - 1 - i).ch)
			isPalendrom = 0;
	}
	if (!isPalendrom)
		printf("\nNot a pal");
	else
		printf("\nPalendrom");
	ListDestroy(list);
	_getch();
	return 0;
}
