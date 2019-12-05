#include<stdio.h>
#include<ctype.h>
#include<stdbool.h>
#include"과제3.h"

typedef struct {
	int id;
	int priority;
	int serial;
} VALUE;

const int maxqueue = 20;
int comparevalue(void* value1, void* value2);
void processQ(HEAP* heap);
char menu(void);
VALUE* getvalue(void);

int main(void) {
	HEAP* prqueue;

	printf("\n  Priority Queue Demonstaration을 시작합니다. \n");
	prqueue = heapcreat(maxqueue, comparevalue);
	processQ(prqueue);

	printf("\n  Priority Queue Demonstaration을 마칩니다.\n");
	return 0;
}
//메인 함수

int comparevalue(void* value1, void* value2) {
	VALUE v1;
	VALUE v2;
	v1 = *(VALUE*)value1;
	v2 = *(VALUE*)value2;
	if (v1.serial < v2.serial)
		return -1;
	else if (v1.serial == v2.serial)
		return 0;
	return +1;
}

	/*2번*/
void processQ(HEAP* prqueue) {
VALUE* value;
bool result;
char option;
int numvalue = 0;
	
do
	{
	option = menu();
	switch (option) 
		{
		case 'a':
			value = getvalue();
			numvalue++;
			value->serial = value->priority * 1000 + (1000 - numvalue);
			result = heapinsert(prqueue, value);
			if (!result) {
				printf(" 오류 : 정상적으로 힙에 넣지 못하였습니다. \n"),exit(101);
			}
			break;
		case 'b':
			result = heapdelete(prqueue, (void**)&value);
			if (!result)
				printf(" 오류 : 해당 고객을 찾지 못하였습니다.\n");
			else {
				printf("소비자 %4d를 정상적으로 삭제하였습니다.\n", value->id);
				numvalue--;
			}
		}	
	} while (option != 'c');
	return;
}

	/*3번*/
char menu(void) {
	char option;
	bool valid;

	printf("\n┌────── MENU ──────┐\n");
	printf("│  a : 새로운 고객 정보를 입력 │\n");
	printf("│  b : 저장된 고객 정보를 삭제 │\n");
	printf("│  c : 끝내기                  │\n");
	printf("└───────────────┘\n");
	printf("  메뉴의 번호를 선택해주세요 : ");

	do {
		scanf(" %c", &option);
		option = tolower(option);
		switch (option) {
		case 'a':
		case 'b':
		case 'c': valid = true;
				break;
		default : printf("  잘못된 값입니다. 다시 입력해주세요 : ");
				valid = false;
				break;
			}
		} while (!valid);
	return option;
}

VALUE* getvalue(void) {
	VALUE* value;
	value = (VALUE*)malloc(sizeof(VALUE));
	if (!value)
		printf("메모리가 초과되었습니다. \n"),exit(200);

	printf(" 고객 ID를 입력 하시오 : ");
	scanf(" %d ", &value->id);

	printf(" 고객 우선순위를 입력 하시오 : ");
	scanf(" %d ", &value->priority);
	return value;
}