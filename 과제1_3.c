#include<stdio.h>
#include <stdbool.h> //스택함수를 위해 다음 헤더를 포함시킴
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
}//스택 생성

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
}//push 스택함수 선언

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
}//pop 스택함수 선언

bool emptyStack(STACK* stack)
{
	return(stack->count == 0);
}//empty stack 스택함수

bool fullStack(STACK* stack)
{
	STACK_NODE* temp;
	if ((temp = (STACK_NODE*)malloc(sizeof(*(stack->top))))) {
		free(temp);
		return false;
	}
	return true;
}//fullstack 스택함수

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
}//bottom 스택함수 -과제1

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
}//destroy stack 스택함수
//@@@@@@@@@@@스텍함수(여기까지)@@@@@@@


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
