#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>

int main()
{
	pid_t pid;

	pid=fork();

	if(pid==-1)
	{
		printf("Error en el fork\n");
		printf("Error: %d",errno);
		exit(-1);
	}

	else if(pid==0)
	{
		printf("Soy el hijo con pid: %d\n", getpid());
		exit(0);
	}

	else if(pid > 0)
	{
		printf("Soy el padre y voy a dormir durante 30 segundos....");
		sleep(30);
		exit(EXIT_SUCCESS);
	}
















	return 0;
}