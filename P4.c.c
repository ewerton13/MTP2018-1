#include <stdio.h>


int main()
{
	int i=0,j=0;
	char str1[256],str[256]={48};
	printf("Digite a frase desejada:       ");
	scanf("%s",&str1);
	while (str1[i] != '\0')
	{
		if (str1[i] >= '0' )	
		{
			if(str1[i] <= '9')
		{
			str[j]=str1[i];
			j++;
		}
		i++;
		}
	}
	printf("%s",str);
	return 0;
}
