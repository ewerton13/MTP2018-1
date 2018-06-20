//Ewerton Henrique Costa 
//11711EEL016
#include <stdio.h>
int decimal1;
int decimal2;
int binario1[32] = {0};
int binario2[32] = {0};
int resultado[32] = {0};
int nb;
int arrastar;

void dec2bin1(int decimal)
{
	int i, resultado = 0;
    
    resultado=decimal;
    if(decimal<0)
    {
	    resultado=-resultado;
	    
		for(i=0;resultado!=0;i++)
		{
	        binario1[i]=resultado%2;
	        resultado=(resultado - binario1[i])/2;
	    }
	    
	    for(i=0;i<32;i++)
	    	binario1[i]=!binario1[i];
    	
    	for(i=31;i!=0;i--)
    	{
    		if(binario1[i]==0)
    		{
    			binario1[i]=1;
    			break;
			}
			else
			binario1[i]=0;
		}
		
		for(i=0;i<32;i++)
	    	binario1[i]=!binario1[i];
	}
	if(decimal>=0)
	{
		for(i=0;resultado!=0;i++)
		{
	        binario1[i]=resultado%2;
	        resultado=(resultado - binario1[i])/2;
	    }
	}
}

void dec2bin2(int decimal)
{
	int i, resultado = 0;
    
    resultado=decimal;
    if(decimal<0)
    {
	    resultado=-resultado;
	    
		for(i=0;resultado!=0;i++)
		{
	        binario2[i]=resultado%2;
	        resultado=(resultado - binario2[i])/2;
	    }
	    
	    for(i=0;i<32;i++)
	    	binario2[i]=!binario2[i];
    	
    	for(i=31;i!=0;i--)
    	{
    		if(binario2[i]==0)
    		{
    			binario2[i]=1;
    			break;
			}
			else
			binario2[i]=0;
		}
		
		for(i=0;i<32;i++)
	    	binario2[i]=!binario2[i];
	}
	if(decimal>=0)
	{
		for(i=0;resultado!=0;i++)
		{
	        binario2[i]=resultado%2;
	        resultado=(resultado - binario2[i])/2;
	    }
	}
}

void NOT()
{
	int i = 0, aux=0;
	
	printf("NOT %d (", decimal1);
	for(i = 31; i >= 0; i--)
		printf("%d", binario1[i]);
	
	printf(") : ");
	
	for(i = 0; i < 32; i++)
	{
		if(binario1[i] == 1)
			binario1[i]= 0;
		else
			binario1[i] = 1;
	}

	printf("%d (",~decimal1);

	for(i = 31; i >= 0; i--)
		printf("%d", binario1[i]);
		
	printf(")");
}

void AND()
{
	int i = 0, aux = 0;
	
	printf("%d (", decimal1);
	for(i = 31; i >= 0; i--)
		printf("%d", binario1[i]);
		
	printf(") AND ");
	printf("%d (", decimal2);
	
	for(i = 31; i >= 0; i--)
		printf("%d", binario2[i]);
		
	printf(") : ");
	
	for(i = 0; i < 32; i++)
	{
		if(binario1[i] == 1 && binario2[i] == 1)
			resultado[i] = 1;
		else 
			resultado[i] = 0;
	}
	
	printf("%d (",decimal1&decimal2);
	
	for(i = 31; i >= 0; i--)
		printf("%d", resultado[i]);
	
	printf(")");
}

void OR()
{
	int i = 0, aux = 0;
	
	printf("%d (", decimal1);
	
	for(i = 31; i >= 0; i--)
		printf("%d", binario1[i]);
			
	printf(") OR ");
	printf("%d (", decimal2);
	
	for(i = 31; i >= 0; i--)
		printf("%d", binario2[i]);
	
	printf(") : ");
	
	for(i = 0; i < 32; i++)
	{
		if(binario1[i] == 0 && binario2[i] == 0)
			resultado[i] = 0;
		else 
			resultado[i] = 1;
	}

	printf("%d (",decimal1|decimal2);
	
	for(i = 31; i >= 0; i--)
		printf("%d", resultado[i]);
	
	printf(")");
}

void XOR()
{
	int i = 0, aux = 0;
	
	printf("%d (", decimal1);
	for(i = 31; i >= 0; i--)
		printf("%d", binario1[i]);
	
	printf(") XOR ");
	printf("%d (", decimal2);
	
	for(i = 31; i >= 0; i--)
		printf("%d", binario2[i]);
	
	printf(") : ");
	
	for(i = 0; i < 32; i++)
	{
		if(binario1[i] == binario2[i])
			resultado[i] = 0;
		else 
			resultado[i] = 1;
	}
	
	printf("%d (",decimal1^decimal2);
	
	for(i = 31; i >= 0; i--)
		printf("%d", resultado[i]);
	
	printf(")");	
}

