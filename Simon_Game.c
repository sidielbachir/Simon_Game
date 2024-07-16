#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
int main(void)
{
	char another_game='y';
	int sequence_length=0;
	int number=0;
	int counter=0;
	time_t seed=0;
	time_t time_taken=0;
	time_t now=0;
	bool correct=true;
	
	printf("HI,this a Simple Simon Game !!!");
	scanf("%c",&another_game);
	do
	{
		correct=true;
		counter=0;
		sequence_length=2;
		time_taken=clock();
		
	while(correct)
	{
		sequence_length += counter++%3 ==0;
		seed=time(NULL);
		now =clock();
		srand((unsigned int)seed);
		for(int i=1;i<=sequence_length;i++)
		printf(" %d",rand()%10);
		for(;clock()-now<CLOCKS_PER_SEC;) ;
		
		printf("\r    Now enter the sequence :");
		srand((unsigned int)seed);
		for(int i=1;i<=sequence_length;i++)
		{
			scanf(" %d",&number);
			if(number!=rand()%10)
			{
				correct=false;
				break;
			}
		}
		printf("%s\n",correct?"right!":"wrong!");
	}	
	
		time_taken= (clock()-time_taken)/CLOCKS_PER_SEC;
		printf("\n\nyour score is %d",--counter*100/time_taken);
		
		fflush(stdin);
		printf("\n\nAnother game? :");
		scanf(" %c",&another_game);
	}while(another_game=='y');
	
	return 0;
}