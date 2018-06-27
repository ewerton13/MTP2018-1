//Ewerton Henrique Costa Calmon
//11711EEL016
#include <stdio.h>

int vet[20],i,a;
float b;
int ler (int vet[20]) 
{
 	printf("digite o tamanho desejado do vetor:   ");
 	scanf("%i",&a);
 	if (a <= 20)
 	{
 		for (i = 0 ; i < a ; i++)
 		{
 			printf("digite os numeros dos vetores:    ");
			scanf("%i",&vet[i]);
			getchar( );	
		}
	}
	else 
		return 0;
 	}
int soma (int vet[20])
{
	int soma1=0;
	for ( i = 0 ; i < a ; i++)
	{
		soma1= soma1 + vet[i];
	}
	b= (float)soma1/(float)a;
	printf("A soma e:  %d  \n\n",soma1);
	printf("A media e: %.2f\n\n",b);
}
int main()
{
	ler(vet);
	soma(vet);
	return 0;
}
