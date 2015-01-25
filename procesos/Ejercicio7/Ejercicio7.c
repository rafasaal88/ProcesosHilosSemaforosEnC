#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <errno.h>

int main()
{
	printf("Creando fichero.....\n");

	FILE *f;

	pid_t pid;
	int estado=0;


	f=fopen("fichero.txt","a");
	

	int i=0;

	for(i=0;i<2;i++)
	{
		pid=fork();


	if(pid==-1)
	{
		printf("Error en fork. Codigo: %d",errno);
		exit(-1);
	}

	else if(pid==0)
	{
		fputs("+++++",f);
		sleep(1);
	
		
		exit(EXIT_SUCCESS);
	}
	else if(pid>0)
	{
		
		fputs("-----",f);
	
		sleep(1);

	}

	}

	while((pid=wait(&estado))>0)
			{
				pid=wait(&estado);
				fclose(f);
			}






	return 0;
}