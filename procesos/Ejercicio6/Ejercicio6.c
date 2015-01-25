#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if(argc<6)
	{
		printf("Numero de argumentos invalido");
		exit(-1);
	}

	pid_t pid;

	pid=fork();

	if(pid==-1)
	{
		printf("Error en el fork");
		exit(-1);
	}

	else if(pid==0)
	{
		execlp(argv[1],argv[1],NULL,NULL);
		exit(EXIT_SUCCESS);
	}



	pid=fork();

	if(pid==-1)
	{
		printf("Error en el fork");
		exit(-1);
	}

	else if(pid==0)
	{
		execlp(argv[2],argv[2],argv[3], argv[4],argv[5],NULL);
	}



	return 0;
}