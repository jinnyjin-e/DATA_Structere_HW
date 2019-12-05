#include <stdio.h>
#include <stdlib.h>  
#include <stdbool.h>

typedef struct node
{
	void*		dataPtr;
	struct node* next;

}Qnode;


typedef struct
{
	Qnode* front;                      
	Qnode* rear;                        
	int count;   
	int quearr[100];
} Queue;
#define Queuelenght 100;

Queue* createQueue(void);

int  dequeue(Queue* queue);
bool enqueue(Queue* queue, void* itemPtr);
bool queueinit(Queue* queue);
bool nextqueue(int pos);
bool emptyqueue(Queue* queue);

Queue* createQueue(void) {
	Queue* queue;
	queue = (Queue*)malloc(sizeof(Queue));
	if (queue) {
		queue->front	= NULL;
		queue->rear		= NULL;
		queue->count	= 0;
	}
	return queue;
}//queue 생성

bool enqueue(Queue* queue, void* itemPtr) {
	Qnode* newPtr;
	if (!(newPtr = (Qnode*)malloc(sizeof(Qnode))))
		return false;
	newPtr->dataPtr = itemPtr;
	newPtr->next = NULL;
	if (queue->count == 0)
		queue->front = newPtr;
	
	(queue->count)++;
	queue->rear = newPtr;
	return true;
}//enqueue

int dequeue(Queue* queue) {
	int a;
	if (emptyqueue(queue)) {
		printf("Queue Memory Empty!!");
		exit(-1);
	}
	queue->front = nextqueue(queue->front);
	a = queue->front;
	return queue->quearr[a];
}



bool emptyqueue(Queue* queue) {
	return(queue->count == 0);
}//queue가 비었는지

bool queueinit(Queue* queue) {
	queue->front = 0;
	queue->rear = 0;
}//큐초기화

bool nextqueue(int pos)
{
	if (pos == 100 - 1)
		return 0;

	else
		return pos + 1;
}

