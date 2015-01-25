#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>


int main(int argc, char *argv[])
{
	if (argc<3)
	{
		printf("Error en los argumentos...");
		exit(-1);
	}

	pid_t pid;
	int segundos=atoi(argv[1]);
	int salida=atoi(argv[2]);
	int estado=0;
	pid=fork();



	if(pid==-1)
	{
		printf("Error en el fork...\n");
		printf("Error: %d",errno);
		exit(-1);
	}

	else if(pid==0)
	{
		printf("Soy el hijo...\n");
		sleep(segundos);
		exit(salida);
	}

	else if(pid>0)
	{
		while((pid=wait(&estado))>0);

		if(WIFEXITED(estado))
		{
			printf("El hijo ha salido %d\n",WEXITSTATUS(estado));
		}
		else if(WIFSTOPPED(estado))
		{
			printf("El hijo se ha parado %d",WSTOPSIG(estado));
		}
		else if(WIFSIGNALED(estado))
		{
			printf("El hijo ha sido asesinado %d",WTERMSIG(estado));
		}



		pid=wait(NULL);

	}

return 0;
}