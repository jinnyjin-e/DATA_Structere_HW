#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include "����2-2.h"

typedef struct customer		//�� ��������
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

void input(void)	//�� ���� ����
{
	int count;
	list *list2;

	list2 = (list*)malloc(sizeof(list));

	printf("\n  - ���� ������ �Է��ϼ��� \n");

	printf("\n     - ���� : ");
	gets(list2->name);//�̸� �Է�	
	printf("\n     - ���� : ");
	gets(list2->age);//���� �Է�
	printf("\n     - ��ȭ��ȣ : ");
	gets(list2->phone);//��ȭ��ȣ �Է�
	printf("\n     - ȸ����� : ");
	gets(list2->grade);//����Է�

	printf("\n  ������������ �ԷµǾ����ϴ�\n");
	printf(" ������������������������������������������������������\n\n");


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
	printf("   - ���� ���� ������ �����Ǿ����ϴ�");
	printf("\n ������������������������������������������������������\n\n");

	return 1;
}//�� ����

list *search(char *s) {
	list *list2;
	list2 = head->next;
	while (strcmp(s, list2->name) != 0 && list2 != rear);
	list2 = list2->next;
	if (list2 == rear)
		return NULL;
	else
		return list2;
} //�� Ž��

void customerinfo(list *list)
{
	printf("\n     ����     : %s          ����     : %s ", list->name, list->age);
	printf("\n     ��ȭ��ȣ : %s         ȸ����� : %s \n\n", list->phone, list->grade);
	printf(" ������������������������������������������������������\n\n");
}//�� ���� ǥ��

int menu(void)
{
	int i;
	char s[10];
	printf("\n ���������������������� ��  �� ������������������������\n");
	printf(" �� 1. �Է�      2. ����      3. Ž��      4. ������ ��\n");
	printf(" ������������������������������������������������������\n");

	do {
		printf("\n  *���ϴ� �׸��� �����Ͻÿ�  ");
		i = atoi(gets(s));
	} while (i < 0 || i>4);
	return i;
}//�����׸�


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
		case 2: printf("\n  - ������ ���� ������ �Է��ϼ��� : ");
			gets(name);
			if (!delete(name)) {
				printf("\n  - ��ϵ��� ���� ���Դϴ� \n\n");
				printf(" ������������������������������������������������������\n\n");
			}
			break;
		case 3: printf("\n  - Ž���� ���� �̸��� �Է��ϼ��� : ");
			gets(name);
			l = search(name);
			if (!search(name)) {
				printf("\n  - ��ϵ��� ���� ���Դϴ� \n\n");
				printf(" ������������������������������������������������������\n\n");
			}
			else {
				customerinfo(l);
				break;
			}
		}
	}
}

