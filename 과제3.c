#include<stdio.h>
#include<ctype.h>
#include<stdbool.h>
#include"����3.h"

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

	printf("\n  Priority Queue Demonstaration�� �����մϴ�. \n");
	prqueue = heapcreat(maxqueue, comparevalue);
	processQ(prqueue);

	printf("\n  Priority Queue Demonstaration�� ��Ĩ�ϴ�.\n");
	return 0;
}
//���� �Լ�

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

	/*2��*/
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
				printf(" ���� : ���������� ���� ���� ���Ͽ����ϴ�. \n"),exit(101);
			}
			break;
		case 'b':
			result = heapdelete(prqueue, (void**)&value);
			if (!result)
				printf(" ���� : �ش� ���� ã�� ���Ͽ����ϴ�.\n");
			else {
				printf("�Һ��� %4d�� ���������� �����Ͽ����ϴ�.\n", value->id);
				numvalue--;
			}
		}	
	} while (option != 'c');
	return;
}

	/*3��*/
char menu(void) {
	char option;
	bool valid;

	printf("\n�������������� MENU ��������������\n");
	printf("��  a : ���ο� �� ������ �Է� ��\n");
	printf("��  b : ����� �� ������ ���� ��\n");
	printf("��  c : ������                  ��\n");
	printf("����������������������������������\n");
	printf("  �޴��� ��ȣ�� �������ּ��� : ");

	do {
		scanf(" %c", &option);
		option = tolower(option);
		switch (option) {
		case 'a':
		case 'b':
		case 'c': valid = true;
				break;
		default : printf("  �߸��� ���Դϴ�. �ٽ� �Է����ּ��� : ");
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
		printf("�޸𸮰� �ʰ��Ǿ����ϴ�. \n"),exit(200);

	printf(" �� ID�� �Է� �Ͻÿ� : ");
	scanf(" %d ", &value->id);

	printf(" �� �켱������ �Է� �Ͻÿ� : ");
	scanf(" %d ", &value->priority);
	return value;
}