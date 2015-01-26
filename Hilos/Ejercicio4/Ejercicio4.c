#include <stdio.h>
#include <pthread.h>
#include <sys/wait.h>
#include <errno.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

void * convertir (char *cadena);

int main(int argc, char *argv[])
{
	if(argc < 3)
	{
		printf("Argumentos invalidos...");
		exit(-1);	
	}
	char video1[20];
	strcpy(video1,argv[1]);
	char video2[20];
	strcpy(video2,argv[2]);


	
	pthread_t thd1, thd2;

	pthread_create(&thd1,NULL,(void*)convertir, (void*) video1);
	pthread_create(&thd2,NULL,(void*)convertir, (void*) video2);
	pthread_join(thd1,NULL);
	pthread_join(thd2,NULL);
	

	









	return 0;
}

void * convertir (char *video){

	char orden[190]="ffmpeg - i ";
	strcat(orden,video);
	strcat(orden," -f mp3 -ab 192000 -ar 48000 -vn ");
	
	strcat(orden,video);
	strcat(orden,".mp3");
	printf("Cambiando formato: %s\n", orden);
	system(orden);

	
}