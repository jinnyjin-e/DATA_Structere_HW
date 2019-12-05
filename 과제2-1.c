#include <stdio.h>
#include <stdlib.h>          
#include <time.h>            
#include "과제2-1.h"

#define chicken		0;        
#define beer		1;
#define coke		2; 
#define beerset		3;	//chichen+beer
#define cokeset		4; 	//chichen*coke

#define oderterm 10		

#define chickTime	10	//주문시 걸리는 시간
#define beerTime	4
#define cokeTime	3
#define beersetT	14
#define cokesetT	13

int main(void)
{
	int order = 0;
	int min = 0;	//시간

	int countchick = 0;
	int countbeer = 0;
	int countcoke = 0;
	int countsetb = 0;
	int countsetc = 0;
	
	Queue q;

	queueinit(&q);
	srand(time(NULL));

	for (min = 0; min < 4800; min++)//8시간
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
	printf("\n주문 현황\n");
	printf(" 치킨 주문한 사람 : %d \n", countchick);
	printf(" 맥주만 주문한 사람: %d \n", countbeer);
	printf(" 콜라만 주문한 사람: %d \n\n", countcoke);
	printf(" 치맥세트 주문한 사람: %d \n", countsetb);
	printf(" 치콜세트 주문한 사람: %d \n", countsetc);

	return 0;
}

