#include <stdio.h>

void codifica ()
{
	char str[256]={'\0'};
	int *ps, i=0;
	
	printf("\nDigite uma mensagem: ");
	scanf("%[^\n]",str);
	char *pmsg=str;
	printf("Codificada: ");
	for(i=0;str[i];i++)
	{
		ps=(int *)pmsg;
		if(ps[i]!=0)
			printf("%d",ps[i]);
		if(ps[i+1]!=0)
			printf(", ");
}
}
void descodifica ()
{

	char *q,i;
	int vet[64];
	printf("Digite os numeros para  descodificao: \n");
	for(i=0; i < 64 ; i++)
	{
		scanf("%d",&vet[i]);
		getchar();
		char *q = (char *) vet;
		if(vet[i]==0)
		{
			break;
		}
		printf("Decodificado e: %s",q);
	}
	
	 
}
int main()
{
	int k,saida=0;
	printf("Digite 1 codificar  ou 2 descodificar: ");
	scanf("%d",&k);
	do
	{
	switch (k)
		{
		case 1:
			{
				codifica();
				break;
			}
		case 2:
			{
				descodifica ();
				break;
			}
		}
	}while(saida !=3);
	return 0;
}
