#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

const char* base_symbols = "0123456789ABCDEFGHIJKLMNOPQRASUVWXYZ";

char* ItoB(char* buffer, size_t number, size_t base) {
	size_t a_number = number;
	char* symbol;
	int string_size = 0;
	int i = 0;
	char flag = 1;
	size_t size = 32;
	if ((symbol = (char*)malloc(size)) == NULL)
		printf("Unable to allocate 32 bytes of memory for character buffer\n");

	int n = 0;
	while (flag)
	{
		do
		{
			symbol[i] = base_symbols[a_number % base];
			a_number /= base;
			++i;
			++string_size;
		} while (a_number != 0 && string_size < size);
		if (!a_number)
			flag = 0;
		else if (!(string_size < size))
		if ((symbol = (char*)realloc(symbol, size + 32)) == NULL)
		{
			printf("Unable to reallocate memory for character buffer\n");
			size += 32;
		}
	}
	symbol[i] = '\0';
	buffer = symbol;
	for (int i = 0; i < string_size / 2; ++i)
	{
		char temporary = buffer[i];
		buffer[i] = buffer[string_size - i - 1];
		buffer[string_size - i - 1] = temporary;
	}
	return buffer;
}

int main()
{

	char buffer[2048];
	int base;
	int num;
	printf("Set num = ");
	scanf_s("%d", &num);
	printf("\n");
	printf("Set base = ");
	scanf_s("%d", &base);
	printf("\n");
	if (base < 37)
		printf("%d in base %d = %s\n", num, base, ItoB(buffer, num, base));
	else
		printf("Unable to perform nums bigger than 36\nLook at \n'const char* base_symbols'\n^^^^^^^^^^^^^^^^^^^^^^^^^^ ");
	system("pause");
	return 0;

}

