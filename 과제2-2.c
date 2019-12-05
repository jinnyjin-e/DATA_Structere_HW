#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include "과제2-2.h"

typedef struct customer		//고객 개인정보
{
	char name[40];
	char age[8];
	char phone[20];
	char grade[8];
	struct customer *next;
}list;

list *head, *rear;

void firstlist(void)
{
	head = (list*)malloc(sizeof(list));
	rear = (list*)malloc(sizeof(list));
	head->next = rear;
	rear->next = rear;
}

void input(void)	//고객 정보 삽입
{
	int count;
	list *list2;

	list2 = (list*)malloc(sizeof(list));

	printf("\n  - 고객의 정보를 입력하세요 \n");

	printf("\n     - 성명 : ");
	gets(list2->name);//이름 입력	
	printf("\n     - 나이 : ");
	gets(list2->age);//나이 입력
	printf("\n     - 전화번호 : ");
	gets(list2->phone);//전화번호 입력
	printf("\n     - 회원등급 : ");
	gets(list2->grade);//등급입력

	printf("\n  ※정상적으로 입력되었습니다\n");
	printf(" ━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n");


	list2->next = head->next;
	head->next = list2;
}

int delete(char *s) {
	list *list2;
	list *list3;
	list3 = head;
	list2 = list3->next;
	while (strcmp(s, list2->name) != 0 && list2 != rear)
	{
		list3 = list3->next;
		list2 = list3->next;
	}
	if (list2 == rear)
		return NULL;
	list3->next = list2->next;
	free(list2);
	printf("   - 고객에 대한 정보가 삭제되었습니다");
	printf("\n ━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n");

	return 1;
}//고객 삭제

list *search(char *s) {
	list *list2;
	list2 = head->next;
	while (strcmp(s, list2->name) != 0 && list2 != rear);
	list2 = list2->next;
	if (list2 == rear)
		return NULL;
	else
		return list2;
} //고객 탐색

void customerinfo(list *list)
{
	printf("\n     성명     : %s          나이     : %s ", list->name, list->age);
	printf("\n     전화번호 : %s         회원등급 : %s \n\n", list->phone, list->grade);
	printf(" ━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n");
}//고객 정보 표출

int menu(void)
{
	int i;
	char s[10];
	printf("\n ┌────────── 항  목 ───────────┐\n");
	printf(" │ 1. 입력      2. 삭제      3. 탐색      4. 끝내기 │\n");
	printf(" └─────────────────────────┘\n");

	do {
		printf("\n  *원하는 항목을 선택하시오  ");
		i = atoi(gets(s));
	} while (i < 0 || i>4);
	return i;
}//선택항목


void main()
{

	char name[40];
	int num;
	list *l;
	firstlist();
	while ((num = menu()) != 4)
	{
		switch (num)
		{
		case 1: 
			input();
			break;
		case 2: printf("\n  - 삭제할 고객의 정보를 입력하세요 : ");
			gets(name);
			if (!delete(name)) {
				printf("\n  - 등록되지 않은 고객입니다 \n\n");
				printf(" ━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n");
			}
			break;
		case 3: printf("\n  - 탐색할 고객의 이름을 입력하세요 : ");
			gets(name);
			l = search(name);
			if (!search(name)) {
				printf("\n  - 등록되지 않은 고객입니다 \n\n");
				printf(" ━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n");
			}
			else {
				customerinfo(l);
				break;
			}
		}
	}
}

