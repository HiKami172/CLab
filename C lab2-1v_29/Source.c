#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include "locale.h"

typedef unsigned char bool;

void LengthWidthSet(double* length, double* width);
void WindowAmountSet(int* windowAmount);
void DoorAmountSet(int* doorAmount);
void WallpaperCostSet(double* wallpaperCost);
double AreaCalc(double length, double width, int windowAmount, int doorAmount);
int TubeAmountCalc(double area);
double WorkCostCalc(double wallpaperCost, int tubeAmount);
double parse1(const char* info);
int parse2(const char* info);


const double height = 2.6;
const double windowWidth = 2.15;
const double windowHeight = 1.5;
const double doorWidth = 0.9;
const double doorHeight = 2.05;
const double tubeWidth = 0.5;
const double tubeLength = 10;
const double glueCost = 2.5;
const int tubesPerGlue = 5;


int main()
{
	bool go = 1;
	bool lengthWidthB = 0, windowAmountB = 0, doorAmountB = 0, wallpaperCostB = 0, areaB = 0, tubeAmountB = 0, costB = 0;
	int windowAmount, doorAmount, tubeAmount;
	double length, width, wallpaperCost, area, cost;
	setlocale(LC_CTYPE, "Rus");
	while (go)
	{
		int choice;

		printf("Меню:\n");
		printf("1. Ввод длинны и ширины комнаты (м)\n");
		printf("2. Ввод количества окон\n");
		printf("3. Ввод количества дверных проемов\n");
		printf("4. Ввод стоимости обойной трубки ($)\n");
		printf("5. Расчет площади оклейки (кв. м)\n");
		printf("6. Расчет необходимого количества обойных трубок\n");
		printf("7. Расчет стоимости поклейки (с учетом клея)\n");
		printf("8. Выход из программы\n");
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1:
			LengthWidthSet(&length, &width);
			lengthWidthB = 1;
			areaB = 0;
			tubeAmountB = 0;
			costB = 0;
			break;
		case 2:
			WindowAmountSet(&windowAmount);
			windowAmountB = 1;
			areaB = 0;
			tubeAmountB = 0;
			costB = 0;
			break;
		case 3:
			DoorAmountSet(&doorAmount);
			doorAmountB = 1;
			areaB = 0;
			tubeAmountB = 0;
			costB = 0;
			break;
		case 4:
			WallpaperCostSet(&wallpaperCost);
			wallpaperCostB = 1;
			costB = 0;
			break;
		case 5:
			system("cls");
			if (!lengthWidthB)
			{
				printf("Длина и ширина комнаты неизвестны!");
				_getch();
				system("cls");
				break;
			}
			if (!windowAmountB)
			{
				printf("Кол-во окон неизвестно!");
				_getch();
				system("cls");
				break;
			}
			if (!doorAmountB)
			{
				printf("Кол-во дверей неизвестно!");
				_getch();
				system("cls");
				break;
			}
			if (areaB)
			{
				printf("Площадь оклейки: ");
				printf("%.2lf кв. м.", area);
				_getch();
				system("cls");
				break;
			}
			printf("Площадь оклейки: ");
			area = AreaCalc(length, width, windowAmount, doorAmount);
			areaB = 1;
			printf("%.2lf кв. м.", area);
			_getch();
			system("cls");
			break;
		case 6:
			system("cls");
			if (!areaB)
			{
				printf("Площадь не расчитана!");
				_getch();
				system("cls");
				break;
			}
			if (tubeAmountB)
			{
				printf("Кол-во обойных трубок: ");
				printf("%d", tubeAmount);
				_getch();
				system("cls");
				break;
			}
			printf("Кол-во обойных трубок: ");
			tubeAmount = TubeAmountCalc(area);
			tubeAmountB = 1;
			printf("%d", tubeAmount);
			_getch();
			system("cls");
			break;
		case 7:
			system("cls");
			if (!wallpaperCostB)
			{
				printf("Цена обойной трубки неизвестна!");
				_getch();
				system("cls");
				break;
			}
			if (!tubeAmountB)
			{
				printf("Кол-во обойных трубок не расчитано!");
				_getch();
				system("cls");
				break;
			}
			if (costB)
			{
				printf("Стоимость поклейки (с учетом клея): ");
				printf("%.2lf $", cost);
				_getch();
				system("cls");
				break;
			}
			printf("Стоимость поклейки (с учетом клея): ");
			cost = WorkCostCalc(wallpaperCost, tubeAmount);
			printf("%.2lf$", cost);
			_getch();
			system("cls");
			break;
		case 8:
			go = 0;
			break;
		}
	}

	return 0;
}


void LengthWidthSet(double *length, double *width)
{
	system("cls");
	*length = parse1("Введите длину комнаты (м): ");
	*width = parse1("Введите ширину комнаты (м): ");
	system("cls");
}

void WindowAmountSet(int *windowAmount)
{
	system("cls");
	*windowAmount = parse2("Введите кол-во окон: ");
	system("cls");
}

void DoorAmountSet(int *doorAmount)
{
	system("cls");
	*doorAmount = parse2("Введите кол-во дверей: ");
	system("cls");
}

void WallpaperCostSet(double *wallpaperCost)
{
	system("cls");
	*wallpaperCost = parse1("Введите стоимость обойной трубки ($): ");
	system("cls");
}

double AreaCalc(double length, double width, int windowAmount, int doorAmount)
{
	return (length + width)*height * 2 - (windowAmount*windowWidth*windowHeight) - (doorAmount*doorWidth*doorHeight);
}

int TubeAmountCalc(double area)
{
	int tubeAmount = 0;
	double left = area;
	while (left > 0)
	{
		left -= tubeWidth*tubeLength;
		++tubeAmount;
	}
	return tubeAmount;
}

double WorkCostCalc(double wallpaperCost, int tubeAmount)
{
	int glueAmount = (tubeAmount % 5 == 0) ? tubeAmount / 5 : 1 + tubeAmount / 5;
	return (wallpaperCost * tubeAmount + glueCost * glueAmount);
}

double parse1(const char* info)
{
	double num;
	char temp = '\n';
	do
	{
		printf("%s", info);
		if (scanf("%lf%c", &num, &temp) == 2 && temp == '\n')
		{
			break;
		}
		printf("Error: 0x51267, Incorrect input.\nPress any key to continue...");
		rewind(stdin);
		getchar();
		system("cls");
	} while (1);
	return num;
}

int parse2(const char* info)
{
	int num;
	char temp = '\n';
	do
	{
		printf("%s", info);
		if (scanf("%d%c", &num, &temp) == 2 && temp == '\n')
		{
			break;
		}
		printf("Error: 0x51267, Incorrect input.\nPress any key to continue...");
		rewind(stdin);
		getchar();
		system("cls");
	} while (1);
	return num;
}
