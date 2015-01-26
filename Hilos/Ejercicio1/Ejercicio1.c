#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

void * mensaje(char *cadena);

int main(){

	char cadena1[]="Hola";
	char cadena2[]="Mundo";

	pthread_t thd1, thd2;


	pthread_create(&thd1,NULL,(void*)mensaje, (void*) cadena1);
	sleep(1);
	pthread_create(&thd2,NULL,(void*)mensaje, (void*) cadena2);

	pthread_exit(NULL);

	pthread_join(thd1, NULL);
	pthread_join(thd2, NULL);

	exit(EXIT_SUCCESS);




	return 0;
}

void * mensaje(char *cadena)
{
	printf("%s\n", cadena);
}