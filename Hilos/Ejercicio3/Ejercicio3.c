#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
/*
int main(int argc, char *argv[])
{

	if(argc<2)
	{
		printf("Numero de argumentos incorrectos\n");
		exit(-1);
	}

	int numero=atoi(argv[1]);

	
	int tiempo=0, resto=0;

	int i=0;

	pthread_t thd[10];
	
	tiempo=10/numero;
	resto=10%numero;

	printf("Tiempo: %d\n",tiempo);
	printf("Resto: %d\n",resto);

	if(resto==0)
	{
		for(i=0;i<tiempo;i++)
		{
			if(i==0)
			printf("Desde %d a %d\n",i,i+numero);
			else
			{
			printf("Variable devuelta hasta variable devuelta+numero\n");
			}
		}
	}








	return 0;
}*/