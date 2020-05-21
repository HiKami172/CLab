#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <locale.h>
#include "Stack.h"
#include "BinTree.h"


T inputCheck(const char* info, T addCheck);
T treeAmount(const Node_t* head);

int main(void) 
{
	setlocale(LC_ALL, "rus");
	//=========================Создание и заполнение стека======================================================
	
	printf("Заполним стек данными:\n");
	Node_t* myStack = createStack(inputCheck("Введите номер дерева: ", 1), inputCheck("Введите значение: ", 0));
	system("cls");
	while (1)
	{
		int check = inputCheck("Продолжить ввод?(1 - да, 2 - нет)\n", 0);
		system("cls");
		if (check == 2)
			break;
		if (check == 1)
		{
			push(&myStack, inputCheck("Введите номер дерева: ", 1), inputCheck("Введите значение: ", 0));
			system("cls");
		}
		else
		{
			printf("Ошибка ввода!\nНажмите любую кнопку для продолжения...");
			_getch();
			system("cls");
		}
	}
	T trees = treeAmount(myStack);
	printf("Кол-во деревьев: %d\n", trees);
	printStack(myStack);
	
	//=========================Создание массива бинарных деревьев=============================================
	
	Node** treeArr = (Node**)malloc(trees * sizeof(Node*));
	for (int i = 0; i < trees; i++)
		treeArr[i] = NULL;

	//=========================Заполнение деревьев данными из стека и очистка стека===========================
	
	while (myStack) 
	{
		insert(&treeArr[myStack->i - 1], myStack->d);
		pop(&myStack);
	}

	//=========================Вывод бинарных деревьев в консоль==============================================

	for (int i = 0; i < trees; i++)
	{
		printf("\nДерево #%d:\n", i + 1);
		if (treeArr[i] == NULL)
		{
			printf("Пусто!\n");
			continue;
		}
		printTree(treeArr[i], "root", 0);
		printf("\n");
	}

	//=========================Подсчет и вывод суммы элементов бинарных деревьев==============================
	
	for (int i = 0; i < trees; i++)
		printf("Сумма элементов дерева #%d: %d\n", i + 1, sumBT(treeArr[i]));

	//=========================Очистка бинарных деревьев======================================================
	
	for (int i = 0; i < trees; i++)
		clearTree(treeArr[i]);
	free(treeArr);
	_getch();
	return 0;
}



T inputCheck(const char* info, T addCheck)
{
	T num;
	char temp = '\n';
	do
	{
		printf("%s", info);
		if (scanf("%d%c", &num, &temp) == 2 && temp == '\n')
		{
			if (!addCheck)
				break;
			if (num > 0)
				break;
		}
		printf("Ошибка ввода!\nНажмите любую кнопку для продолжения...");
		rewind(stdin);
		getchar();
		system("cls");
	} while (1);
	return num;
}
T treeAmount(const Node_t* head)
{
	T greatest = 1;
	while (head) {
		if (head->i > greatest)
			greatest = head->i;
		head = head->next;
	}
	return greatest;
}