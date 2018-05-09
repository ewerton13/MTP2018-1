//Ewerton Henrique Costa Calmon
//11711EEL016
#include <stdio.h>
int decimal1;
int decimal2;
int binario1[32];
int binario2[32];
int resultado[32];
int nb;
int *vet;
int aux;

void dec2bin1(int decimal)
{
	aux=decimal;
	for(nb = 0; decimal >= (1 << nb); nb++);
	for(;nb!=0;nb--)
	{
		binario1[nb]=decimal%2;
		if(binario1[nb]==1)
			decimal = decimal/2;
	}
}
void dec2bin2(int decimal2)
{
	scanf("%d", &decimal2);
	getchar();
	aux=decimal2;
	for(nb = 0; decimal2 >= (1 << nb); nb++);
	for(;nb!=0;nb--)
	{
		binario2[nb]=decimal2%2;
		decimal2 = decimal2/2;
	}
}

void NOT()
{
	int i = 0;
	for(i = 0; i < 32; i++)
	{
		if(binario1[i] == 1)
			binario1[i]= 0;
		else
			binario1[i] = 1;
	}	
}

void AND()
{
	int i = 0;
	for(i = 0; i < 32; i++)
	{
		if(binario1[i] == 1 && binario2[i] == 1)
			resultado[i] = 1;
		else 
			resultado[i] = 0;
	}
}

void OR()
{
	int i = 0;
	for(i = 0; i < 32; i++)
	{
		if(binario1[i] == 0 && binario2[i] == 0)
			resultado[i] = 0;
		else 
			resultado[i] = 1;
	}	
}

void XOR()
{
	int i = 0;
	for(i = 0; i < 32; i++)
	{
		if(binario1[i] == binario2[i])
			resultado[i] = 0;
		else 
			resultado[i] = 1;
	}	
}

void RT()
{
	int i = 0, j = 0,arrastar;
	printf("digite o valor desejado para arrastar");
	scanf("%d",&arrastar);
	for(i = 0; i < arrastar; i++)
		resultado[i] = 0;
	for(i = arrastar; i < 32; i++)
	{
		resultado[i] = binario1[j];
		j++;
	}	
}

void LT()
{
	
	int i = 0,j = 0,arrastar;
	printf("digite o valor desejado para arrastar");
	scanf("%d",&arrastar);
	for(i = arrastar; i < 32; i++)
	{
		resultado[i] = binario1[j];
		j++;
	}
	for(; j < 32; j++)
		resultado[j] = 0;	
}

int main()
{
	int n,i;
	printf("MENU, digite um para NOT,2para AND,3 para OR,4 para XOR, 5 para RIGHTSHIFT, 6 para LEFTSHIFT \n\n");
	scanf("%d",&n);
	switch(n)
	{
		{
			case 1:
			scanf("%d", &decimal1);
			getchar();
			dec2bin1(decimal1);
			NOT();
			printf("NOT %d (", decimal1);
			for(i = 31; i >= 0; i--)
			{
				printf("%d", binario1[i]);
			}
			printf(")\n");
			break;
		}
		case 2:
		{
			AND();
			printf("Digite o valor do primeiro decimal");
			scanf("%d",&decimal1);
			getchar();
			printf("Digite o valor do segundo decimal");
			scanf("%d",decimal2);
			getchar();
				printf("AND %d (", decimal1);
			for(i = 31; i >= 0; i--)
			{
				printf("%d", binario1[i]);
			}
			printf(")\n");
			break;
		}	
		case 3:
		{
			OR();
			printf("Digite o valor do primeiro decimal");
			scanf("%d",&decimal1);
			getchar();
			printf("Digite o valor do segundo decimal");
			scanf("%d",decimal2);
			getchar();
			break;
		}
		case 4:
		{
			XOR();
			printf("Digite o valor do primeiro decimal");
			scanf("%d",&decimal1);
			getchar();
			printf("Digite o valor do segundo decimal");
			scanf("%d",decimal2);
			getchar();
			break;
		}
		case 5:
		{
			RT();
			dec2bin1(decimal1);
			printf("Digite o valor do primeiro decimal");
			scanf("%d",&decimal1);
			getchar();
			printf("RIGHTSHIFT %d (", decimal1);
			for(i = 31; i >= 0; i--)
			{
				printf("%d", binario1[i]);
			}
			printf(")\n");
			break;
		}
		case 6:
		{
			LT();
			dec2bin1(decimal1);
			printf("Digite o valor do primeiro decimal");
			scanf("%d",&decimal1);
			getchar();
			printf("LEFTHSHIFT %d (", decimal1);
			for(i = 31; i >= 0; i--)
			{
				printf("%d", binario1[i]);
			}
			printf(")\n");
			break;	
		}
	}
}
