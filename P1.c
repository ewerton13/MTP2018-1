//Ewerton Henrique Costa Calmon
//11711EEL016
#include <stdio.h>
#define m 10000
int main()
{
	int estado=0,i=0;
	char bin[m];
	printf("Digite o valor do binario:   ");
	getchar();
	gets(bin);
	while(bin[i] != '\0')
	{
		if(bin[i] == '1' || bin[i] == '0')
		{
			if(estado == 0)
			{
				if(bin[i] == '0')
				{
					estado = 0;
				}
				else
				estado = 1;
			}
			else
			{
				if(estado == 1)
				{
					if(bin[i] == '0')
					estado = 2;
					else
					estado = 0;
				}
				else
				if(estado == 2)
				{
					if(bin[i] == '0')
					estado = 1;
					else
					estado = 2;
				}
			}
			i++;
		}
		else
		{
			printf("O numero nao e valido");
			return 0;
		}
		
	}
	if(estado == 0)
	printf("o valor e multiplo de 3:  %s",bin);
	else 
	printf("ele nao e um multiplo de 3");
	return 0;
}
