#include <stdio.h>
#include <stdlib.h>

void gera_numeros(float * vetor, int tam);
void imprime_numeros(float * vetor);
float soma(float * inicio_vetor, float * fim_vetor, float (*funcao)(float, float));
float soma_(float a, float b);
float produto(float * inicio_vetor, float * fim_vetor, float (*funcao)(float, float));
float produto_(float a, float b);

int main (void){
    srand(123456);
    int opc;
    float vetor[100];
    float resultado_soma = 0, resultado_produto = 0;

    //gera numeros aleatórios e os imprime
    gera_numeros(vetor,100);
    //imprime_numeros(vetor);

    while(opc!=3){
        printf("\n---------- MENU -----------\n");
        printf("1- Somatorio\n");
        printf("2- Produtorio\n");
        printf("3- Encerrar\n");
        printf("\nEscolha sua opc: ");
        scanf("%d",&opc);
        getchar();
        system("cls");

        switch(opc){
        case 1:
            resultado_soma = soma(vetor, vetor+100, soma_);
            printf("\nSoma do vetor: %f\n", resultado_soma);
            break;
        case 2:
            resultado_produto = produto(vetor, vetor+100, produto_);
            printf("\nProduto do vetor: %f\n", resultado_produto);
            break;
        case 3:
            exit(1);
            break;
        }

    }

    return 0;
}

void gera_numeros(float * vetor, int tam){
    int i;
    for(i = 0; i < tam; i++){
        vetor[i] = (float) rand()/(float) RAND_MAX + 0.5f;
    }
}

void imprime_numeros(float * vetor){
    int i;
    for (i = 0; i < 100; i++){
           printf("%f \n", vetor[i]);
     }
}

float soma(float * inicio_vetor, float * fim_vetor, float (*funcao)(float, float)) {
    return (inicio_vetor == fim_vetor)? 0 : (*funcao)(*inicio_vetor, soma(inicio_vetor+1, fim_vetor, funcao));
}

float soma_(float a, float b) {
    return a+b;
}

float produto(float * inicio_vetor, float * fim_vetor, float (*funcao)(float, float)) {
    return (inicio_vetor == fim_vetor)? 1 : (*funcao)(*inicio_vetor, produto(inicio_vetor+1, fim_vetor, funcao));
}

float produto_(float a, float b) {
    return a*b;
}
