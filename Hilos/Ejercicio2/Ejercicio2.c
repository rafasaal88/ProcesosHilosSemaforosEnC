#include <pthread.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void *suma();

int main()
{

	int numhilos=0;
	int i=0;
	int total=0; 
	void *res;
	int aux;

	printf("¿Cuantos elementos aleatorios desea producir?: ");
	scanf("%d",&numhilos);

	pthread_t thd[numhilos];

	for (i=0;i<numhilos;i++)
	{
		pthread_create(&thd[i],NULL,(void*)suma,NULL);
		sleep(2);
	}

	for (i=0;i<numhilos;i++)
	{
		pthread_join(thd[i],(void **)&res);


		total=total+(*(int*)res);

		free(res);
	}

	printf("El resultado es %d\n",total);



	return 0;
}

void *suma(){

	srand(time(NULL));

	int num1=0,num2=0;
	int *suma;

	suma=(int *)malloc(sizeof(int));

	num1=rand()%100;
	num2=rand()%100;

	printf("El primer numero aleatorio es %d\n", num1);
	printf("El segundo numero aleatorio es %d\n", num2);

	*suma=num1+num2;

	printf("La suma de los dos es: %d\n", *suma);



	pthread_exit((void *) suma);

}
