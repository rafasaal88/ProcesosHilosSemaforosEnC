#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

struct estructura
{
	float matriz [3][3];
	float escalar;
};


void *multiplica(void *parametro);


int main(){

	srand(time(NULL));


	struct estructura prueba1,prueba2;

	int i=0,j=0;
	int nFil=3,nCol=3;
		prueba1.escalar=rand()%10;
		prueba2.escalar=rand()%10;
		for (i=0;i<nFil;i++)
		{
			for (j = 0; j < nCol; j++)
			{
				prueba1.matriz[i][j]=rand()%10;
				prueba2.matriz[i][j]=rand()%10;
			}
		}
		printf("El escalar es: %f\n", prueba1.escalar);
		for (i=0;i<nFil;i++)
		{
			printf("\n");
			for (j = 0; j < nCol; j++)
			{
				printf("%f\t", prueba1.matriz[i][j]);
				
			}
		}
		printf("\n");
		printf("\nEl escalar es: %f\n", prueba2.escalar);
		for (i=0;i<nFil;i++)
		{
			printf("\n");
			for (j = 0; j < nCol; j++)
			{
				printf("%f\t", prueba2.matriz[i][j]);
				
			}
		}
		printf("\n");

		pthread_t thd1,thd2;

		pthread_create(&thd1,NULL,(void*)multiplica,(void*)&prueba1);
		pthread_create(&thd2,NULL,(void*)multiplica,(void*)&prueba2);

		pthread_join(thd1,NULL);
		pthread_join(thd2,NULL);

				


		printf("El escalar es: %f\n", prueba1.escalar);
		for (i=0;i<nFil;i++)
		{
			printf("\n");
			for (j = 0; j < nCol; j++)
			{
				printf("%f\t", prueba1.matriz[i][j]);
				
			}
		}
		printf("\n");
		printf("\nEl escalar es: %f\n", prueba2.escalar);
		for (i=0;i<nFil;i++)
		{
			printf("\n");
			for (j = 0; j < nCol; j++)
			{
				printf("%f\t", prueba2.matriz[i][j]);
				
			}
		}
		printf("\n");



	return 0;
}

void *multiplica(void *parametro)
{
	int i=0, j=0;
	struct estructura *datos;

	datos=(struct estructura *)parametro;

	int nFil=3,nCol=3;


	for (i=0;i<nFil;i++)
	{
		for (j = 0; j < nCol; j++)
		{
			datos->matriz[i][j]=datos->matriz[i][j]*datos->escalar;
		}
	}


	pthread_exit(NULL);
}
