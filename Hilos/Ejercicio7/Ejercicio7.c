#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pthread.h>
#include <string.h>

struct estructura
{
	char cadena[30];
	int entero;
};

void *modificar(void * parametro);

int main()
{
	struct estructura * miestructura;
	int hebras=0;
	int i=0;

	printf("¿Cuantas hebras desea crear? ");
	scanf("%d",&hebras);

	miestructura=(struct estructura *)malloc(sizeof(struct estructura)*hebras);

	for (i=0;i<hebras;i++)
	{
		strcpy((miestructura[i].cadena), "Hola, soy una cadena");
		miestructura[i].entero=i;
	}


	pthread_t thd[hebras];

	for (i=0;i<hebras;i++)
	{
		pthread_create(&thd[i],NULL,(void*)modificar, (void*)&miestructura[i]);
	}

	for (i=0;i<hebras;i++)
	{
		pthread_join(thd[i],NULL);
	}	

	for (i=0;i<hebras;i++)
	{
		printf("Estructura %d, la cadena es %s y el entero %d\n", i, miestructura[i].cadena, miestructura[i].entero);
	}


	return 0;
}



void *modificar(void * parametro){


	struct estructura *aux;

	aux=(struct estructura*)parametro;

	aux->cadena[0]='a';
	aux->entero=(aux->entero)+1;


	pthread_exit(NULL);

}
