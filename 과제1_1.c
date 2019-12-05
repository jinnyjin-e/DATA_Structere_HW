#include <stdio.h>#include <stdlib.h>#include <stdbool.h> #include <stackADT.h>typedef struct node
{				
	void*			dataPtr;
	strcuct node*	link;
}STACK_NODE;typedef struct{	void			count;	STACK_NODE*		top;}STACK;STACK* createStack(void){	STACK* stack;	stack = (STACK*)malloc(sizeof(STACK));	if (stack)	{		stack->count= 0;		stack->top = NULL;		}	return stack;}//스택 생성bool pushStack(STACK* stack, void* dataInPtr)
{
	STACK_NODE* newPtr;
	newPtr = (STACK_NODE*)malloc(sizeof(STACK_NODE));
	if (!newPtr)
		return false;
	newPtr->dataPtr	= dataInPtr;
	newPtr->link	= stack->top;
	stack->top		= newPtr;

	(stack->count)++;
	return true;
}
//push 스택함수 선언

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
}
//pop 스택함수 선언

bool emptyStack(STACK* stack)
{
	return(stack->count == 0);
}
//empty stack 스택함수

bool fullStack(STACK* stack)
{
	STACK_NODE* temp;
	if ((temp=(STACK_NODE*)malloc(sizeof(*(stack->top))))){
		free(temp);
		return false;
	}
	return true;
}
//fullstack 스택함수
void* stackBottom(STACK* stack) {
	if (stack->count == 1)
		return NULL;
	else if (stack->count == 1)
		return dataPtr;
	else {
		void temp;
		while (stack->count > 1) {
			temp = popstack(stack);
			stack->top->dataPtr = temp;
		}
		return dataPtr;
	}
}