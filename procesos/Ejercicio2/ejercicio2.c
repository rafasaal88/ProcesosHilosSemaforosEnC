#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <errno.h>

void procesohijo(int i);

int main ()
{

	pid_t pid;

	int procesos=0,i=0, estado=0;

	printf("¿Cuantos procesos hijos quiere? ");
	scanf ("%d", &procesos);


	for (i=0;i<procesos;i++)
	{
		pid=fork();
		if(pid==-1)
		{
			printf("Fallo en el fork");
			exit(EXIT_FAILURE);
		}


		else if (pid==0)
		{
			procesohijo(i);
		}

		else
		{
			sleep(1);

			printf("Yo soy el padre con ID: %d y mi hijo es %d\n", getpid(),getppid());

			while((pid=wait(&estado))>0)
			{
				pid=wait(&estado);
			}

			if(WIFEXITED(estado)!=0)
			{
				printf("Padre: Mi hijo %d ha muerto. Devuelve %d\n", i, WEXITSTATUS(estado));
			}
			else
			{
				printf("Padre: Mi hijo %d sigue vivo. Devuelve %d\n", i, WEXITSTATUS(estado));
			}

		}



	}



	return 0;
}

void procesohijo(int i)
{
	printf("Yo soy el proceso %d, mi padre es %d y mi ID es: %d\n", i,getppid(),getpid());
	sleep(10*i);
	exit(0);
}