void RIGHTSHIFT(int arrastar)
{
	int i = 0, j = 0, aux = 0;
	
	printf("%d (", decimal1);
	
	for(i = 31; i >= 0; i--)
		printf("%d", binario1[i]);
			
	printf(") >> ");
	printf("%d (", arrastar);
	
	for(i = 31; i >= 0; i--)
		printf("%d", binario2[i]);
	
	printf(") : ");
	
	for(i = 0; i < arrastar; i++)
		resultado[i] = 0;
		
	for(i = arrastar; i < 32; i++)
	{
		resultado[i] = binario1[j];
		j++;
	}
	
	printf("%d (",decimal1>>arrastar);
	
	for(i = 31; i >= 0; i--)
		printf("%d", resultado[i]);
	
	printf(")");
}

void LEFTSHIFT(int arrastar)
{
	int i = 0, j = 0, aux = 0;
	
	printf("%d (", decimal1);
	for(i = 31; i >= 0; i--)
		printf("%d", binario1[i]);
	
	printf(") << ");
	printf("%d (", arrastar);
	for(i = 31; i >= 0; i--)
		printf("%d", binario2[i]);
	
	printf(") : ");
	
	for(i = arrastar; i < 32; i++)
	{
		resultado[i] = binario1[j];
		j++;
	}
	
	for(; j < 32; j++)
		resultado[j] = 0;
	
	printf("%d (",decimal1<<arrastar);
	
	for(i = 31; i >= 0; i--)
		printf("%d", resultado[i]);
	
	printf(")");
}

void menu( )
{
	int k,i,saida;
    printf("\t1. Digite 1 para NOT\n");
    printf("\t2. Digite 2 para AND\n");
    printf("\t3. Digite 3 para OR\n");
    printf("\t4. Digite 4 para  XOR\n");
    printf("\t5. Digite 5 para RIGHT SHIFT\n");
    printf("\t6. Digite 6 para LEFT SHIFT\n");
    printf("\t7. Digite 7 para Sair\n");
    
	do
	{
		inicio:
		printf ("\nDigite sua opcao: ");
		scanf("%d",&k);
		switch(k)
		{
			case 1:
				printf("Digite um numero decimal: ");
				scanf("%d", &decimal1);
				getchar();
				dec2bin1(decimal1);
				NOT();
				saida=1;
				break;
			
			case 2:	
				printf("Digite o primeiro numero decimal: ");
				scanf("%d", &decimal1);
				getchar();
				dec2bin1(decimal1);
				printf("Digite o segundo numero decimal: ");
				scanf("%d", &decimal2);
				getchar();
				dec2bin2(decimal2);
				AND();
				saida=1;
				break;
			
			case 3:
				printf("Digite o primeiro numero decimal: ");
				scanf("%d", &decimal1);
				getchar();
				dec2bin1(decimal1);
				printf("Digite o segundo numero decimal: ");
				scanf("%d", &decimal2);
				getchar();
				dec2bin2(decimal2);
				OR();
				saida=1;
				break;
			
			case 4:
				printf("Digite o primeiro numero decimal: ");
				scanf("%d", &decimal1);
				getchar();
				dec2bin1(decimal1);
				printf("Digite o segundo numero decimal: ");
				scanf("%d", &decimal2);
				getchar();
				dec2bin2(decimal2);
				XOR();
				saida=1;
				break;
		
			case 5:
				printf("Digite o primeiro numero decimal: ");
				scanf("%d", &decimal1);
				getchar();
				dec2bin1(decimal1);
				printf("Digite quantos bits para direita: ");
				scanf("%d", &arrastar);
				getchar();
				dec2bin2(arrastar);
				RIGHTSHIFT(arrastar);
				saida=1;
				break;
		
			case 6:
				printf("Digite o primeiro numero decimal: ");
				scanf("%d", &decimal1);
				getchar();
				dec2bin1(decimal1);
				printf("Digite quantos bits para esquerda: ");
				scanf("%d", &arrastar);
				getchar();
				dec2bin2(arrastar);
				LEFTSHIFT(arrastar);
				saida=1;
				break;
		
			case 7:
				saida = 0;
				break;		
	}
	}while(saida!=0);
}

int main()
{
	menu();
	return 0;
}
