#include <stdio.h>
#include <string.h>
#define ESTOQUE_MAX 100

int n=0;
struct Dimensoes

{
	float largura;
	float profundidade;
	float altura;
};
struct Produto
{
	char nome [63];
	float preco;
	float dimensoes;
	struct Dimensoes end;	
};

struct Produto produtos[ESTOQUE_MAX];

void preencher (void)
{
	int i;
	printf("Digite quantos produtos deseja cadastrar:   \n");
	scanf("%d",&n);
	for( i = 0;  i < n ; i++ )
	{
		printf("Nome:         \n");
		scanf("%s", produtos[i].nome);
		getchar();
		printf("Preco:        \n");
		scanf("%f",&produtos[i].preco);
		getchar();
		printf("Dimensoes:    \n");
		scanf("%f",&produtos[i].dimensoes);
		getchar();
		printf("largura:      \n");
		scanf("%f",&produtos[i].end.largura);
		getchar();
		printf("Profundidade: \n");
		scanf("%f",&produtos[i].end.profundidade);
		getchar();
		printf("Altura:       \n");
		scanf("%f", &produtos[i].end.altura);
		getchar();
		printf("--------------------------------------------------------");
	}
}

void mostrar(int n)
{
	int i;
	for (i = 0 ; i < n ; i++)
	{
		printf("\n\n");
		printf("Nome e: %s\n", produtos[i].nome);
		printf("Preco e: %f\n", produtos[i].preco);
		printf("Dimensoes e: %f\n", produtos[i].dimensoes);
		printf("Largura e: %f\n", produtos[i].end.largura);
		printf("Profundidade e:%f\n", produtos[i].end.profundidade);
		printf("Altura e:%f\n", produtos[i].end.altura);
		printf("--------------------------------------------------------");
	}
}

void buscar()
{
	int i=0, j=0;
	char str[63];
	
	printf("\nDigite o nome do produto que deseja buscar:  ");
	getchar ();
	scanf("%[^\n]",str);
	printf ("\n");
		
	while(1)
	{
		if (i == n)
		{
			printf ("\nProduto nao cadastrado.\n\n");
			printf("--------------------------------------------------------");
			break;		
		}
		if(strcmp(str,produtos[i].nome)!=0)
		{
			i++;
		}
	
		if (strcmp(str, produtos[i].nome) == 0)
		{
				printf("Nome e: %s\n", produtos[i].nome);
				printf("Preco e: %f\n", produtos[i].preco);
				printf("Dimensoes e: %f\n", produtos[i].dimensoes);
				printf("Largura e: %f\n", produtos[i].end.largura);
				printf("Profundidade e:%f\n", produtos[i].end.profundidade);
				printf("Altura e:%f\n", produtos[i].end.altura);
				printf("--------------------------------------------------------");
				printf("\n\n\n");
				break;
		}
	}
}

int main()
{
	int a=0;
	struct Produto produtos;
	
	do
	{
	printf("\n");
	printf("\n\t [1] - Para cadastrar:     \n");
	printf("\t [2] - Mostar os produtos: \n");
	printf("\t [3] - Buscar o produto:   \n");
	printf("\t [4] - Sair do programa:   \n");
	printf("--------------------------------------------------------\n\n");
	scanf("%d",&a);
	
		switch(a)
		{
			case 1:
				preencher();
				break;
			case 2:
				mostrar(n);
				break;
			case 3:
				buscar();
				break;
		}
	}while (a != 4);
	
	return 0;
}
