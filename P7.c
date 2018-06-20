//Ewerton Henrique Costa Calmon
//11711EEL016
#include <stdio.h>


int A(int k, int l)
{
	if(k == 0)
		return l + 1;
	
	if( k > 0 && l == 0)
		return A(k - 1, 1);
		
	if(k > 0 && l > 0)
		return A(k - 1, A(k, l - 1));
	
}

int main()
{
	int k, l;
	
	printf(" Funcao de Ackermann \n");
	printf("Entre com dois valores 'k' e 'l' respectivamente:");
	scanf("%d %d", &k,&l);
	getchar();
	
	printf("\t%d",A(k,l));

    return 0;
}
