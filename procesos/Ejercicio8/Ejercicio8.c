#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>

int global=0;

int main()
{
	pid_t pid;
	int estado;
	int hijos=0;
	int i=0;
	



	printf("¿Cuantos hijos desea? ");
	scanf ("%d", &hijos);

	for(i=0;i<hijos;i++)
	{
	pid=fork();

	if(pid==-1)
	{
		printf("Error en el fork\n");
		exit(EXIT_FAILURE);
	}

	else if(pid==0)
	{
		global++;
		exit(EXIT_SUCCESS);
	}

	if(pid>0)
	{
		printf("Soy el proceso padre y mi pid es: %d\n", getppid());
		sleep(2);
		while((pid=wait(&estado))>0)
		{
			pid=wait(&estado);

		}
	
	}

	}
printf("El valor de global es: %d\n", global);
}