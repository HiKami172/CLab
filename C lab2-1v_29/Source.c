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

		printf("����:\n");
		printf("1. ���� ������ � ������ ������� (�)\n");
		printf("2. ���� ���������� ����\n");
		printf("3. ���� ���������� ������� �������\n");
		printf("4. ���� ��������� ������� ������ ($)\n");
		printf("5. ������ ������� ������� (��. �)\n");
		printf("6. ������ ������������ ���������� ������� ������\n");
		printf("7. ������ ��������� �������� (� ������ ����)\n");
		printf("8. ����� �� ���������\n");
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
				printf("����� � ������ ������� ����������!");
				_getch();
				system("cls");
				break;
			}
			if (!windowAmountB)
			{
				printf("���-�� ���� ����������!");
				_getch();
				system("cls");
				break;
			}
			if (!doorAmountB)
			{
				printf("���-�� ������ ����������!");
				_getch();
				system("cls");
				break;
			}
			if (areaB)
			{
				printf("������� �������: ");
				printf("%.2lf ��. �.", area);
				_getch();
				system("cls");
				break;
			}
			printf("������� �������: ");
			area = AreaCalc(length, width, windowAmount, doorAmount);
			areaB = 1;
			printf("%.2lf ��. �.", area);
			_getch();
			system("cls");
			break;
		case 6:
			system("cls");
			if (!areaB)
			{
				printf("������� �� ���������!");
				_getch();
				system("cls");
				break;
			}
			if (tubeAmountB)
			{
				printf("���-�� ������� ������: ");
				printf("%d", tubeAmount);
				_getch();
				system("cls");
				break;
			}
			printf("���-�� ������� ������: ");
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
				printf("���� ������� ������ ����������!");
				_getch();
				system("cls");
				break;
			}
			if (!tubeAmountB)
			{
				printf("���-�� ������� ������ �� ���������!");
				_getch();
				system("cls");
				break;
			}
			if (costB)
			{
				printf("��������� �������� (� ������ ����): ");
				printf("%.2lf $", cost);
				_getch();
				system("cls");
				break;
			}
			printf("��������� �������� (� ������ ����): ");
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
	*length = parse1("������� ����� ������� (�): ");
	*width = parse1("������� ������ ������� (�): ");
	system("cls");
}

void WindowAmountSet(int *windowAmount)
{
	system("cls");
	*windowAmount = parse2("������� ���-�� ����: ");
	system("cls");
}

void DoorAmountSet(int *doorAmount)
{
	system("cls");
	*doorAmount = parse2("������� ���-�� ������: ");
	system("cls");
}

void WallpaperCostSet(double *wallpaperCost)
{
	system("cls");
	*wallpaperCost = parse1("������� ��������� ������� ������ ($): ");
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
