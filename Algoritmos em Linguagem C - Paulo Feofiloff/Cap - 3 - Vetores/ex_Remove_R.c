#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10

/*  A função recebe um vetor e o indice do elemento que pretente 'remover'
    Através de ponteiros, manipula o vetor - Função feita de forma recursiva */
void RemoveR(int *ptr, int k, int i);


int main()
{
    int vetor[TAM], n, i;

    srand(time(NULL));

    printf("Escolha o indice a ser retirado da funcao (indice de 1 a 10): ");
    scanf("%d", &n);
    
    printf("Vetor atual: {");
    for(i = 0; i < TAM; i++) 
    {
        vetor[i] = rand() % 100;
        printf(" %d ", vetor[i]);
    }
    printf("}\n");

    RemoveR(&vetor[0], n-1, TAM-1);

    printf("Novo vetor: {");
    for(i = 0; i < TAM && vetor[i] != -1; i++) printf(" %d ", vetor[i]);
    printf("}\n");

    return 0;
}


void RemoveR(int *ptr, int k, int i)
{
    if(k == i) *(ptr + k) = -1;

    else{
        *(ptr + k) = *(ptr + k + 1);
        RemoveR(ptr, k + 1, i);
    }
}