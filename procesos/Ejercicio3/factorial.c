#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
	
	if(argc < 2)
	{
		printf("Argumentos invalidos.\n");
		exit(-1);
	}
	else
	{
	int i=0;
	int numero=atoi(argv[1]);
	int aux=1;

		for(i=1;i<=numero;i++)
		{
			aux=aux*i;
		}
	
	printf("El factorial de %d es %d\n",numero, aux);
	}
	return 0;
}