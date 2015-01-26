#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *cuenta(char *fichero);

int main(int argc, char *argv[])
{

	if(argc<2)
	{
		printf("Numero de parametros incorrectos\n");
		exit(-1);
	}
	int i=0;
	int j=0;
	int elementos=argc-1;
	void *rest;
	int aux=0;

	

	

	
	
	char auxiliar[20];

	pthread_t thd[elementos];
		
	for(i=0;i<elementos;i++)
	{
		strcpy(auxiliar,argv[i+1]);
		pthread_create(&thd[i],NULL,(void*)cuenta,(void *)auxiliar);
		//printf ("Ejecutando %d\n",i);
		pthread_join(thd[i],&rest);
		aux=aux+rest;


	}	
	printf("Total: %d\n",aux);


	return 0;
}

void *cuenta(char *fichero)
{
	FILE *f=NULL; 
	int linea=0;
	char letra;
	printf("Fichero: %s\n", fichero);

	f=fopen(fichero,"r");

	if(f==NULL)
	{
		printf("El fichero %s no puede ser abierto o no existe\n", fichero);
		pthread_exit((int*)linea);
	}
	else{
	while((letra=(fgetc(f)))!=EOF)
	{
		if(letra=='\n')
		{
			linea++;
		}
	}
	fclose(f);
	printf("%d\n",linea);

	pthread_exit((int*)linea);
	}
}