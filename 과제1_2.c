#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#include "stacksADT.h"


typedef struct node
{
	void*			dataPtr;
	struct node*	link;
}STACK_NODE;

typedef struct
{
	int				count;
	STACK_NODE*		top;
}STACK;

STACK* createStack(void) {
	STACK* stack;
	stack = (STACK*)malloc(sizeof(STACK));
	if (stack)
	{
		stack->count = 0;
		stack->top = NULL;
	}
	return stack;
}//���� ����

bool pushStack(STACK* stack, void* dataInPtr)
{
	STACK_NODE* newPtr;
	newPtr = (STACK_NODE*)malloc(sizeof(STACK_NODE));
	if (!newPtr)
		return false;
	newPtr->dataPtr = dataInPtr;
	newPtr->link = stack->top;
	stack->top = newPtr;

	(stack->count)++;
	return true;
}//push �����Լ� ����

void* popStack(STACK* stack)
{
	void*		dataOutPtr;
	STACK_NODE* temp;
	if (stack->count == 0)
		dataOutPtr = NULL;
	else
	{
		temp = stack->top;
		dataOutPtr = stack->top->dataPtr;
		stack->top = stack->top->link;
		free(temp);
		(stack->count)--;
	}
	return dataOutPtr;
}//pop �����Լ� ����

bool emptyStack(STACK* stack)
{
	return(stack->count == 0);
}//empty stack �����Լ�

bool fullStack(STACK* stack)
{
	STACK_NODE* temp;
	if ((temp = (STACK_NODE*)malloc(sizeof(*(stack->top))))) {
		free(temp);
		return false;
	}
	return true;
}//fullstack �����Լ�

void* stackBottom(STACK* stack) {
	void* temp;

	if (stack->count == 0)
		return NULL;
	else {
		while (stack->count >= 1) {
			temp = popStack(stack);
		}
		return temp;
	}
}//bottom �����Լ� -����1

STACK* destroyStack(STACK* stack) {
	STACK_NODE* temp;
	if (stack) {
		while (stack->top != NULL) {
			free(stack->top->dataPtr);
			temp = stack->top;
			stack->top = stack->top->link;
			free(temp);
		}
		free(stack);
	}
	return NULL;
}//destroy stack �����Լ�
//@@@@@@@@@@@�����Լ�(�������)@@@@@@@


int main(void)
{
	STACK* stack;
	STACK* stack2;
	STACK* stack3;
	char token;
	char* dataPtr;
	char* dataPtr2;
	char* dataPtr3;
	char fileID[25];
	FILE* fpIn;
	int lineCount = 1;

	//stack ����
	stack = createStack();
	stack2 = createStack();
	stack3 = createStack();
	printf("Enter file ID for file to be parsed: ");
	scanf("%s", fileID);
	int check=0;//�������� ����

	fpIn = fopen(fileID, "r");
	if (!fpIn)
		printf("Error opening %s\n", fileID), exit(100);

	while ((token = fgetc(fpIn)) != EOF) {
		if (token == '\n')
			lineCount++;
		if (token == '(') {//�Ұ�ȣ
			dataPtr = (char*)malloc(sizeof(char));
			pushStack(stack, dataPtr);
		}
		else {
			if (token == ')') {
				if (emptyStack(stack)) {
					printf("%s %d\n", openMiss, lineCount);
					check = 1;//return�� ���� �ʾҴ�.
				}
				else
					popStack(stack);
			}
		}

		if (token == '{') {//�߰�ȣ
			dataPtr2 = (char*)malloc(sizeof(char));
			pushStack(stack2, dataPtr2);
		}
		else {
			if (token == '}') {
				if (emptyStack(stack2)) {
					printf("%s %d\n", openMiss2, lineCount);
					check = 2;//return�� ���� �ʾҴ�.
				}
				else
					popStack(stack2);
			}
		}
		if (token == '[') {//���ȣ
			dataPtr3 = (char*)malloc(sizeof(char));
			pushStack(stack3, dataPtr3);
		}
		else
		{
			if (token == ']') {
				if (emptyStack(stack3)) {
					printf("%s %d\n", openMiss3, lineCount);
					check = 3;//return�� ���� �ʾҴ�.
				}
				else
					popStack(stack3);
			}
		}
	}

	if (!emptyStack(stack)) {
		printf("%s %d\n", closMiss, lineCount);
		check = 4;//return�� ���� �ʾҴ�.
	}
	if (!emptyStack(stack2)) {
		printf("%s %d\n", closMiss2, lineCount);
		check = 5;//return�� ���� �ʾҴ�.
	}
	if (!emptyStack(stack3)) {
		printf("%s %d\n", closMiss3, lineCount);
		check = 6;//return�� ���� �ʾҴ�.
	}
	if (check>0)//��ȣ�� ¦�� �� ������ check=0
		return 1;
	
	destroyStack(stack);
	destroyStack(stack2);
	destroyStack(stack3);
	printf("Parsing is OK : %d Lines parsed. \n", lineCount);
	return 0;
}