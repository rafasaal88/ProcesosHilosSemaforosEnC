#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>


int main(int argc, char *argv[])
{
	if(argc < 3)
	{
		printf("Numero de argumentos invalidos...\n");
		exit(-1);
	}
	int i=0;
	pid_t pid;
	int estado;

	for(i=1;i<argc;i++)
	{
		pid=fork();

		if(pid==-1)
		{
			printf("Error en el fork\n");
			printf("Error: %d\n", errno);
			exit(-1);
		}

		else if(pid==0)
		{
			printf("Soy el hijo%d\n",i);
			execlp("./factorial","./factorial",argv[i],NULL);

			exit(EXIT_SUCCESS);
		}

		else
		{
			sleep(1);

			while((pid=wait(&estado))>0)
			{
				pid=wait(&estado);
			}

		}














	}


return 0;
}