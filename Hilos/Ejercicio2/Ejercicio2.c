#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

void *suma();


int main(){

	int elementos=0;
	void *res;
	int i=0;
	int total=0;
	

	printf("Introduzca el numero de hebras que desea: ");
	scanf("%d",&elementos);

	pthread_t thd[elementos];
	

	for (i=0;i<elementos;i++)
	{
		pthread_create(&thd[i],NULL,(void*) suma, NULL);

	
		
	}

	
	for (i=0;i<elementos;i++)
	{
		

		
		pthread_join(thd[i],&res);
		
		printf("%d\n",res);
		total=total+res;

	}
	printf("%d\n",total);
	//printf("El total de las sumas parciales es: %d\n", suma);
	return 0;
}

void *suma()
{
	srand(time(NULL));

	int num1=0;
	int num2=0;

	num1=rand()%100;
	printf("El primer numero aleantorio es: %d\n", num1);
	num2=rand()%100;
	printf("El segundo numero aleantorio es: %d\n", num2);

	num1=num1+num2;

	pthread_exit((int *)num1);
}