#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

struct estructura
{
	
	int entero;
	char cadena[20];
};

void *incrementa(void* datos);

int main()
{
	int elementos, i=0;
	printf("¿Cuantos hilos quiere?: ");
	scanf("%d", &elementos);
	void * retorno;
	struct estructura* datos;
	datos=malloc(sizeof(struct estructura)*elementos);

	pthread_t thd[elementos];


	for(i=0;i<elementos;i++)
	{
		datos[i].entero=5;
		strcpy((datos[i].cadena),"Esto es una cadena");
	}


	for(i=0;i<elementos;i++)
	{
		pthread_create(&thd[i],NULL,(void*) incrementa, (void*) &datos[i]);
		pthread_join(thd[i],&retorno);
		datos[i]=*(struct estructura*)retorno;
	}

	return 0;
}

void *incrementa(void* datos)
{

	struct estructura * auxiliar;
	auxiliar=malloc(sizeof(struct estructura));

	auxiliar=(struct estructura*)datos;


	(*auxiliar).cadena[0]='9';
	(*auxiliar).entero=((*auxiliar).entero)+1;

	pthread_exit((void*)auxiliar);

}