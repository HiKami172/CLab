#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>


int InputCheck1(const char* info);
double InputCheck2(const char* info);
double DeterminatorCalc(double** matrix, int size);
void PrintMatrix(double** matrix, int size);
void GetMatrixWithoutRowAndCol(double **matrix, int size, int row, int col, double **newMatrix);


int main(void)
{
	setlocale(LC_CTYPE, "Rus");
	int size = 0;
	while (size <= 0)
		size = InputCheck1("Введите порядок матрицы: ");
	//============Создание единичной матрицы================
	double **unit = (double**)malloc(size * sizeof(double*));
	for (int i = 0; i < size; i++)
		unit[i] = (double*)malloc(size * sizeof(double));

	for (int i = 0; i < size; i++)
	for (int j = 0; j < size; j++)
		unit[i][j] = (i == j) ? 1 : 0;
	//============Создание пользовательской матрицы=========
	double **matrix = (double**)malloc(size * sizeof(double*));
	for (int i = 0; i < size; i++)
		matrix[i] = (double*)malloc(size * sizeof(double));

	for (int i = 0; i < size; i++)
	for (int j = 0; j < size; j++)
	{
		printf("matrix[%d][%d] ", i + 1, j + 1);
		matrix[i][j] = InputCheck2("Введите элемент:");
	}
	//=============Проверка на обратимость==================
	PrintMatrix(matrix, size);
	double det = DeterminatorCalc(matrix, size);
	printf("Определитель = %.2lf\n", det);
	if (det == 0)
	{
		printf("Определитель равен нулю. Матрица необратима!\n");
		_getch();
		return 0;
	}
	//=============Нахождение обратной матрицы==============
	for (int i = 0; i < size; i++) //Прямой ход
	{
		double solutionElement = matrix[i][i];
		for (int j = i + 1; j < size; j++)
		{
			double mult = -matrix[j][i] / solutionElement;
			for (int k = 0; k < size; k++)
			{
				matrix[j][k] += mult * matrix[i][k];
				unit[j][k] += mult * unit[i][k];
			}
		}
	}

	for (int i = size - 1; i > 0; i--) //Обратный ход
	{
		double solutionElement = matrix[i][i];
		for (int j = i - 1; j >= 0; j--)
		{
			double mult = -matrix[j][i] / solutionElement;
			for (int k = size - 1; k >= 0; k--)
			{
				matrix[j][k] += mult * matrix[i][k];
				unit[j][k] += mult * unit[i][k];
			}
		}
	}

	for (int i = 0; i < size; i++) //Двумя предыдущими шагами мы обнулили все элементы кроме главной диагонали. Теперь делим строки на эти элементы, чтобы привести матрицу к единичному виду
	{
		double solutionElement = matrix[i][i];
		if (solutionElement != 1)
			for (int j = 0; j < size; j++)
			{
				matrix[i][j] /= solutionElement;
				unit[i][j] /= solutionElement;
			}
	}
	//=============Вывод результата==================
	printf("Обратная матрица:\n");
	PrintMatrix(unit, size);
	for (int i = 0; i < size; i++)
		free(matrix[i]);
	free(matrix);
	for (int i = 0; i < size; i++)
		free(unit[i]);
	free(unit);
	_getch();
	return 0;
}
int InputCheck1(const char* info)
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
double InputCheck2(const char* info)
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
double DeterminatorCalc(double** matrix, int size)
{
	if (size == 1)
		return matrix[0][0];
	double det = 0;
	double **newMatrix = (double**)malloc((size - 1) * sizeof(double*));
	for (int i = 0; i < size - 1; i++)
		newMatrix[i] = (double*)malloc((size - 1) * sizeof(double));

	for (int i = 0; i < size; i++)
	{
		double element = matrix[0][i];
		GetMatrixWithoutRowAndCol(matrix, size, 0, i, newMatrix);
		if (i % 2 == 0)
			det += element * DeterminatorCalc(newMatrix, size - 1);
		else
			det -= element * DeterminatorCalc(newMatrix, size - 1);
	}
	for (int i = 0; i < size - 1; i++)
		free(newMatrix[i]);
	free(newMatrix);
	return det;
}
void GetMatrixWithoutRowAndCol(double **matrix, int size, int row, int col, double **newMatrix) {
	int offsetRow = 0;
	int offsetCol = 0; 
	for (int i = 0; i < size - 1; i++) {
		if (i == row) {
			offsetRow = 1;
		}
		offsetCol = 0;
		for (int j = 0; j < size - 1; j++) {
			if (j == col) {
				offsetCol = 1;
			}

			newMatrix[i][j] = matrix[i + offsetRow][j + offsetCol];
		}
	}
}
void PrintMatrix(double** matrix, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			printf("%.2lf\t", matrix[i][j]);
		printf("\n");
	}
}