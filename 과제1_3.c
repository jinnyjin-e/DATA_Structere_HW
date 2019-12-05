#include<stdio.h>
#include <stdbool.h> //�����Լ��� ���� ���� ����� ���Խ�Ŵ
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


//Convert Decimal Binary
int main(void) 
{
	unsigned	int num;
	int* digit;
	STACK* stack;

	stack = createStack();

	printf("Enter an integer:    ");
	scanf("%d", &num);

	while (num > 0) {
		digit = (int*)malloc(sizeof(int));
		*digit = num % 2;
		pushStack(stack, digit);
		num = num / 2;
	}
	printf("The binary number is :  ");
	while (!emptyStack(stack)) {
		digit = (int*)popStack(stack);
		printf("%1d", *digit);
	}
	printf("\n");
	destroyStack(stack);
	return 0;
}
