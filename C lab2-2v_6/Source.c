//---------------------------------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS
#define MIN -35
#define MAX  35 // чем больше эти числа, тем меньше точность
#define true 1
#include <stdio.h>
#include <math.h>
#include <conio.h>
//---------------------------------------------------------------------------
double Check(char *funcpointer);
long double factorial(long double fact, double x, int n);

int main()
{
	int n = 1;
	long double fact;
	long double epsilon, SinX = 0;
	double x = Check("Please, Enter x: ");
	do
	{
		epsilon = Check("Please, Enter epsilon: ");
		if (epsilon < 0)
		{
			printf("Error: 0x51267, Incorrect input\n");
		}
	} while (epsilon < 0);
	fact = x;
	SinX = x;
	while ((SinX != sin(x)))
	{
		n++;
		fact = factorial(fact, x, 2 * n - 1);
		if (n % 2 == 1)
			SinX += fact;
		else
			SinX -= fact;

		if (fabs(sin(x) - SinX) < epsilon) break;
	}
	printf("%d\n", n);
	_getch();
	return 0;
}

long double factorial(long double fact, double x, int n)
{
	fact *= x*x / ((n - 1)*n);

	return fact;
}


double Check(char *funcpointer)
{
	double num;
	char temp = '\n';
	do
	{
		printf("%s", funcpointer);
		if (scanf("%lf%c", &num, &temp) == 2 && temp == '\n' && num > MIN && num < MAX)
		{
			break;
		}
		printf("Error: 0x51267, Incorrect input\n");
		rewind(stdin);
		_getch();
		system("cls");

	} while (true);
	return num;
}
//---------------------------------------------------------------------------