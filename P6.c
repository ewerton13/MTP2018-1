#include <stdio.h>

int vet[20],a,i;
int ler (int vet[20]) 
{
 	printf("digite o tamanho desejado do vetor:   ");
 	scanf("%d",&a);
 	if (a <= 20)
 	{
 		for (i = 0 ; i < a ; i++)
 	{
 		printf("digite os numeros dos vetores:    ");
		scanf("%i",&vet[i]);	
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
	printf("A soma e:  %d  \n\n",soma1);
	printf("A media e: %2.f\n\n",(float)soma1/a);
}
int main()
{
	ler(vet);
	soma(vet);
	return 0;
}

