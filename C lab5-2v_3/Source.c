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
	//=========================�������� � ���������� �����======================================================
	
	printf("�������� ���� �������:\n");
	Node_t* myStack = createStack(inputCheck("������� ����� ������: ", 1), inputCheck("������� ��������: ", 0));
	system("cls");
	while (1)
	{
		int check = inputCheck("���������� ����?(1 - ��, 2 - ���)\n", 0);
		system("cls");
		if (check == 2)
			break;
		if (check == 1)
		{
			push(&myStack, inputCheck("������� ����� ������: ", 1), inputCheck("������� ��������: ", 0));
			system("cls");
		}
		else
		{
			printf("������ �����!\n������� ����� ������ ��� �����������...");
			_getch();
			system("cls");
		}
	}
	T trees = treeAmount(myStack);
	printf("���-�� ��������: %d\n", trees);
	printStack(myStack);
	
	//=========================�������� ������� �������� ��������=============================================
	
	Node** treeArr = (Node**)malloc(trees * sizeof(Node*));
	for (int i = 0; i < trees; i++)
		treeArr[i] = NULL;

	//=========================���������� �������� ������� �� ����� � ������� �����===========================
	
	while (myStack) 
	{
		insert(&treeArr[myStack->i - 1], myStack->d);
		pop(&myStack);
	}

	//=========================����� �������� �������� � �������==============================================

	for (int i = 0; i < trees; i++)
	{
		printf("\n������ #%d:\n", i + 1);
		if (treeArr[i] == NULL)
		{
			printf("�����!\n");
			continue;
		}
		printTree(treeArr[i], "root", 0);
		printf("\n");
	}

	//=========================������� � ����� ����� ��������� �������� ��������==============================
	
	for (int i = 0; i < trees; i++)
		printf("����� ��������� ������ #%d: %d\n", i + 1, sumBT(treeArr[i]));

	//=========================������� �������� ��������======================================================
	
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
		printf("������ �����!\n������� ����� ������ ��� �����������...");
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