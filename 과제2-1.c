#include <stdio.h>
#include <stdlib.h>          
#include <time.h>            
#include "����2-1.h"

#define chicken		0;        
#define beer		1;
#define coke		2; 
#define beerset		3;	//chichen+beer
#define cokeset		4; 	//chichen*coke

#define oderterm 10		

#define chickTime	10	//�ֹ��� �ɸ��� �ð�
#define beerTime	4
#define cokeTime	3
#define beersetT	14
#define cokesetT	13

int main(void)
{
	int order = 0;
	int min = 0;	//�ð�

	int countchick = 0;
	int countbeer = 0;
	int countcoke = 0;
	int countsetb = 0;
	int countsetc = 0;
	
	Queue q;

	queueinit(&q);
	srand(time(NULL));

	for (min = 0; min < 4800; min++)//8�ð�
	{
		if (min % oderterm == 0){
			switch (rand() % 5){
			case 0:
				enqueue(&q, chickTime);
				countchick++;
				break;

			case 1:
				enqueue(&q, beerTime);
				countbeer++;
				break;

			case 2:
				enqueue(&q, cokeTime);
				countcoke++;
				break;

			case 3:
				enqueue(&q, beersetT);
				countsetb++;
				break;

			case 4:
				enqueue(&q, cokesetT);
				countsetc++;
				break;
			}
		}
		if (order <= 0 && !emptyqueue(&q))
			order = dequeue(&q);
		order--;
	}
	printf("\n�ֹ� ��Ȳ\n");
	printf(" ġŲ �ֹ��� ��� : %d \n", countchick);
	printf(" ���ָ� �ֹ��� ���: %d \n", countbeer);
	printf(" �ݶ� �ֹ��� ���: %d \n\n", countcoke);
	printf(" ġ�Ƽ�Ʈ �ֹ��� ���: %d \n", countsetb);
	printf(" ġ�ݼ�Ʈ �ֹ��� ���: %d \n", countsetc);

	return 0;
}

