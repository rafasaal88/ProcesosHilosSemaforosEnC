#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>

struct datos
{
	int escalar;
	int matriz[3][3];
};

void mostrarmatriz(struct datos dato);
void *multiplicar(void * dato);




int main()
{
	struct datos *dato;
	void *valor;
	srand(time(NULL));
	int i=0,j=0;
	pthread_t thd[2];

	dato=malloc(sizeof(struct datos)*2);




	dato[0].escalar=rand()%10;
	dato[1].escalar=rand()%10;

	printf("El primer escalar es: %d\n", dato[0].escalar);
	printf("El segundo escalar es: %d\n", dato[1].escalar);


	
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			dato[0].matriz[i][j]=rand()%10;
			dato[1].matriz[i][j]=rand()%10;
		}
	}

	for(i=0;i<2;i++)
	{
	mostrarmatriz(dato[i]);	
	printf("\n");
	}

	

	for(i=0;i<2;i++)
	{
	pthread_create(&thd[i],NULL,(void*)multiplicar,(void*) &dato[i]);

	pthread_join(thd[i],&valor);


	
	dato[i]=*(struct datos*)valor;	
	}

	for(i=0;i<2;i++)
	{
	mostrarmatriz(dato[i]);	
	printf("\n");
	}






return 0;
}









void *multiplicar(void* dato)
{

	struct datos * auxiliar=malloc(sizeof(struct datos));

	auxiliar=(struct datos *)dato;

	int i=0,j=0;

	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			(*auxiliar).matriz[i][j]=((*auxiliar).matriz[i][j])*((*auxiliar).escalar);
		}

	}



	pthread_exit((void*)auxiliar);
}

void mostrarmatriz(struct datos dato)
{
	int i=0,j=0;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d\t",dato.matriz[i][j]);
		}
		printf("\n");
	}

}