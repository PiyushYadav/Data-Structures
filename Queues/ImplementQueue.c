#include <stdio.h>
#include "Queues.h"

int main(){

	Queue *Q1=CreateQueue(5);
	int i=1;
	while(i <= 5){
		EnQueue(Q1,i);
		printf("front =%d rear=%d\n",Q1->front,Q1->rear);
		i++;
	}
	PrintQueue(Q1);
	i=0;
	while(i<3){
		DeQueue(Q1);
		printf("front =%d rear=%d\n",Q1->front,Q1->rear);
		i++;
	}
	PrintQueue(Q1);
	printf("\n");
	i=1;
	while(i<=3){
		EnQueue(Q1,i*5);
		printf("front =%d rear=%d\n",Q1->front,Q1->rear);
		i++;
	}
	printf("\n\n\n%d\n\n\n\n",Front(Q1));
	PrintQueue(Q1);
	printf("front =%d rear=%d\n",Q1->front,Q1->rear);
	return 0;

}
