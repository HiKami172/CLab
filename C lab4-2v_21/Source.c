#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include "locale.h"

#define point '.'
#define space ' '

typedef unsigned char bool ;

const char* u_alp = "ÀÁÂÃÄÅ¨ÆÇÈÉÊËÌÍÎÏĞÑÒÓÔÕÖ×ØÙÚÛÜİŞß";
const char* l_alp = "àáâãäå¸æçèéêëìíîïğñòóôõö÷øùúûáışÿ";

bool isLetter(char temp)
{
	int i = 0;
	while (i < 33)
	{
		if (temp == u_alp[i] || temp == l_alp[i])
			return 1;
		++i;
	}
	return 0;
}

bool isUpper(char temp)
{
	int i = 0;
	while (i < 33)
	{
		if (temp == u_alp[i])
			return 1;
		++i;
	}
	return 0;
}

char toUpper(char ch)
{
	int i = 0;
	while (i < 33)
	{
		if (ch == l_alp[i])
			return u_alp[i];
		++i;
	}
}

void push(char* str, char ch, int* size, int i)
{
	if (i < size)
		str[i] = ch;
	else
	{
		if ((str = (char*)realloc(str, *size + 32)) == NULL)
		{
			printf("Unable to reallocate memory for character buffer\n");
			return;
		}
		*size += 32;
		str[i] = ch;
	}
}

int main()
{
	FILE* file;
	int temp, prev = 'M';
	int i = 0;
	bool newSentence = 1;
	char* str = NULL; size_t size = 32;
	if ((str = (char*)malloc(size)) == NULL)
		printf("Unable to allocate 32 bytes of memory for character buffer\n");
	setlocale(LC_CTYPE, "Rus");
	file = fopen("text.txt", "r");
	if (file != NULL)
	{
		while ((temp = fgetc(file)) != EOF)
		{
			if (temp == space)
			{
				if (prev == space)
				{
					--i;
				}
				else
					push(str, (char)temp, &size, i);
			}
			else if (temp == point)
			{
				push(str, (char)temp, &size, i);
				newSentence = 1;
			}
			else if (isLetter(temp))
			{
				if (newSentence)
				{
					if (isUpper(temp))
						push(str, (char)temp, &size, i);
					else
						push(str, toUpper(temp), &size, i);
					newSentence = 0;
				}
				else
					push(str, (char)temp, &size, i);
			}
			else
				push(str, (char)temp, &size, i);
			++i;
			prev = temp;
		}
		push(str, '\0', &size, i);
	}
	else
	{
		printf("Executional error, file does not exist");
	}
	printf("%s", str);
	_getch();
}
